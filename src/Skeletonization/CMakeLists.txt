cmake_minimum_required(VERSION 3.15...3.25)

## Find dependencies
find_package(CGAL CONFIG REQUIRED)
# Find and use Boost components
find_package(Boost REQUIRED COMPONENTS graph)

find_package(Eigen3 3.1.0 QUIET)
include(CGAL_Eigen3_support)

# Activate this property to "hide" targets (i.e. cgal) to the end user
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(Skeletor)

set(src_files skeleton.cpp
             )

add_executable(${PROJECT_NAME} ${src_files})

target_link_libraries(${PROJECT_NAME} PUBLIC ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} Boost::graph 
                                             CGAL::Eigen3_support)


target_include_directories(${PROJECT_NAME} PUBLIC  "${SOURCE_DIR}"
                                                  )
                                               
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
