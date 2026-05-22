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
    DrawText(TextFormat("Elapsed Time: %02.02f s", GetTime()), 10, 10, 30, BLACK);
}

void Timer::DrawTimerBackwards() {
    startTime = 60;
    lifeTime = startTime - GetTime();
    DrawText(TextFormat("Time Remaining: %02.02f s", lifeTime), 350, 10, 30, BLACK);
}