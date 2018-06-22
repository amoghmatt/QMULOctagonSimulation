/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OctagonSimulationAudioProcessor::OctagonSimulationAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    // Default Values
    bypassState = 0;
    mix = 50.0;
    xPosition = 1;
    yPosition = 1;
    overallGain = 1.0;
    
}

OctagonSimulationAudioProcessor::~OctagonSimulationAudioProcessor()
{
    
}

//==============================================================================
const String OctagonSimulationAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OctagonSimulationAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OctagonSimulationAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OctagonSimulationAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OctagonSimulationAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OctagonSimulationAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OctagonSimulationAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OctagonSimulationAudioProcessor::setCurrentProgram (int index)
{
}

const String OctagonSimulationAudioProcessor::getProgramName (int index)
{
    return {};
}

void OctagonSimulationAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void OctagonSimulationAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    loadFile.changeImpulseNow(1);
    formatManager.registerBasicFormats();
    
    dsp::ProcessSpec spec {sampleRate, static_cast<uint32>(samplesPerBlock), 2};
    convolution.prepare(spec);
    transportSource.prepareToPlay(samplesPerBlock, sampleRate);
    
    
    _impulseFile = loadFile.getImpulseData();
    convolution.loadImpulseResponse(_impulseFile, true, false, 0, true);

}

void OctagonSimulationAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OctagonSimulationAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void OctagonSimulationAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    AudioSampleBuffer wetSamples;
    wetSamples.makeCopyOf(buffer);
    int newImpulseID = static_cast<int>((13 * (getYPosition() - 1)) + getXPosition());
    
    loadFile.changeImpulseAsync(newImpulseID);
    _impulseFile = loadFile.getImpulseData();
    
    float reverbMix = getMix() / 100.0;
    const bool impulseChanging {loadFile.isNowChanging()};
    
    if(impulseChanging && !getBypass())
        buffer.applyGain(0.25f);
    
    if(getBypass() || impulseChanging)
    {
        // BYPASS
    }
    else
    {
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            convolution.loadImpulseResponse(_impulseFile, true, false, 0, true);
            dsp::AudioBlock<float> wet_block (wetSamples, wetSamples.getSample(channel, 0));
            dsp::AudioBlock<float> dry_block (buffer, buffer.getSample(channel, 0));
            convolution.process(dsp::ProcessContextReplacing<float>(wet_block));
            dry_block.multiply(1.0 - reverbMix);
            wet_block.multiply(reverbMix);
            dry_block.add(wet_block);
        }
    }
    
    buffer.applyGain(overallGain);
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
}

//==============================================================================
bool OctagonSimulationAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* OctagonSimulationAudioProcessor::createEditor()
{
    return new OctagonSimulationAudioProcessorEditor (*this);
}

//==============================================================================
void OctagonSimulationAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OctagonSimulationAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OctagonSimulationAudioProcessor();
}
