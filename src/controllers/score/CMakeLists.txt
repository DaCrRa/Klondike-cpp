file(GLOB klondike_score_source_files
    "*.cc"
)

add_library(KlondikeScore SHARED ${klondike_score_source_files})
target_link_libraries(KlondikeScore KlondikeActions)
target_include_directories(KlondikeScore PUBLIC "inc")
