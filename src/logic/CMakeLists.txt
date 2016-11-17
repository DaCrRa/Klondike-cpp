file(GLOB klondike_logic_source_files
    "*.cc"
)

add_library(KlondikeLogic SHARED ${klondike_logic_source_files})
target_link_libraries(KlondikeLogic KlondikeLocalController) # TO BE DECOUPLED
target_include_directories(KlondikeLogic PUBLIC "inc")
