# Root CMake for AppWithCustomFont project.
cmake_minimum_required(VERSION 3.21)

project(AppWithCustomFont CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

find_package(fmt REQUIRED)

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Qml Quick)
message(STATUS "Qt6_FOUND=${Qt6_FOUND}")
message(STATUS "Qt6_DIR=${Qt6_DIR}")

# ===================================
add_subdirectory(AppWithCustomFont)
