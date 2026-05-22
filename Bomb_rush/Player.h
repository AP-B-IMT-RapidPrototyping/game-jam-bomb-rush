//
// Created by jorga on 22/05/2026.
//

#pragma once
#include "Map.h"
#include "raylib.h"

class Player {
    Vector2 position;
    float speed;
    bool canJump;
    Rectangle playerRect;

public:
    Player();
    void Draw();
    void Update(Map *envItems, int envItemsLength, float delta);
    Vector2 GetPos();
    void Shoot();
};


