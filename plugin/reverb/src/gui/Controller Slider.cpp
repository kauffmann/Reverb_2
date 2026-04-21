



ControllerSlider::ControllerSlider ( AudioProcessorValueTreeState& state,
const String& parameterID,
const String& parameterLabel,
PluginProcessor* inProcessor)
: juce::Slider(parameterLabel), mProcessor(*inProcessor)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);

    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(state,parameterID, *this);

    addListener(this);

    startTimer(30);
}

ControllerSlider::~ControllerSlider()
{
    removeListener(this);
}

void ControllerSlider::mouseDown(const MouseEvent& event)
{


    if (this->hitTest(event.getMouseDownX(), event.getMouseDownY()))
    {
        Slider::mouseDown(event);
        setMouseCursor(MouseCursor::NoCursor);
        mInitialDownMousePosition = Desktop::Desktop::getMousePosition();

    }

}

void ControllerSlider::mouseUp(const MouseEvent& event)
{
    Slider::mouseUp(event);
    Slider::setMouseCursor(MouseCursor::NormalCursor);
    Desktop::setMousePosition(mInitialDownMousePosition);

}

void ControllerSlider::mouseExit(const MouseEvent& event)
{

}

void ControllerSlider::timerCallback()
{
    if (this->isMouseOver()){}

}


void ControllerSlider::sliderValueChanged (Slider*)
{

}



