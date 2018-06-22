/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class OctagonSimulationAudioProcessorEditor  : public AudioProcessorEditor, public Timer, public Slider::Listener, public Button::Listener
{
public:
    OctagonSimulationAudioProcessorEditor (OctagonSimulationAudioProcessor&);
    ~OctagonSimulationAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void timerCallback() override;
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button* buttonClicked) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OctagonSimulationAudioProcessor& processor;
    
    Slider xAxisSlider;
    Slider yAxisSlider;
    Slider mixSlider;
    Slider gainSlider;
    
    Label xLabel;
    Label yLabel;
    Label mixLabel;
    Label gainLabel;
    
    TextButton bypassButton;
    
    Image backgroundImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OctagonSimulationAudioProcessorEditor)
};
