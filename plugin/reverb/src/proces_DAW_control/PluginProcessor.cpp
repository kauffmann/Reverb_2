

AudioPluginAudioProcessor::AudioPluginAudioProcessor()
    : AudioProcessor(
          BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
              .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
              .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
      ), apvts(*this, nullptr, "Parameters", parameters.createParameterLayout()) {
    
    // Register the processor as a listener to the parameters
    apvts.addParameterListener("SIZE", this);
    apvts.addParameterListener("DECAY", this);
    apvts.addParameterListener("DRY", this);
    apvts.addParameterListener("WET", this);
    apvts.addParameterListener("EARLY REFLECTIONS", this);
    apvts.addParameterListener("PREDELAY", this);
}

AudioPluginAudioProcessor::~AudioPluginAudioProcessor() 
{
    apvts.removeParameterListener("SIZE", this);
    apvts.removeParameterListener("DECAY", this);
    apvts.removeParameterListener("DRY", this);
    apvts.removeParameterListener("WET", this);
    apvts.removeParameterListener("EARLY REFLECTIONS", this);
    apvts.removeParameterListener("PREDELAY", this);
}

const juce::String AudioPluginAudioProcessor::getName() const {
  return JucePlugin_Name;
}

bool AudioPluginAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool AudioPluginAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool AudioPluginAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double AudioPluginAudioProcessor::getTailLengthSeconds() const {
  return 0.0;
}

int AudioPluginAudioProcessor::getNumPrograms() {
  return 1;  // NB: some hosts don't cope very well if you tell them there are 0
             // programs, so this should be at least 1, even if you're not
             // really implementing programs.
}

int AudioPluginAudioProcessor::getCurrentProgram() {
  return 0;
}

void AudioPluginAudioProcessor::setCurrentProgram(int index) {
  juce::ignoreUnused(index);
}

const juce::String AudioPluginAudioProcessor::getProgramName(int index) {
  juce::ignoreUnused(index);
  return {};
}

void AudioPluginAudioProcessor::changeProgramName(int index,
                                                  const juce::String& newName) {
  juce::ignoreUnused(index, newName);
}

void AudioPluginAudioProcessor::prepareToPlay(double sampleRate,
                                              int samplesPerBlock) {
  // Use this method as the place to do any pre-playback
  // initialisation that you need..
  juce::ignoreUnused(sampleRate, samplesPerBlock);

  reverb.configure(sampleRate);
    /*int arr[5] = {0, 1, 2, 3, 4};
    std::cout << "Accessing out of bounds (stack buffer overflow): ";
    std::cout << arr[10] << std::endl;  // ASan will catch this*/




  
}

void AudioPluginAudioProcessor::releaseResources() {
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

bool AudioPluginAudioProcessor::isBusesLayoutSupported(
    const BusesLayout& layouts) const {
#if JucePlugin_IsMidiEffect
  juce::ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  // Some plugin hosts, such as certain GarageBand versions, will only
  // load plugins that support stereo bus layouts.
  if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
    return false;

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}

void AudioPluginAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);

    juce::ScopedNoDenormals noDenormals;

    auto* channelDataL = buffer.getWritePointer(0);
    auto* channelDataR = buffer.getWritePointer(1);

    reverb.process(channelDataL, channelDataR, buffer.getNumSamples());
      
}

bool AudioPluginAudioProcessor::hasEditor() const {
  return true;  // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* AudioPluginAudioProcessor::createEditor() {
  return new WrappedRasterAudioProcessorEditor(*this);
}

void AudioPluginAudioProcessor::getStateInformation(
    juce::MemoryBlock& destData) {
  
    
    juce::ValueTree params("Params");

    for (auto& param : getParameters())
    {
        juce::ValueTree paramTree(getParamID(param));
        paramTree.setProperty("Value", param->getValue(), nullptr);
        params.appendChild(paramTree, nullptr);
    }


    copyXmlToBinary(*params.createXml(), destData);


}

void AudioPluginAudioProcessor::setStateInformation(const void* data, int sizeInBytes) 
{


    auto xml = getXmlFromBinary(data, sizeInBytes);

    if (xml != nullptr)
    {
        auto preset = juce::ValueTree::fromXml(*xml);

        for (auto& param : getParameters())
        {
            auto paramTree = preset.getChildWithName(getParamID(param));

            if (paramTree.isValid())
                param->setValueNotifyingHost(paramTree["Value"]);
        }
    }
}


// This creates new instances of the plugin.
// This function definition must be in the global namespace.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
  return new AudioPluginAudioProcessor();
}




void AudioPluginAudioProcessor::parameterChanged(const juce::String& parameterID, float newValue) 
{




    if (parameterID == "SIZE")
    {
        reverb.setRoomSize(newValue);

    }
    else if (parameterID == "DECAY")
    {
        reverb.setDecay(newValue);
       
    }

    else if (parameterID == "DRY")
    {
       reverb.setDry(newValue);
    }

    else if (parameterID == "WET")
    {
        reverb.setDiffusionGain(newValue);
    }

    else if (parameterID == "EARLY REFLECTIONS")
    {
        reverb.setEarlyReflections(newValue);
    }

    else if (parameterID == "PREDELAY")
    {
        reverb.setPreDelay(newValue);
    }

}


