file(GLOB console_user_interaction_source_files
    "*.cc"
)

add_library(ConsoleUserInteraction SHARED ${console_user_interaction_source_files})

target_include_directories(ConsoleUserInteraction PUBLIC "inc")