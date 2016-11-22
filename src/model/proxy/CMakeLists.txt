file(GLOB klondike_model_proxy_source_files
    "*.cc"
)

add_library(KlondikeModelProxy SHARED ${klondike_model_proxy_source_files})
target_link_libraries(KlondikeModelProxy KlondikeModel)
target_include_directories(KlondikeModelProxy PUBLIC "inc")