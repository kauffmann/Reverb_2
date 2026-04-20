


AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    constexpr auto versionHint = 1;

    layout.add(std::make_unique<juce::AudioParameterFloat>(ParameterID{"SIZE",versionHint},
        "Room Size",
        juce::NormalisableRange<float>(10.0f, 200.0f, 10.0f),
        50.0f, String(), AudioProcessorParameter::genericParameter,
        [](float value, int) -> String
        {
            String valueToText =
                String(value , 1) + " DODO";

            return valueToText;
        })); // default:


    layout.add((std::make_unique<juce::AudioParameterFloat>(ParameterID{"DECAY",versionHint},
        "Decay",
        juce::NormalisableRange<float>(0.2f, 40.0f, 0.1f),
        6.0f)));


    layout.add((std::make_unique<juce::AudioParameterFloat>(ParameterID{"DRY", versionHint},
        "Dry",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.1f),
        0.4f))); // default

    layout.add((std::make_unique<juce::AudioParameterFloat>(ParameterID{"DIFFUSSER",versionHint},
        "Diffusser Gain",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.1f),
        0.3f))); // default

    layout.add((std::make_unique<juce::AudioParameterFloat>(ParameterID{"WET_REFLECTIONS",versionHint},
        "Early Reflection Gain",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.1f), 0.3f))); // default


    layout.add((std::make_unique<juce::AudioParameterFloat>(ParameterID{"PREDELAY", versionHint},
        "Predelay",
        juce::NormalisableRange<float>(0.0f, 500.0f, 1.0f), 20.0f, String(), AudioProcessorParameter::genericParameter,
        [](float value, int) -> String
        {
            String valueToText =
                String(value, 1) + " ms";

            return valueToText;
        }))); // default


    return layout;
}