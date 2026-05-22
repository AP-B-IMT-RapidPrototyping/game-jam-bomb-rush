//
// Created by jorga on 22/05/2026.
//

#include "Timer.h"

#include <raylib.h>

Timer::Timer() {
    startTime = 0;   // Start time (seconds)
    lifeTime = 0;    // Lifetime (seconds)
}

void StartTimer(Timer *timer, double lifetime)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}