cmake_minimum_required(VERSION 3.14)

# https://github.com/Daguerreo/QMLTreeView/tree/main

project(parameterEditor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type to Debug
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt6 REQUIRED COMPONENTS Core Qml Quick)

set(PROJECT_SOURCES
    main.cpp
    TreeModel.cpp
    TreeItem.cpp
    TableItem.cpp
    TableModel.cpp
    ParameterEntry.cpp  
    QParameterManager.cpp
    qml.qrc
    )

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
   
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core 
                                              Qt6::Quick 
                                              Qt6::Qml 
                                              )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Quick_INCLUDE_DIRS}
    ${Qt6Qml_INCLUDE_DIRS}
    )