file(GLOB klondike_local_controller_source_files
    "*.cc"
)

add_library(KlondikeLocalController SHARED ${klondike_local_controller_source_files})
target_link_libraries(KlondikeLocalController KlondikeController
                                              KlondikeModelImpl)
target_include_directories(KlondikeLocalController PUBLIC "inc")