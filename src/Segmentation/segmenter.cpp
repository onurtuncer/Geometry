#include <CGAL/Polyhedron_3.h>
#include <CGAL/Polyhedron_items_with_id_3.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/extract_mean_curvature_flow_skeleton.h>
#include <CGAL/mesh_segmentation.h>
#include <fstream>

// #include <vtkSmartPointer.h>
// #include <vtkPolyData.h>
// #include <vtkPoints.h>
// #include <vtkCellArray.h>
// #include <vtkTriangle.h>
// #include <vtkPolyDataMapper.h>
// #include <vtkActor.h>
// #include <vtkRenderer.h>
// #include <vtkRenderWindow.h>
// #include <vtkRenderWindowInteractor.h>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkTriangle.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkProperty.h>

typedef CGAL::Simple_cartesian<double>                               Kernel;
typedef Kernel::Point_3                                              Point;
typedef CGAL::Polyhedron_3<Kernel, CGAL::Polyhedron_items_with_id_3> Polyhedron;
typedef boost::graph_traits<Polyhedron>::vertex_descriptor           vertex_descriptor;
typedef boost::graph_traits<Polyhedron>::halfedge_descriptor         halfedge_descriptor;
typedef boost::graph_traits<Polyhedron>::face_descriptor             face_descriptor;
typedef CGAL::Mean_curvature_flow_skeletonization<Polyhedron>        Skeletonization;
typedef Skeletonization::Skeleton                                    Skeleton;
typedef Skeleton::vertex_descriptor                                  Skeleton_vertex;

void visualizeMesh(const Polyhedron& polyhedron) {
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkCellArray> triangles = vtkSmartPointer<vtkCellArray>::New();

    // Add vertices to VTK points
    for (const auto& v : vertices(polyhedron)) {
        auto point = v->point();
        points->InsertNextPoint(point.x(), point.y(), point.z());
    }

    // Add faces to VTK triangles
    for (const auto& f : faces(polyhedron)) {
        vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
        auto h = f->halfedge();
        for (int i = 0; i < 3; ++i) {
            auto v = h->vertex();
            triangle->GetPointIds()->SetId(i, v->id());
            h = h->next();
        }
        triangles->InsertNextCell(triangle);
    }

    // Create a polydata object
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();

    // Add the geometry and topology to the polydata
    polyData->SetPoints(points);
    polyData->SetPolys(triangles);

    // Create a mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polyData);

    // Create an actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // Create a renderer
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);

    // Create a render window
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    // Create a render window interactor
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    // Start the visualization
    renderWindow->Render();
    renderWindowInteractor->Start();
}

void visualizeSegments(const std::vector<Polyhedron>& segments) {
    // Create a renderer
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

    // Create a named colors object
    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

    // Add each segment as a separate actor with a different color
    for (std::size_t i = 0; i < segments.size(); ++i) {
        // Convert segment to VTK format
        vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
        vtkSmartPointer<vtkCellArray> triangles = vtkSmartPointer<vtkCellArray>::New();

        // Add vertices
        for (auto vertexIterator = segments[i].vertices_begin(); vertexIterator != segments[i].vertices_end(); ++vertexIterator) {
            auto point = vertexIterator->point();
            points->InsertNextPoint(point.x(), point.y(), point.z());
        }

        // Add faces
        for (auto facetIterator = segments[i].facets_begin(); facetIterator != segments[i].facets_end(); ++facetIterator) {
            auto halfedgeHandle = facetIterator->halfedge();
            vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
            for (int j = 0; j < 3; ++j) {
                auto vertexHandle = halfedgeHandle->vertex();
                triangle->GetPointIds()->SetId(j, vertexHandle->id());
                halfedgeHandle = halfedgeHandle->next();
            }
            triangles->InsertNextCell(triangle);
        }

        vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
        polyData->SetPoints(points);
        polyData->SetPolys(triangles);

        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputData(polyData);

        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        actor->GetProperty()->SetColor(colors->GetColor3d("SegmentColor" + std::to_string(i)).GetData());

        renderer->AddActor(actor);
    }

    // Create a render window
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    // Create an interactor
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    // Set the interactor style to trackball camera (enables zooming with mouse wheel)
    vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    renderWindowInteractor->SetInteractorStyle(style);

    // Start the visualization
    renderWindow->Render();
    renderWindowInteractor->Start();
}

