




AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : processorRef(p) {
  juce::ignoreUnused(processorRef);


  //background.setImage(juce::ImageCache::getFromMemory(reverb::assets::background_png, reverb::assets::background_pngSize));
  //addAndMakeVisible(background);
  background = juce::ImageCache::getFromMemory(reverb::assets::background_blue_png, reverb::assets::background_blue_pngSize);

  sizeSlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "SIZE", "Room Size");
  //sizeSlider->setTextValueSuffix(" ");
  sizeSlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(sizeSlider.get());

  sizeLabel.setJustificationType(juce::Justification::centred);
  sizeLabel.setInterceptsMouseClicks(false, false);
  sizeLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(sizeLabel);

  decaySlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "DECAY", "Decay");
  decaySlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(decaySlider.get());

  decayLabel.setJustificationType(juce::Justification::centred);
  decayLabel.setInterceptsMouseClicks(false, false);
  decayLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(decayLabel);

  drySlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "DRY", "Dry");
  drySlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(drySlider.get());

  dryLabel.setJustificationType(juce::Justification::centred);
  dryLabel.setInterceptsMouseClicks(false, false);
  dryLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(dryLabel);


  wetSlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "WET", "Wet");
  wetSlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(wetSlider.get());

  wetLabel.setJustificationType(juce::Justification::centred);
  wetLabel.setInterceptsMouseClicks(false, false);
  wetLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(wetLabel);

  earlyReflectionSlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "EARLY REFLECTIONS", "Early reflection");
  earlyReflectionSlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(earlyReflectionSlider.get());

  earlyreflectionLabel.setJustificationType(juce::Justification::centred);
  earlyreflectionLabel.setInterceptsMouseClicks(false, false);
  earlyreflectionLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(earlyreflectionLabel);


  preDelaySlider = std::make_unique<ControllerSlider>(processorRef.getAPVTS(), "PREDELAY", "Predelay");
  preDelaySlider->setPopupDisplayEnabled(true, true, this);

  addAndMakeVisible(preDelaySlider.get());

  preDelayLabel.setJustificationType(juce::Justification::centred);
  preDelayLabel.setInterceptsMouseClicks(false, false);
  preDelayLabel.setFont(lookAndFeel.getSliderLabelFont());
  addAndMakeVisible(preDelayLabel);


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

  const int slider_size = 100;

  int sliderXpos = static_cast<int>( getWidth() / 6);

  sizeSlider->setBounds( static_cast<int>( sliderXpos - slider_size),
                     static_cast<int>( (getHeight() * 0.34f)),
                     slider_size, slider_size);


  //JUCE_LIVE_CONSTANT(0.50)
  sizeLabel.setBounds(static_cast<int>( sliderXpos - slider_size),
                     getHeight() * 0.37 + 50,
                     slider_size, slider_size);


  decaySlider->setBounds( static_cast<int>( sliderXpos * 2 - slider_size),
                     static_cast<int>( (getHeight() * 0.34f)),
                     slider_size, slider_size);



  decayLabel.setBounds(static_cast<int>( sliderXpos * 2 - slider_size),
                     getHeight() * 0.37 + 50,
                     slider_size, slider_size);


  drySlider->setBounds( static_cast<int>( sliderXpos * 3 - slider_size),
                     static_cast<int>( (getHeight() * 0.34f)),
                     slider_size, slider_size);



  dryLabel.setBounds(static_cast<int>( sliderXpos * 3 - slider_size),
                     getHeight() * 0.37 + 50,
                     slider_size, slider_size);


 wetSlider->setBounds( static_cast<int>( sliderXpos * 4 - slider_size),
                     static_cast<int>( (getHeight() * 0.34f)),
                     slider_size, slider_size);



 wetLabel.setBounds(static_cast<int>( sliderXpos * 4 - slider_size),
                       getHeight() * 0.37 + 50,
                       slider_size, slider_size);

earlyReflectionSlider->setBounds( static_cast<int>( sliderXpos * 5 - slider_size),
                     static_cast<int>( (getHeight() * 0.34f)),
                     slider_size, slider_size);



earlyreflectionLabel.setBounds(static_cast<int>( sliderXpos * 5 - slider_size),
                       getHeight() * 0.37 + 50,
                       slider_size, slider_size);


preDelaySlider->setBounds( static_cast<int>( sliderXpos * 6 - slider_size),
                     static_cast<int>( (getHeight() * 0.34f)),
                     slider_size, slider_size);



preDelayLabel.setBounds(static_cast<int>( sliderXpos * 6 - slider_size),
                       getHeight() * 0.37 + 50,
                       slider_size, slider_size);



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
