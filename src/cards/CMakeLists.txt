file(GLOB cards_source_files
    "*.cc"
)

add_library(Cards SHARED ${cards_source_files})
target_include_directories(Cards PUBLIC "inc")