//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <raylib.h>
#include "Player.h"

class Bullet {
public:
    Bullet(Player playerPos);
    void Draw();
    void Update();
    Rectangle GetBody();
    int GetDamage();
    ~Bullet();
private:
    Vector2 position;
    int velocity;
    int damage;
    Rectangle body;
};


