#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Mean_curvature_flow_skeletonization.h>
#include <CGAL/boost/graph/properties.h>  // For CGAL::vertex_point property map
#include <CGAL/boost/graph/graph_traits_Surface_mesh.h>  // For boost::graph_traits
// #include <CGAL/IO/read_STL.h>  // For reading STL files
#include <CGAL/IO/write_xyz_points.h>  // For writing point correspondences

#include <fstream>

typedef CGAL::Simple_cartesian<double>                        Kernel;
typedef Kernel::Point_3                                       Point;
typedef CGAL::Surface_mesh<Point>                             Triangle_mesh;
typedef boost::graph_traits<Triangle_mesh>::vertex_descriptor vertex_descriptor;
typedef CGAL::Mean_curvature_flow_skeletonization<Triangle_mesh> Skeletonization;
typedef Skeletonization::Skeleton                             Skeleton;
typedef Skeleton::vertex_descriptor                           Skeleton_vertex;
typedef Skeleton::edge_descriptor                             Skeleton_edge;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <input.stl>" << std::endl;
    return EXIT_FAILURE;
  }

  Triangle_mesh tmesh;
  std::ifstream input(argv[1]);
  input >> tmesh;

  if (!input || !CGAL::is_triangle_mesh(tmesh)) {
    std::cerr << "Error: Invalid or non-triangulated STL file." << std::endl;
    return EXIT_FAILURE;
  }

  Skeleton skeleton;
  Skeletonization mcs(tmesh);

  mcs.contract_geometry();
  mcs.collapse_edges();
  mcs.split_faces();
  mcs.detect_degeneracies();
  mcs.contract();
  mcs.contract_until_convergence();

  mcs.convert_to_skeleton(skeleton);

  std::cout << "Number of vertices of the skeleton: " << boost::num_vertices(skeleton) << "\n";
  std::cout << "Number of edges of the skeleton: " << boost::num_edges(skeleton) << "\n";

  // Output all the edges of the skeleton.
  std::ofstream output("skel-sm.polylines.txt");
  for (Skeleton_edge e : CGAL::make_range(edges(skeleton))) {
    const Point& s = skeleton[source(e, skeleton)].point;
    const Point& t = skeleton[target(e, skeleton)].point;
    output << "2 " << s << " " << t << "\n";
  }
  output.close();

  // Output skeleton points and the corresponding surface points
  output.open("correspondance-sm.polylines.txt");
  for (Skeleton_vertex v : CGAL::make_range(vertices(skeleton)))
    for (vertex_descriptor vd : skeleton[v].vertices)
      output << "2 " << skeleton[v].point << "  " << get(CGAL::vertex_point, tmesh, vd) << "\n";

  return EXIT_SUCCESS;
}

