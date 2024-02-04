cmake_minimum_required(VERSION 3.1...3.23)
project(delaunay)

# CGAL and its components
find_package(CGAL REQUIRED)
find_package(Eigen3 3.1.0 QUIET)
include(CGAL_Eigen3_support)

if(TARGET CGAL::Eigen3_support)
  create_single_source_cgal_program("delaunay.cpp")

  foreach(
    target
    delaunay)
    target_link_libraries(${target} PUBLIC CGAL::Eigen3_support)
  endforeach()
else()
  message("NOTICE: Examples in this directory require Eigen 3.1 (or greater), and will not be compiled.")
endif()