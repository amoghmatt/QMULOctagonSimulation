/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "LoadImpulseFile.h"

//==============================================================================
/**
*/
class OctagonSimulationAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    OctagonSimulationAudioProcessor();
    ~OctagonSimulationAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //==============================================================================
    void setXPosition(int xValue) { xPosition = xValue; }
    void setYPosition(int yValue) { yPosition = yValue; }
    void setBypass(int bypassValue) { bypassState = bypassValue; }
    void setMix(float mixValue) { mix = mixValue; }
    void setOverallGain(float gainValue) { overallGain = Decibels::decibelsToGain(gainValue); }
    
    //==============================================================================
    int getXPosition() { return xPosition; }
    int getYPosition() { return yPosition; }
    int getBypass() { return bypassState; }
    float getMix() { return mix; }
    float getGain() { return Decibels::gainToDecibels(overallGain); }
    
private:
    
    int xPosition;
    int yPosition;
    int bypassState;
    float mix;
    float overallGain;
    
    File _impulseFile;
    
    LoadImpulseFile loadFile;
    dsp::Convolution convolution;
    AudioFormatManager formatManager;
    
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OctagonSimulationAudioProcessor)
};
