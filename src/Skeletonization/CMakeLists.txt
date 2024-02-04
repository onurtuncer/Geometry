cmake_minimum_required(VERSION 3.15...3.25)

## Find dependencies
find_package(CGAL CONFIG REQUIRED)
# Find and use Boost components
find_package(Boost REQUIRED COMPONENTS graph)


# Activate this property to "hide" targets (i.e. cgal) to the end user
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(Skeletor)

set(src_files skeleton.cpp
             )

add_executable(${PROJECT_NAME} ${src_files})

# Test the operating system
if(UNIX AND NOT APPLE)
    target_compile_definitions(${PROJECT_NAME} PUBLIC OS_PLATFORM_LINUX)
elseif(WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC OS_PLATFORM_WINDOWS)
endif()

# if(LINUX)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE Boost::graph CGAL::CGAL)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE  Boost::graph CGAL::CGAL)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC  "${SOURCE_DIR}"
                                                  )
                                               
# Set compiler options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()