cmake_minimum_required(VERSION 3.25)

project(NewStartupBackend VERSION 0.0.1 DESCRIPTION "backend project in C++" LANGUAGES CXX C)

set(ASIO_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/asio/asio/include)

add_subdirectory(external/crow)
add_subdirectory(app)
