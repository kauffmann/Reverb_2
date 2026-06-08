#pragma once


class AudioPluginAudioProcessorEditor : public juce::Component {
public:
  explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);
  ~AudioPluginAudioProcessorEditor() override;

  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  AudioPluginAudioProcessor& processorRef;
  CustomLookAndFeel lookAndFeel;

  juce::Image background;
  juce::Label sizeLabel{"size label", "SIZE"};
  juce::Label decayLabel{"decay label", "DECAY"};
  juce::Label dryLabel{"dry label", "DRY"};
  juce::Label wetLabel{"reverb label", "REVERB"};
  juce::Label earlyreflectionLabel{"early reflection label", "EARLY REFLECTION"};
  juce::Label preDelayLabel{"predelay label", "PREDELAY"};


  ControllerSlider sizeSlider;
  ControllerSlider decaySlider;
  ControllerSlider drySlider;
  ControllerSlider wetSlider;
  ControllerSlider earlyReflectionSlider;
  ControllerSlider preDelaySlider;



  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};

class WrappedRasterAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
  WrappedRasterAudioProcessorEditor(AudioPluginAudioProcessor&);
  void resized() override;

private:
  static constexpr int originalWidth{ 750};
  static constexpr int originalHeight{ 310};

  AudioPluginAudioProcessorEditor rasterComponent;

  AudioPluginAudioProcessor& mProcessor;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WrappedRasterAudioProcessorEditor)
};