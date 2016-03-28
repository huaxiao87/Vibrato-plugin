/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "../inc/PluginProcessor.h"
#include "../inc/PluginEditor.h"
#include "../JuceLibraryCode/JuceHeader.h"



//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	// This is where our plugin�s editor size is set.
	setSize(800, 480);

	// these define the parameters of our slider object

	initializeSlider(m_sliderModulationAmplitude, 0.0, 1.0, 0.01, 220, 50, 60, 330, "amp");
	initializeSlider(m_sliderModulationFrequency, 0.0, 1.0, 0.01, 520, 50, 60, 330, "Hz");
    initializeLabel(m_sliderModulationAmplitude, m_ampLabel, " Amp");
    initializeLabel(m_sliderModulationFrequency, m_freqLabel, " Freq");
    initializeButton(m_timeButton, 350, 400);
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
}

//==============================================================================
void GainAudioProcessorEditor::paint (Graphics& g)
{
	// fill the whole window white
	g.fillAll(Colours::white);

	// set the current drawing colour to black
	g.setColour(Colours::black);

	// set the font size and draw text to the screen
	g.setFont(15.0f);

//	g.drawFittedText("Amplitude", 10, 20, getWidth(), 30, Justification::centred, 1);
//	g.drawFittedText("Frequency", 40, 40, getWidth(), 30, Justification::centred, 1);

}

void GainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	m_sliderModulationAmplitude.setBounds(40, 30, 20, getHeight() - 60);
}

void GainAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.m_fModulationFAmplitude = m_sliderModulationAmplitude.getValue();
	processor.m_fModulationFrequency = m_sliderModulationFrequency.getValue();
}
void GainAudioProcessorEditor::initializeSlider(Slider &slider, float minValue, float maxValue, float step, int x, int y, int width, int height, const String & suffix)
{
	slider.setSliderStyle(Slider::LinearBarVertical);
	slider.setRange(minValue, maxValue, step);
	slider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	slider.setPopupDisplayEnabled(true, this);
	//m_sliderModulationAmplitude.setTextValueSuffix("Volume");
	slider.setValue(1.0);

	// this function adds the slider to the editor
	addAndMakeVisible(&slider);
    
    slider.setTextValueSuffix (suffix);

	// add the listener to the slider
	slider.addListener(this);

	// sets the position and size of the slider with arguments (x, y, width, height)
	slider.setBounds(x, y, width, height);
}

void GainAudioProcessorEditor::initializeLabel(Slider &slider, Label &label, const String & name)
{
    addAndMakeVisible (&label);
    label.setText (name, dontSendNotification);
    label.attachToComponent (&slider, false);
}

void GainAudioProcessorEditor::initializeButton(TextButton &button, int x, int y)
{
    addAndMakeVisible (&button);
    button.setButtonText ("Just a button");
    button.setBounds(x, y, 100, 40);
}


