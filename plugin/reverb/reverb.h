/*
==============================================================================

BEGIN_JUCE_MODULE_DECLARATION

   ID:            reverb
   vendor:        Michael Kauffmann
   version:       1.0.0
   name:          Reverb Plugin
   description:   Core of the reverb plugin
   dependencies:  juce_audio_utils, juce_dsp

   website:
   license:       MIT

END_JUCE_MODULE_DECLARATION

==============================================================================
*/

#pragma once

#include <juce_graphics/juce_graphics.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_core/juce_core.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_events/juce_events.h>
#include <juce_dsp/juce_dsp.h>
#include <vector>
#include <memory>
#include <functional>
#include <ranges>
#include <algorithm>
#include <array>
#include <cmath>



#include "include/dsp/FDN_Reverb.h"
#include "include/proces_DAW_control/Parameters.h"
#include "include/gui/CustomLookAndFeel.h"
// order matters, e.g. if processor is not instantiated  before editor, as editor depend on it.
#include "include/proces_DAW_control/PluginProcessor.h"
#include "include/gui/Controller Slider.h"
#include "include/gui/PluginEditor.h"


