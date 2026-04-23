


#include "ReverbAssets.h"

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : processorRef(p) {
  juce::ignoreUnused(processorRef);


  //background.setImage(juce::ImageCache::getFromMemory(reverb::assets::background_png, reverb::assets::background_pngSize));
  //addAndMakeVisible(background);
  background = juce::ImageCache::getFromMemory(reverb::assets::background_png, reverb::assets::background_pngSize);

  sizeSlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "SIZE", "Room Size");
  //sizeSlider->setTextValueSuffix(" ");
  sizeSlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(sizeSlider.get());

  sizeLabel.setJustificationType(juce::Justification::centred);
  sizeLabel.setInterceptsMouseClicks(false, false);
  sizeLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(sizeLabel);



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

  const auto bounds = getLocalBounds();


  //auto sizeSliderBounds = bounds.reduced(230, 40);
  //sizeSliderBounds.removeFromBottom(110);
  //sizeSlider->setBounds(sizeSliderBounds);
  const int slider_size = 100;



  sizeSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5),
                     (getHeight() * 0.35) - (slider_size * 0.5),
                     slider_size, slider_size);

  //rateLabel.setBounds(sizeSliderBounds);

  auto sliderBounds = bounds.reduced(230, 40);
  sliderBounds.removeFromBottom(110);
  //JUCE_LIVE_CONSTANT(0.50)
  sizeLabel.setBounds((getWidth() * 0.5) - (slider_size * 0.5),
                     getHeight() * 0.37,
                     slider_size, slider_size);

  //sizeLabel.setBounds(sliderBounds);

}



// Wrapper implementation

WrappedRasterAudioProcessorEditor::WrappedRasterAudioProcessorEditor(AudioPluginAudioProcessor& p) :
    AudioProcessorEditor(p),
    rasterComponent(p), mProcessor(p)
{

  addAndMakeVisible(rasterComponent);



  if (auto* constrainer = getConstrainer())
  {
    constrainer->setFixedAspectRatio(static_cast<double> (originalWidth) / static_cast<double> (originalHeight)); //impotant, is used when resized. w ad h must always fit this ratio
    constrainer->setSizeLimits(originalWidth / 4, originalHeight / 4, originalWidth * 2, originalHeight * 2);
  }

  double sizeRatio = mProcessor.getResizeFactor();



  setResizable(true, true);
  setSize(static_cast<int> (originalWidth * sizeRatio), static_cast<int> (originalHeight * sizeRatio));
}

void WrappedRasterAudioProcessorEditor::resized()
{
  const auto scaleFactor = static_cast<float> (getWidth()) / originalWidth;
  mProcessor.setResizeFactor(scaleFactor);


  rasterComponent.setTransform(juce::AffineTransform::scale(scaleFactor)); // this is the actual scale transforming
  rasterComponent.setBounds(0, 0, originalWidth, originalHeight); // unintuitive, but need this as transform use original bounds to transform from.
}
