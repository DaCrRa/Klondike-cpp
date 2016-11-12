file(GLOB test_cards_source_files
    "*.cc"
)

add_library(TestCards SHARED ${test_cards_source_files})
target_link_libraries(TestCards Cards)
target_include_directories(TestCards PUBLIC "inc")