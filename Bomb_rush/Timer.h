//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <iostream>


class Timer {
public:
    Timer();
    void DrawTimer();
    double GetLifeTime();
private:
    double startTime;
    double lifeTime;
    double current;
};


