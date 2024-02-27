cmake_minimum_required(VERSION 3.14)

# https://github.com/Daguerreo/QMLTreeView/tree/main

project(parameterEditor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Quick)

set(PROJECT_SOURCES
    main.cpp
    # ParameterModel.cpp
    tree_model.cpp
    tree_item.cpp
    json_entry.cpp
    parameter_entry.cpp
    qml.qrc
    resources.qrc)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
   
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core 
                                              Qt5::Quick 
                                              Qt5::Qml 
                                              )

# Include Qt headers for the specific target
target_include_directories(${PROJECT_NAME} PRIVATE
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Quick_INCLUDE_DIRS}
    ${Qt5Qml_INCLUDE_DIRS}
    )
