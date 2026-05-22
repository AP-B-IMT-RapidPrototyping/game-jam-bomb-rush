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

    startTime = 3;
    lifeTime = startTime - GetTime();
    current = GetTime();
    if (lifeTime>0) {
        DrawText(TextFormat("Time Remaining: %02.02f s", lifeTime), 450, 10, 30, BLACK);
        DrawText(TextFormat("Elapsed Time: %02.02f s", GetTime()), 10, 10, 30, BLACK);
    }
    if (lifeTime <=0) {
        DrawText("GAME OVER",200,200,50,BLACK);
        current += lifeTime;
        DrawText(TextFormat("Time Remaining: %02.02f s", 0), 450, 10, 30, BLACK);
        DrawText(TextFormat("Elapsed Time: %02.02f s", current), 10, 10, 30, BLACK);
    }
}

double Timer::GetLifeTime() {
    return lifeTime;
}
