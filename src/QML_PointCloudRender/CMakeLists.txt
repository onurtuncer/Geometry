cmake_minimum_required(VERSION 3.20)

set(MYNAME pointCloudRenderer)

project(${MYNAME} VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Concurrent Gui Quick Qml OpenGL)

find_package(VTK 9.3 COMPONENTS CommonCore 
                                RenderingCore 
                                GUISupportQt 
                                RenderingOpenGL2 
                                InteractionStyle
                                RenderingContextOpenGL2
                                RenderingCore
                                RenderingFreeType
                                RenderingGL2PSOpenGL2
                                RenderingQt
                                GUISupportQtQuick)

if (NOT VTK_FOUND OR VTK_VERSION VERSION_LESS "9.3.0")
  message("Skipping ${MYNAME}: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()

set(PROJECT_SOURCES
                    main.cpp
                    pointcloud.h 
                    pointcloud.cpp 
                    qml.qrc)

add_executable(${MYNAME} ${PROJECT_SOURCES})
   
target_link_libraries(${MYNAME}  PRIVATE Qt6::Core 
                                         Qt6::Concurrent
                                         Qt6::OpenGL
                                         Qt6::Qml 
                                         Qt6::Gui
                                         Qt6::Quick)

target_link_libraries(${MYNAME} PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(TARGETS ${MYNAME} MODULES ${VTK_LIBRARIES} )

message (STATUS "VTK_VERSION: ${VTK_VERSION}")
message (STATUS "VTK_DIR: ${VTK_DIR}")