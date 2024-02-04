# Install script for directory: /home/melina/dev/Geometry/vendor/CGAL-5.6/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/AABB_tree/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Advancing_front_surface_reconstruction/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Algebraic_foundations/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Algebraic_kernel_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Alpha_shapes_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Alpha_shapes_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Alpha_wrap_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Apollonius_graph_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Approximate_min_ellipsoid_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Arrangement_on_surface_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_LCC/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_OpenMesh/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_arrangement_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_graphcut/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_polyhedron_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_surface_mesh/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/BGL_triangulation_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Barycentric_coordinates_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Boolean_set_operations_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Box_intersection_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/CGALimageIO/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circular_kernel_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circular_kernel_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Circulator/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Classification/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Combinatorial_map/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Cone_spanners_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Convex_decomposition_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Convex_hull_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Convex_hull_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Envelope_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Filtered_kernel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Generalized_map/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Generator/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/HalfedgeDS/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Heat_method_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Hyperbolic_triangulation_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Inscribed_areas/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Interpolation/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Interval_skip_list/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Jet_fitting_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Kernel_23/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Linear_cell_complex/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Matrix_search/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Mesh_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_annulus_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_circle_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_ellipse_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_quadrilateral_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_sphere_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Min_sphere_of_spheres_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Minkowski_sum_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Modular_arithmetic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Nef_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Nef_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Nef_S2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Optimal_bounding_box/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Optimal_transportation_reconstruction_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Orthtree/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Partition_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Periodic_2_triangulation_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Periodic_3_mesh_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Periodic_3_triangulation_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Periodic_4_hyperbolic_triangulation_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Point_set_processing_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Poisson_surface_reconstruction_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygon_mesh_processing/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polygonal_surface_reconstruction/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyhedron/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polyline_simplification_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polynomial/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Polytope_distance_d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Principal_component_analysis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Profiling_tools/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Property_map/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/QP_solver/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/RangeSegmentTrees/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Rectangular_p_center_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Ridges_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/SMDS_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/STL_Extension/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Scale_space_reconstruction_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Segment_Delaunay_graph_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Segment_Delaunay_graph_Linf_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Set_movable_separability_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_detection/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Shape_regularization/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Skin_surface_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Snap_rounding_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Solver_interface/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_searching/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Spatial_sorting/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Straight_skeleton_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Stream_lines_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Stream_support/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Subdivision_method_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_approximation/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_deformation/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_parameterization/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_segmentation/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_shortest_path/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_simplification/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_skeletonization/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesh_topology/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_mesher/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Surface_sweep_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/TDS_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Tetrahedral_remeshing/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Triangulation_on_sphere_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Visibility_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Voronoi_diagram_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/examples/Weights/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/melina/dev/Geometry/vendor/CGAL-5.6/examples/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
