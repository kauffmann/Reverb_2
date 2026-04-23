

cmake_minimum_required(VERSION 4.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 26)

set(LIB_DSP ${CMAKE_SOURCE_DIR}/Geraint-Luff_DSP)

# Adds a plugin target.
set(PLUGIN_NAME "Reverb")

# Our executable target
juce_add_plugin( ReverbPlugin # name of plugin target
        PRODUCT_NAME
        ${PLUGIN_NAME}
        VERSION
        0.0.0 # 0 forces AU hosts to always refresh.
        COMPANY_NAME
        "audio_head"
        PLUGIN_MANUFACTURER_CODE
        Auhe # good practice to use company name as source to make strong unique code, that differ from other companies.
        PLUGIN_CODE
        Rerb # # good practice to use plugin name as source to make strong unique code, that differ from other companies.
        FORMATS
        Standalone
        AU
        VST3
        IS_SYNTH
        FALSE
        NEEDS_MIDI_INPUT
        FALSE
        NEEDS_MIDI_OUTPUT
        FALSE
        VST3_AUTO_MANIFEST
        FALSE
        COPY_PLUGIN_AFTER_BUILD # set true to copy build plugin to system plugin dir. Se windows case above.
        True
)

# Configures the JUCE sources included in the plugin target.
target_compile_definitions(ReverbPlugin
        PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)



# important, the name reverb must match name of module created in reverb.h
# audio_head is namespace in Cmake, not in source project code - not the same
juce_add_module(reverb ALIAS_NAMESPACE audio_head)

# Additional definitions required by all users of this module.
target_compile_definitions(ReverbPlugin
        INTERFACE
        PLUGIN_NAME="${PLUGIN_NAME}"
)



# Enables strict C++ warnings, located and set in CompilerWarnings.cmake
target_compile_options(ReverbPlugin INTERFACE "${PROJECT_WARNINGS_CXX}")


target_link_libraries(ReverbPlugin PRIVATE reverb::assets)

target_link_libraries(
        ReverbPlugin
        PRIVATE
        audio_head::reverb
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)


# Make the Geraint-Luff_DSP directory visible to the compiler. I do this since it is not a library, and must be added as directory instead linked to target.
target_include_directories(ReverbPlugin PRIVATE ${LIB_DSP})


