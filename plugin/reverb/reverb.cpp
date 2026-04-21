

#include "reverb.h"

// add namespace to ease use of juce frame work, no need for juce::     Keep for now, but seems a bit inconsistent, works in cpp but not header.
//using namespace juce;  Disabled it, not consistent

// order matters, if processor is not instantiated  before editor, as editor depend on it.


#include "src/proces_DAW_control/Parameters.cpp"

#include "src/proces_DAW_control/PluginProcessor.cpp"
#include  "src/gui/Controller Slider.cpp"
#include "src/gui/PluginEditor.cpp"