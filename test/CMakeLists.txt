include(googletest.cmake)

add_executable(ATest ATest.cc)
target_include_directories(ATest PRIVATE ${GTEST_INCLUDE_DIR})
target_link_libraries(ATest gtest)

add_test(NAME ATestTest COMMAND ATest)

add_custom_command(TARGET ATest POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                           -DTEST=ATest
                           -DTARGET=$<TARGET_FILE:ATest>
                           -P ${CMAKE_CURRENT_SOURCE_DIR}/test_runner.cmake
)
