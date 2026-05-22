//
// Created by jorga on 22/05/2026.
//

#include "Timer.h"

#include <raylib.h>

Timer::Timer() {
    startTime = 0;   // Start time (seconds)
    lifeTime = 0;    // Lifetime (seconds)
}

void Timer::DrawTimer() {

    DrawText(TextFormat("Elapsed Time: %02.02f ms", GetFrameTime()*1000), 200, 220, 20, BLACK);
}

void Timer::UpdateTimer() {

}

void Timer::StartTimer(double lifetime)
{
    this->startTime = GetTime();
    this->lifeTime = lifetime;
}

bool Timer::TimerDone()
{
    return GetTime() - this->startTime >= this->lifeTime;
}

double Timer::GetElapsed()
{
    return GetTime() - this->startTime;
}