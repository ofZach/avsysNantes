
#pragma once


#include "ofMain.h"


class oscillator {
    
    public:
    
    int sampleRate;
    float frequency;
    float volume;
    float phase;
    float phaseAdder;
    
    void setup (int sampleRate);
    void setFrequency (float freq);
    void setVolume (float volume);

    float getSample();

};