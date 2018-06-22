//
//  LoadImpulseFile.h
//  OctagonSimulation - All
//
//  Created by Amogh Matt on 21/03/2018.
//

#ifndef LoadImpulseFile_h
#define LoadImpulseFile_h

#include "../JuceLibraryCode/JuceHeader.h"

class LoadImpulseFile: private Timer
{
public:
    LoadImpulseFile () { startTimer(200); }
    ~LoadImpulseFile () {}

    void changeImpulseAsync (int newImpulse);
    void changeImpulseNow (int newImpulse) { changeImpulse (newImpulse); }

    const bool isNowChanging() { return nowChangingImpulse; }
    File getImpulseData() { return impulseFile; }
    
private:
    int currentImpulse {-1};
    bool nowChangingImpulse {false};
    
    File impulseFile;
    
    void timerCallback() override;
    void changeImpulse(int newImpulse);
};

#endif /* LoadImpulseFile_h */
