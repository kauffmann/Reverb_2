#pragma once


class AudioPluginAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);
  ~AudioPluginAudioProcessorEditor() override;

  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  AudioPluginAudioProcessor& processorRef;

  juce::Image background;
  //juce::Label sizeLabel{"size label", "SIZE"};
  //juce::Label decayLabel{"decay label", "DECAY"};
  //juce::Label dryLabel{"rate label", "DRY"};
  //juce::Label wetLabel{"rate label", "WET"};
  //juce::Label earlyreflectionLabel{"early reflection label", "EARLY REFLECTION"};
  //juce::Label preDelayLabel{"predelay label", "PREDELAY"};
  std::unique_ptr<ControllerSlider> sizeSlider;


  //ControllerSlider decaySlider;
  //ControllerSlider drySlider;
  //ControllerSlider wetSlider;
  //ControllerSlider earlyReflectionSlider;
  //ControllerSlider preDelay;

  CustomLookAndFeel lookAndFeel;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};

