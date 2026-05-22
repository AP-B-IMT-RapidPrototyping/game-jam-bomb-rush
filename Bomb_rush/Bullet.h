//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <raylib.h>


class Bullet {
public:
    Bullet();
    void Draw();
    void Update();
    ~Bullet();
private:
    Vector2 position;
    Vector2 velocity;
};


