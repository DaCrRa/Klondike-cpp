file(GLOB klondike_source_files
    "*.cc"
)

include_directories(".")

add_executable(Klondike ${klondike_source_files})

