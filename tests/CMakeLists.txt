find_package(GTest REQUIRED)
add_executable(EvalParserTests gtest_main.cpp)
target_link_libraries(EvalParserTests PRIVATE ${GTEST_BOTH_LIBRARIES} gtest_main evaluate_parser)

include(GoogleTest)
gtest_discover_tests(EvalParserTests)
