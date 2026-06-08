# Mandatory line, sets the minimum version of CMake that should be used with this repository.
# 3.22 is the minimum CMake version required by JUCE.
# 3.25 is required for the MSVC_DEBUG_INFORMATION_FORMAT feature to work.
# To verify your version run
# $ cmake --version


cmake_minimum_required(VERSION 4.2 FATAL_ERROR)
project(Reverb_2)

# Set the C++ standard only if this project is standalone;
# otherwise, let clients decide.
if(PROJECT_IS_TOP_LEVEL)
    if (NOT CMAKE_CXX_STANDARD)
        # Always use the newest C++ standard on green-field projects if possible.
        set(CMAKE_CXX_STANDARD 26)
    endif()

    # Links to C++ runtime statically
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    # Embeds debug information
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT Embedded CACHE STRING "" FORCE)
endif()



set(CMAKE_POLICY_DEFAULT_CMP0141        NEW      CACHE STRING "" FORCE)

# Sets the minimum deployment target
# macOS 10.11 is the minimum required by JUCE
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE STRING "" FORCE)
# Builds a binary that works on Apple Silicon (arm64) and Intel-based Macs
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "" FORCE)


# This enables UndefinedBehaviorSanitizer, and addressSanitizer or thread (not with address!), memory, heap...,   global.
# Makes build slow. Disable/enable this as needed.
#[[if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang"
        AND CMAKE_BUILD_TYPE STREQUAL "Debug")

    add_compile_options(
            -fsanitize=undefined,thread
            -fno-omit-frame-pointer
    )

    add_link_options(-fsanitize=undefined,thread)

endif()]]

#[[if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(
            -fsanitize=address
            -fno-omit-frame-pointer
            -g
    )
    add_link_options(-fsanitize=address)
endif()]]



# I like to download the dependencies to the same folder as the project.
# If you want to install them system-wide, set CPM_SOURCE_CACHE with a path to the dependencies
# either as an environment variable or pass it with -DCPM_SOURCE_CACHE=<path> when invoking cmake.
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# Downloads CPM if not already downloaded. CPM is an easy-to-use package manager nicely integrated with CMake.
include(cmake/cpm.cmake)

# This commands downloads AND configures JUCE. It sets up some variables, like JUCE_SOURCE_DIR. cpmaddpackage  creates a target, here is named JUCE
cpmaddpackage(
        NAME
        JUCE
        GIT_TAG
        8.0.13
        GITHUB_REPOSITORY
        juce-framework/JUCE
        SOURCE_DIR
        ${LIB_DIR}/juce
)

# Adds compiler warning utilities & other.
include(cmake/CompilerWarnings.cmake)
include(cmake/Util.cmake)

# Adds dsp repository.
#[[CPMAddPackage(
    NAME DSP
    GITHUB_REPOSITORY Signalsmith-Audio/dsp
    GIT_TAG main  # Specify the desired tag or branch
    VERSION 1.7.0  # Specify a version if needed
    SOURCE_DIR ${LIB_DIR}/dsp
    OPTIONS
       "SOME_OPTION OFF"  # Replace with any specific options if needed
)]]



if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Sets the Windows VST3 installation location to one
    # that doesn't require elevated permissions.
    set_directory_properties(PROPERTIES JUCE_VST3_COPY_DIR "$ENV{LOCALAPPDATA}/Programs/Common/VST3")
endif()

add_subdirectory(assets)
# Adds all the targets configured in the "plugin" folder.
add_subdirectory(plugin)


# In Visual Studio this command provides a nice grouping of source files in "filters".
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/..)


