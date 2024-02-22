cmake_minimum_required(VERSION 3.15)

find_package(VTK REQUIRED)
# include(${VTK_USE_FILE})

# Activate this property to "hide" targets (i.e. cgal) to the end user
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(box)

set(src_files  
                main.cpp )

add_executable(${PROJECT_NAME} ${src_files})

target_link_libraries(${PROJECT_NAME} PUBLIC ${VTK_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
