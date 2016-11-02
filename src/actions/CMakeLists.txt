file(GLOB klondike_actions_source_files
    "*.cc"
)

add_library(KlondikeActions SHARED ${klondike_actions_source_files})
target_link_libraries(KlondikeActions KlondikeModel)
target_include_directories(KlondikeActions PUBLIC "inc")
