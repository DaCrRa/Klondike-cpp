add_executable(BTest BTest.cc)
target_include_directories(BTest PRIVATE ${GTEST_INCLUDE_DIR})
target_link_libraries(BTest gtest)

run_tests_for_target(BTest BTest)
