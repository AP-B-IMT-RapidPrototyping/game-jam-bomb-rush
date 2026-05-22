//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <raylib.h>


class Bullet {
public:
    Bullet(Vector2 playerPos);
    void Draw();
    void Update();
    Vector2 GetPos();
    ~Bullet();
private:
    Vector2 position;
    int velocity;
};


