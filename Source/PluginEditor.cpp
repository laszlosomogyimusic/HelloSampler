/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //mLoadButton.onClick = [&]() { p.loadFile(); };
    //addAndMakeVisible(mLoadButton);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
}

//==============================================================================
void HelloSamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    g.fillAll(juce::Colours::black);

    g.setColour(juce::Colours::white);
    g.setFont(15.0f);

    if (audioProcessor.getNumSamplerSounds() > 0)
    {
        g.fillAll(juce::Colours::green);
        g.drawText("Sound loaded", getWidth() / 2 - 50, getHeight() / 2 - 10, 100, 20, juce::Justification::centred);

    }
    else
    {
        g.drawText("Load a sound", getWidth() / 2 - 50, getHeight() / 2 - 10, 100, 20, juce::Justification::centred);
    }
}

void HelloSamplerAudioProcessorEditor::resized()
{
    //mLoadButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);

}
bool HelloSamplerAudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray& files)
{
    for (auto file : files)
    {
        if (file.contains(".wav") || file.contains(".mp3") || file.contains(".aif"))
        {
            return true;
        }
    }

    return false;
}

void HelloSamplerAudioProcessorEditor::filesDropped(const juce::StringArray& files, int x, int y)
{
    for (auto file : files)
    {
        if (isInterestedInFileDrag(file))
        {
            audioProcessor.loadFile(file);
        }
    }
    repaint();
}


