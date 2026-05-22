//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <iostream>


class Timer {
public:
    Timer();
    void DrawTimer();
    void UpdateTimer();
    void StartTimer(double lifetime);
    bool TimerDone();
    double GetElapsed();
    double startTime;
    double lifeTime;
    std::string time;
private:
};


