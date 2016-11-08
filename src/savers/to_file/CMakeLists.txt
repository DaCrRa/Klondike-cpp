file(GLOB klondike_to_file_saver_source_files
    "*.cc"
)

add_library(KlondikeToFileSaver SHARED ${klondike_to_file_saver_source_files})
target_link_libraries(KlondikeToFileSaver KlondikeSaver
                                          KlondikeSerializerDeserializer
                                          stdc++fs)
target_include_directories(KlondikeToFileSaver PUBLIC "inc")