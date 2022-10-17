find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

set(PROTO_FILES Message.proto)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_custom_command(
    OUTPUT Message.json
    COMMAND protoc --jsonschema_out=${CMAKE_CURRENT_BINARY_DIR} ${PROTO_FILES}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Message.proto
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Compiling json schema"
    VERBATIM)

add_custom_target(json_schema ALL DEPENDS Message.json)

add_library(lib_proto STATIC)
target_sources(lib_proto
    PUBLIC
        ${PROTO_SRCS}
        ${PROTO_HDRS}
)
target_include_directories(lib_proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${Protobuf_INCLUDE_DIRS})
target_link_libraries(lib_proto PUBLIC ${Protobuf_LIBRARIES})

add_executable(main main.cpp)
target_link_libraries(main PUBLIC lib_proto)
