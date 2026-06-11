

<img width="1265" height="546" alt="Screenshot 2026-06-08 at 12 35 01" src="https://github.com/user-attachments/assets/0d24f7d9-725e-4bcb-a5c2-7402ed480259" />
<br/><br/><br/><br/><br/><br/>



# Feedback Delay Network Reverb VST3 Audio FX Plugin

Based on Geraint Luft's "Let's write a reverb," talk. This is my own custom implementation of a reverb using his DSP library. 
I've also added early refelctions and pre-delay. Talk: https://www.youtube.com/watch?v=QWnD30xHjW4 Geraint Luft: https://signalsmith-audio.co.uk/

## Dependency 

Geraint Luft's DSP library https://github.com/Signalsmith-Audio/dsp.

JUCE 8 https://juce.com/ Please check license if you are using this.

CMake

## Usage
After cloning it locally, creating your own git repo,  you can proceed with the usual CMake workflow.

From CLI, at your project directory, execute:

$ cmake -S . -B build<br/>
$ cmake --build build

The first run will take the most time because the dependencies (CPM, JUCE, and googletest) need to be downloaded.

On Mac/Xcode you must first run config from terminal, creating a .xcodeproj file you can open in xcode(cmake -S . -B build -G Xcode). 
