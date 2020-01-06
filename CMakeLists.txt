cmake_minimum_required(VERSION 2.8.12)
project(asio_study)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(asio_client src/client/asio_client.cpp)
target_link_libraries(asio_client ${CONAN_LIBS})

add_executable(asio_server src/server/asio_server.cpp)
target_link_libraries(asio_server ${CONAN_LIBS})