cmake_minimum_required(VERSION 3.0)
project(evaluate_parser)

add_library(evaluate_parser evalparser.hpp evalparser.cpp)
target_include_directories(evaluate_parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
