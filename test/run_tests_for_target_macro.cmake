set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

macro(run_tests_for_target target_to_test test_executable)
   add_test(NAME ${target_to_test}Test COMMAND ${test_executable})

   add_custom_command(TARGET ${target_to_test} POST_BUILD
                      COMMAND ${CMAKE_COMMAND}
                              -DTEST=${test_executable}
                              -DTARGET=$<TARGET_FILE:${target_to_test}>
                              -P ${TEST_DIR}/test_runner.cmake
   )
endmacro()