/* void writeOFF(const std::string& filename, const Polyhedron& mesh) {
    std::ofstream ofs(filename);
    ofs << "OFF" << std::endl;
    ofs << mesh.size_of_vertices() << " " << mesh.size_of_facets() << " 0" << std::endl;
    for (const auto& v : mesh.vertices()) {
        ofs << v->point() << std::endl;
    }
    for (const auto& f : mesh.facets()) {
        ofs << "3 ";
        for (auto h = f->facet_begin(); h != f->facet_end(); ++h) {
            ofs << h->vertex()->id() << " ";
        }
        ofs << std::endl;
    }
    ofs.close();
} */

// Property map associating a facet with an integer as id to an
// element in a vector stored internally
template<class ValueType>
struct Facet_with_id_pmap
    : public boost::put_get_helper<ValueType&,
             Facet_with_id_pmap<ValueType> >
{
    typedef face_descriptor key_type;
    typedef ValueType value_type;
    typedef value_type& reference;
    typedef boost::lvalue_property_map_tag category;
    Facet_with_id_pmap(
      std::vector<ValueType>& internal_vector
    ) : internal_vector(internal_vector) { }
    reference operator[](key_type key) const
    { return internal_vector[key->id()]; }
private:
    std::vector<ValueType>& internal_vector;
};
int main(int argc, char* argv[])
{
  std::ifstream input((argc>1)?argv[1]:CGAL::data_file_path("bear.off"));
  Polyhedron tmesh;
  input >> tmesh;
  if (!CGAL::is_triangle_mesh(tmesh))
  {
    std::cout << "Input geometry is not triangulated." << std::endl;
    return EXIT_FAILURE;
  }
  // extract the skeleton
  Skeleton skeleton;
  CGAL::extract_mean_curvature_flow_skeleton(tmesh, skeleton);
  // init the polyhedron simplex indices
  CGAL::set_halfedgeds_items_id(tmesh);
  //for each input vertex compute its distance to the skeleton
  std::vector<double> distances(num_vertices(tmesh));
  for(Skeleton_vertex v : CGAL::make_range(vertices(skeleton)) )
  {
    const Point& skel_pt = skeleton[v].point;
    for(vertex_descriptor mesh_v : skeleton[v].vertices)
    {
      const Point& mesh_pt = mesh_v->point();
      distances[mesh_v->id()] = std::sqrt(CGAL::squared_distance(skel_pt, mesh_pt));
    }
  }
  // create a property-map for sdf values
  std::vector<double> sdf_values( num_faces(tmesh) );
  Facet_with_id_pmap<double> sdf_property_map(sdf_values);
  // compute sdf values with skeleton
  for(face_descriptor f : faces(tmesh))
  {
    double dist = 0;
    for(halfedge_descriptor hd : halfedges_around_face(halfedge(f, tmesh), tmesh))
      dist+=distances[target(hd, tmesh)->id()];
    sdf_property_map[f] = dist / 3.;
  }
  // post-process the sdf values
  CGAL::sdf_values_postprocessing(tmesh, sdf_property_map);
  // create a property-map for segment-ids (it is an adaptor for this case)
  std::vector<std::size_t> segment_ids( num_faces(tmesh) );
  Facet_with_id_pmap<std::size_t> segment_property_map(segment_ids);
  // segment the mesh using default parameters
  std::cout << "Number of segments: "
            << CGAL::segmentation_from_sdf_values(tmesh, sdf_property_map, segment_property_map) <<"\n";

//   // Visualize the segmented mesh
//   visualizeMesh(tmesh);

     // Assuming 'segments' is a vector of segmented Polyhedron objects
    std::vector<Polyhedron> segments;

    // Visualize the segmented mesh with each segment in a different color
    visualizeSegments(segments);

  return EXIT_SUCCESS;
}