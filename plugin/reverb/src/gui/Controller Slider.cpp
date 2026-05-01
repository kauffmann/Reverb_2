




ControllerSlider::ControllerSlider ( juce::AudioProcessorValueTreeState& state,
                                     const juce::String& parameterID,
                                     const juce::String& parameterLabel)
: Slider(parameterLabel), mAttachment(state, parameterID, *this)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);



    

}

ControllerSlider::~ControllerSlider() {}



