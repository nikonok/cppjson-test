FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(nlohmann main.cpp)

target_link_libraries(nlohmann PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(nlohmann PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
