file(GLOB klondike_console_view_source_files
    "*.cc"
)

add_library(KlondikeConsoleView SHARED ${klondike_console_view_source_files})
target_include_directories(KlondikeConsoleView PUBLIC "inc")
target_include_directories(KlondikeConsoleView PRIVATE
             $<TARGET_PROPERTY:KlondikeController,INTERFACE_INCLUDE_DIRECTORIES>
             $<TARGET_PROPERTY:KlondikeModel,INTERFACE_INCLUDE_DIRECTORIES>)