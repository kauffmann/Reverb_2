#pragma once

using namespace juce;


class ControllerSlider : public Slider
{

public:
    ControllerSlider( AudioProcessorValueTreeState& state,
                     const String& parameterID,
                     const String& parameterLabel);

    ~ControllerSlider();






private:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControllerSlider)

};
