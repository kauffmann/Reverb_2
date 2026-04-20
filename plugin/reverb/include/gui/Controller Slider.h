#pragma once

class ContollerSlider : public Slider, public Slider::Listener, public Timer
{

public:


    ContollerSlider( AudioProcessorValueTreeState& state,
                     const String& parameterID,
                     const String& parameterLabel,
                     PluginProcessor* inProcessor);
    ~ContollerSlider();


    void mouseDown(const MouseEvent& event) override;

    void mouseUp(const MouseEvent& event) override;

    void mouseExit(const MouseEvent& event) override;

    void timerCallback() override;

    void sliderValueChanged (Slider*) override;



private:
    Point<int> mInitialDownMousePosition;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    PluginProcessor& mProcessor;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ContollerSlider)

};
