#include "reverb.h"

// add namespace to ease use of juce frame work, no need for juce::
// order matters, if processor is not instantiated  before editor, as editor depend on it.
using namespace juce;
#include "src/proces_DAW_control/Parameters.cpp"
#include "src/proces_DAW_control/PluginProcessor.cpp"
#include "src/gui/PluginEditor.cpp"