file(GLOB klondike_local_logic_source_files
    "*.cc"
)

add_library(KlondikeLocalLogic SHARED ${klondike_local_logic_source_files})
target_link_libraries(KlondikeLocalLogic KlondikeLogic
                                         KlondikeLocalController)
target_include_directories(KlondikeLocalLogic PUBLIC "inc")