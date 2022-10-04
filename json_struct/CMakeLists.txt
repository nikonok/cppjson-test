FetchContent_Declare(
    json_struct
    GIT_REPOSITORY https://github.com/jorgen/json_struct.git
)

FetchContent_MakeAvailable(json_struct)

add_executable(jsonstruct main.cpp)

target_link_libraries(jsonstruct PRIVATE json_struct)

target_include_directories(jsonstruct PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
