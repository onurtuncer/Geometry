cmake_minimum_required(VERSION 3.14)

set(MYNAME HighlightPickedActor)

project(${MYNAME} VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt5 REQUIRED COMPONENTS Core Quick)

set(PROJECT_SOURCES
        main.cpp
        QQuickVtkItem.cpp
        MyVtkItem.cpp
        qml.qrc)

add_executable(${MYNAME} ${PROJECT_SOURCES})
   
target_link_libraries(${MYNAME}  PRIVATE Qt5::Core 
                                         Qt5::Quick)

find_package(VTK)

if (NOT VTK_FOUND OR VTK_VERSION VERSION_LESS "9.0.0")
  message("Skipping ${MYNAME}: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()

target_link_libraries(${MYNAME} PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit( TARGETS ${MYNAME} MODULES ${VTK_LIBRARIES} )

message (STATUS "VTK_VERSION: ${VTK_VERSION}")
message (STATUS "VTK_DIR: ${VTK_DIR}")

