


#include "ReverbAssets.h"

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p) {
  juce::ignoreUnused(processorRef);


  //background.setImage(juce::ImageCache::getFromMemory(reverb::assets::background_png, reverb::assets::background_pngSize));
  //addAndMakeVisible(background);
  background = juce::ImageCache::getFromMemory(reverb::assets::background_png, reverb::assets::background_pngSize);

  sizeSlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "SIZE", "Room Size");
  addAndMakeVisible(sizeSlider.get());

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(800, 400);    // 540, 270)

  setLookAndFeel(&lookAndFeel);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
  setLookAndFeel(nullptr);
}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.drawImageWithin(background, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit, false);


  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  //g.drawFittedText("Reverb", getLocalBounds(),
    //               juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized() {

  //const auto bounds = getLocalBounds();


  //auto sizeSliderBounds = bounds.reduced(230, 40);
  //sizeSliderBounds.removeFromBottom(110);
  //sizeSlider->setBounds(sizeSliderBounds);
  const int slider_size = 100;



  sizeSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5),
                     (getHeight() * 0.35) - (slider_size * 0.5),
                     slider_size, slider_size);

  //rateLabel.setBounds(sizeSliderBounds);

}
