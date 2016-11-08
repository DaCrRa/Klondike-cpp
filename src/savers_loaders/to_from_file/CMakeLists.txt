file(GLOB klondike_file_saver_loader_source_files
    "*.cc"
)

add_library(KlondikeFileSaverLoader SHARED ${klondike_file_saver_loader_source_files})
target_link_libraries(KlondikeFileSaverLoader KlondikeSaverLoader
                                          KlondikeSerializerDeserializer
                                          stdc++fs)
target_include_directories(KlondikeFileSaverLoader PUBLIC "inc")