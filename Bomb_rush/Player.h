//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <vector>

#include "Bullet.h"
#include "Map.h"
#include "raylib.h"

class Player {
public:
    Vector2 position;
    float speed;
    bool canJump;
    Rectangle playerRect;
    bool lookingLeft;

    Player();
    void Update(Map *envItems, int envItemsLength, float delta);
    Vector2 GetPos();
    std::vector<Bullet*> Shoot(std::vector<Bullet*>);
};


