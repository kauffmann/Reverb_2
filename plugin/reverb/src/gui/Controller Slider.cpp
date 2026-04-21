
using namespace juce;



ControllerSlider::ControllerSlider ( juce::AudioProcessorValueTreeState& state,
                                     const juce::String& parameterID,
                                     const juce::String& parameterLabel)
: Slider(parameterLabel)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);

    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(state,parameterID, *this);

}

ControllerSlider::~ControllerSlider() {}



