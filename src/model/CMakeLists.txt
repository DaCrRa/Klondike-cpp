add_subdirectory(implementation)

file(GLOB klondike_model_source_files
    "*.cc"
)

add_library(KlondikeModel SHARED ${klondike_model_source_files})
target_link_libraries(KlondikeModel Cards)
target_include_directories(KlondikeModel PUBLIC "inc")