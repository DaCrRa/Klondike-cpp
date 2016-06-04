add_executable(ATest ATest.cc)
target_include_directories(ATest PRIVATE ${GTEST_INCLUDE_DIR})
target_link_libraries(ATest gtest)

run_tests_for_target(ATest ATest)
