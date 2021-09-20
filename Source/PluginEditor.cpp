/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor(&p), mWaveThumbnail{ p }, mADSR{ p }, processor(p)
{
    auto lsImage = juce::ImageCache::getFromMemory(BinaryData::LaszloSomogyiMusic_png, BinaryData::LaszloSomogyiMusic_pngSize);

    if (!lsImage.isNull())
        mImageComponent.setImage(lsImage, juce::RectanglePlacement::stretchToFit);
    else
        jassert(! lsImage.isNull());


    addAndMakeVisible(mWaveThumbnail);
    addAndMakeVisible(mADSR);
    addAndMakeVisible(mImageComponent);

    startTimerHz(30);
    setSize (600, 400);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
    stopTimer();
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

}

void HelloSamplerAudioProcessorEditor::resized()
{
    mWaveThumbnail.setBoundsRelative(0.0f, 0.25f, 1.0f, 0.5f);
    mADSR.setBoundsRelative(0.0f, 0.75f, 1.0f, 0.25f);
    mImageComponent.setBoundsRelative(0.0f, 0.0f, 0.25f, 0.25f);
}

void HelloSamplerAudioProcessorEditor::timerCallback()
{
    repaint();
}




