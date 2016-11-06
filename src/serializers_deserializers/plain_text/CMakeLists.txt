file(GLOB klondike_plain_text_serializer_source_files
    "*.cc"
)

add_library(KlondikePlainTextSerializer SHARED ${klondike_plain_text_serializer_source_files})
target_link_libraries(KlondikePlainTextSerializer KlondikeSerializer KlondikeModel)
target_include_directories(KlondikePlainTextSerializer PUBLIC "inc")