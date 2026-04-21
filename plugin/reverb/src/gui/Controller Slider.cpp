
using namespace juce;



ControllerSlider::ControllerSlider ( AudioProcessorValueTreeState& state,
const String& parameterID,
const String& parameterLabel,
AudioPluginAudioProcessor* inProcessor)
: Slider(parameterLabel), mProcessor(*inProcesor)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);

    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(state,parameterID, *this);

}





