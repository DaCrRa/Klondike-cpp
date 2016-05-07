add_subdirectory(cards)
add_subdirectory(utils)
add_subdirectory(model)
add_subdirectory(controllers)
add_subdirectory(views)

add_executable(Klondike KlondikeMain.cc)

target_link_libraries(Klondike KlondikeModel
                               KlondikeController
                               KlondikeConsoleView)
