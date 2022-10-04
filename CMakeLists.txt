cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Workshop LANGUAGES CXX VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

add_subdirectory(nlohmann)
add_subdirectory(json_struct)
