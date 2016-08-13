add_subdirectory(score)

file(GLOB klondike_controller_source_files
    "*.cc"
)

add_library(KlondikeController SHARED ${klondike_controller_source_files})
target_link_libraries(KlondikeController KlondikeModel KlondikeScore)
target_include_directories(KlondikeController PUBLIC "inc")