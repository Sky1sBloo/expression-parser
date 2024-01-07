cmake_minimum_required(VERSION 3.1)
project(evaluate_parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(tests)
add_library(evaluate_parser evalparser.hpp evalparser.cpp)

enable_testing()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
add_test(NAME EvalParserTests COMMAND EvalParserTests)
