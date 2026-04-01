# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 4.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 26)

set(LIB_DSP ${CMAKE_SOURCE_DIR}/Geraint-Luff_DSP)

# Adds a plugin target.
set(PLUGIN_NAME "Reverb")

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

#[[juce_add_binary_data(tremolo_plugin_assets
        HEADER_NAME
        "TremoloPluginAssets.h"
        NAMESPACE
        tremolo::assets
        SOURCES
        assets/Background.png
        assets/Logo.png
        assets/Inter-Bold.ttf
        assets/Inter-Medium.ttf
)]]

#add_library(tremolo::tremolo_plugin_assets ALIAS tremolo_plugin_assets)

# important, the name reverb must match name of module created in reverb.h
juce_add_module(reverb ALIAS_NAMESPACE audio_head)

# Additional definitions required by all users of this module.
target_compile_definitions(ReverbPlugin
        INTERFACE
        PLUGIN_NAME="${PLUGIN_NAME}"
)

# Enables strict C++ warnings.
target_compile_options(ReverbPlugin INTERFACE "${PROJECT_WARNINGS_CXX}")

#target_link_libraries(tremolo_plugin INTERFACE tremolo::tremolo_plugin_assets)

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


# Zip the .vst3 bundle with the README.txt file
#[[get_target_property(VST3_BUNDLE_PATH ReverbPlugin_VST3 JUCE_PLUGIN_ARTEFACT_FILE)
cmake_path(GET VST3_BUNDLE_PATH PARENT_PATH VST3_BUNDLE_OUTPUT_DIR)
add_custom_command(
        TARGET ReverbPlugin_VST3
        POST_BUILD
        WORKING_DIRECTORY ${VST3_BUNDLE_OUTPUT_DIR}
        # For some reason, if the README.txt is in a different directory, zipping it fails, thus, we need to copy it first
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/assets/README.txt" ${VST3_BUNDLE_OUTPUT_DIR}
        COMMAND ${CMAKE_COMMAND} -E tar cvf "${VST3_BUNDLE_OUTPUT_DIR}/Tremolo.zip" --format=zip -- "${VST3_BUNDLE_PATH}" README.txt
)]]



#[[
option(BUILD_EXAMPLES "When on, the supplied example apps will be added as targets and built" OFF)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

option(BUILD_TESTS "When on, will download the GoogleTest framework and add the automated tests project" OFF)
if(BUILD_TESTS)
    # This command allows running tests from the "build" folder (the one where CMake generates the project to).
    enable_testing()

    # Adds all the targets configured in the "test" folder.
    add_subdirectory(test)
endif()]]
