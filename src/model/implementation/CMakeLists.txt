file(GLOB klondike_model_impl_source_files
    "*.cc"
)

add_library(KlondikeModelImpl SHARED ${klondike_model_impl_source_files})
target_link_libraries(KlondikeModelImpl KlondikeModel)
target_include_directories(KlondikeModelImpl PUBLIC "inc")