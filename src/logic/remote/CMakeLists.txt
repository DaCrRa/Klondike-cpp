file(GLOB klondike_remote_logic_source_files
    "*.cc"
)

add_library(KlondikeRemoteLogic SHARED ${klondike_remote_logic_source_files})
target_link_libraries(KlondikeRemoteLogic KlondikeLogic
                                          KlondikeRemoteController)
target_include_directories(KlondikeRemoteLogic PUBLIC "inc")