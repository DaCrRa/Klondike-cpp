file(GLOB app_source_files
    "*.cc"
)

add_library(KlondikeApp SHARED ${app_source_files})
target_link_libraries(KlondikeApp KlondikeConsoleView
                                  KlondikeController)
target_include_directories(KlondikeApp PUBLIC "inc")

