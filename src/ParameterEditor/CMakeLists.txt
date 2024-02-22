cmake_minimum_required(VERSION 3.5)

project(TreeViewExample LANGUAGES CXX)

# Find Qt packages
find_package(Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Qt headers
include_directories(${Qt5Core_INCLUDE_DIRS}
                    ${Qt5Quick_INCLUDE_DIRS}
                    ${Qt5QuickControls2_INCLUDE_DIRS})

# Add QML files to resource file
qt5_add_resources(QML_RCC qml.qrc)

# Create executable
add_executable(${PROJECT_NAME} main.cpp ${QML_RCC})

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::QuickControls2)