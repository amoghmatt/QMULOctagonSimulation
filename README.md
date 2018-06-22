# QMULOctagonSimulation
My implementation of a  a simulation of the QMUL Octagon Building as an audio plugin using multiple impulse responses. Developed using JUCE

## Running Instructions

Since the Impulses folder is too large to be placed within the initial zip, the impulses folder can be found here 
https://c4dm.eecs.qmul.ac.uk/rdr/handle/123456789/10

The “Impulses” folder MUST be placed in ~/Library/Audio/Plug-Ins/Impulses for the effect to work.
Ex: ~/Library/Audio/Plug-Ins/Impulses/x01y00.wav

The plugin can be compiled by running the OctagonSimulation.jucer file. Kindly make sure that before building the code in the Projucer application there are 7 files and 1 Folder (with 169 wave files) which are imported into the project. Details are as follows
Files  - LoadImpulseFile.cpp, LoadImpulseFile.h, PluginEditor.cpp, PluginEditor.h, PluginProcessor.cpp, PluginProcessor.h, octagon.jpg Folder - impulses
