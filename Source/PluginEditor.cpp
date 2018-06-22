/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OctagonSimulationAudioProcessorEditor::OctagonSimulationAudioProcessorEditor (OctagonSimulationAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p),
    backgroundImage{ImageCache::getFromMemory(BinaryData::octagon_jpg, BinaryData::octagon_jpgSize)}
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize(640, 656);
    startTimer(100);
    
    addAndMakeVisible(xAxisSlider);
    xAxisSlider.setRange(0, 12, 1);
    xAxisSlider.setSliderStyle (Slider::LinearHorizontal);
    xAxisSlider.setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    xAxisSlider.setColour(Slider::textBoxBackgroundColourId, Colours::black);
    xAxisSlider.setColour(Slider::textBoxTextColourId, Colours::white);
    xAxisSlider.addListener(this);
    
    addAndMakeVisible(yAxisSlider);
    yAxisSlider.setRange(0, 12, 1);
    yAxisSlider.setSliderStyle (Slider::LinearVertical);
    yAxisSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    yAxisSlider.setColour(Slider::textBoxBackgroundColourId, Colours::black);
    yAxisSlider.setColour(Slider::textBoxTextColourId, Colours::white);
    yAxisSlider.addListener(this);
    
    addAndMakeVisible(mixSlider);
    mixSlider.setRange (0, 100, 0);
    mixSlider.setSliderStyle (Slider::Rotary);
    mixSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    mixSlider.setColour(Slider::textBoxBackgroundColourId, Colours::black);
    mixSlider.setColour(Slider::textBoxTextColourId, Colours::white);
    mixSlider.addListener(this);
    
    addAndMakeVisible(gainSlider);
    gainSlider.setRange (-80, 40, 0);
    gainSlider.setSliderStyle (Slider::Rotary);
    gainSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainSlider.setColour(Slider::textBoxBackgroundColourId, Colours::black);
    gainSlider.setColour(Slider::textBoxTextColourId, Colours::white);
    gainSlider.addListener(this);
    
    addAndMakeVisible(bypassButton);
    bypassButton.setButtonText (TRANS("Bypass"));
    bypassButton.setColour(TextButton::buttonOnColourId, Colours::lightblue);
    bypassButton.setColour(TextButton::textColourOnId, Colours::white);
    bypassButton.setColour(TextButton::textColourOffId, Colours::black);
    bypassButton.addListener(this);
    
    addAndMakeVisible(xLabel);
    xLabel.setText("X Plane:", dontSendNotification);
    xLabel.setFont (Font (15.00f, Font::plain));
    xLabel.setJustificationType (Justification::centredLeft);
    xLabel.setEditable (false, false, false);
    xLabel.setColour(Label::textColourId, Colours::black);
    
    addAndMakeVisible(yLabel);
    yLabel.setText("Y Plane:", dontSendNotification);
    yLabel.setFont (Font (15.00f, Font::plain));
    yLabel.setJustificationType (Justification::centredLeft);
    yLabel.setEditable (false, false, false);
    yLabel.setColour(Label::textColourId, Colours::black);
    
    addAndMakeVisible(mixLabel);
    mixLabel.setText("Mix:", dontSendNotification);
    mixLabel.setFont (Font (15.00f, Font::plain));
    mixLabel.setJustificationType (Justification::centredLeft);
    mixLabel.setEditable (false, false, false);
    mixLabel.setColour(Label::textColourId, Colours::black);
    
    addAndMakeVisible(gainLabel);
    gainLabel.setText("Gain:", dontSendNotification);
    gainLabel.setFont (Font (15.00f, Font::plain));
    gainLabel.setJustificationType (Justification::centredLeft);
    gainLabel.setEditable (false, false, false);
    gainLabel.setColour(Label::textColourId, Colours::black);

}

OctagonSimulationAudioProcessorEditor::~OctagonSimulationAudioProcessorEditor()
{
    
}

//==============================================================================
void OctagonSimulationAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll(Colours::black);
    g.drawImage(backgroundImage, 0, 0, 640, 656, 0, 0, 1280, 1312);
    
    g.setColour (Colours::black);
    g.setFont (20.0f);
    g.drawFittedText ("QMUL Octagon Reverb", getWidth()/2 - 75, 50, 150, 20, Justification::centred, 1);
}

void OctagonSimulationAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    bypassButton.setBounds(getWidth()/2 - 50, 75, 100, 40);
    
    xAxisSlider.setBounds(110, 525, 400, 40);
    yAxisSlider.setBounds(25, 170, 80, 375);
    mixSlider.setBounds(getWidth()/2 - 300, 50, 100, 100);
    gainSlider.setBounds(getWidth() - 100, 50, 100, 100);
    
    //xLabel.setBounds(getWidth()/2 - 30, 330, 80, 40);
    //yLabel.setBounds(getWidth()/2 - 250, 170, 80, 40);
    mixLabel.setBounds(0, 50 , 80, 40);
    gainLabel.setBounds(getWidth() - 150, 50, 80, 40);
    
}

void OctagonSimulationAudioProcessorEditor::sliderValueChanged (Slider* sliderMoved)
{
    if (sliderMoved == &xAxisSlider)
        processor.setXPosition(xAxisSlider.getValue() + 1);
    else if (sliderMoved == &yAxisSlider)
        processor.setYPosition(yAxisSlider.getValue() + 1);
    else if (sliderMoved == &mixSlider)
        processor.setMix(mixSlider.getValue());
    else if (sliderMoved == &gainSlider)
        processor.setOverallGain(gainSlider.getValue());
}

void OctagonSimulationAudioProcessorEditor::buttonClicked(Button* buttonClicked)
{
    if (buttonClicked == &bypassButton)
        processor.setBypass(!processor.getBypass());
}

void OctagonSimulationAudioProcessorEditor::timerCallback()
{
    bypassButton.setToggleState(processor.getBypass(), dontSendNotification);
    xAxisSlider.setValue(processor.getXPosition() - 1);
    yAxisSlider.setValue(processor.getYPosition() - 1);
    mixSlider.setValue(processor.getMix());
    gainSlider.setValue(processor.getGain());
    
}
