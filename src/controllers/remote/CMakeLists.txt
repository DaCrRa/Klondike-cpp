file(GLOB klondike_remote_controller_source_files
    "*.cc"
)

add_library(KlondikeRemoteController SHARED ${klondike_remote_controller_source_files})
target_link_libraries(KlondikeRemoteController KlondikeController
                                               KlondikeModelProxy)
target_include_directories(KlondikeRemoteController PUBLIC "inc")