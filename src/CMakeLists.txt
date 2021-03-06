add_subdirectory(cards)
add_subdirectory(utils)
add_subdirectory(model)
add_subdirectory(controllers)
add_subdirectory(views)
add_subdirectory(app)
add_subdirectory(actions)
add_subdirectory(logic)
add_subdirectory(serializers_deserializers)
add_subdirectory(savers_loaders)

add_executable(Klondike KlondikeMain.cc)

target_link_libraries(Klondike KlondikeApp
                               KlondikeLocalLogic
                               KlondikePlainTextSerializerDeserializer
                               KlondikeFileSaverLoader
                               KlondikeConsoleView)

add_executable(KlondikeClient KlondikeClient.cc)

target_link_libraries(KlondikeClient KlondikeApp
                                     KlondikeRemoteLogic
                                     KlondikePlainTextSerializerDeserializer
                                     KlondikeFileSaverLoader
                                     KlondikeConsoleView)

add_executable(KlondikeTest KlondikeTestMain.cc)

target_link_libraries(KlondikeTest TestCards
                                   KlondikeApp
                                   KlondikeLocalLogic
                                   KlondikePlainTextSerializerDeserializer
                                   KlondikeFileSaverLoader
                                   KlondikeConsoleView)
