add_subdirectory(score)
add_subdirectory(local)

file(GLOB klondike_controller_source_files
    "*.cc"
)

add_library(KlondikeController SHARED ${klondike_controller_source_files})
target_link_libraries(KlondikeController KlondikeActions
                                         KlondikeScore
                                         KlondikeSaverLoader)
target_include_directories(KlondikeController PUBLIC "inc")
