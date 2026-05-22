//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <raylib.h>
#include "Player.h"

class Bullet {
public:
    Bullet(Vector2 playerPos,bool lookingLeft);
    void Draw();
    void Update();
    int GetVelocity();
    Rectangle GetBody();
    int GetDamage();
    ~Bullet();
private:
    Vector2 position;
    int velocity;
    int damage;
    Rectangle body;
};


