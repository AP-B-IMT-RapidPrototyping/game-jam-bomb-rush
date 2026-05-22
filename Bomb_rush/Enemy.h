//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <iostream>

#include "Bullet.h"
#include "raylib.h"


class Enemy {
public:
    Enemy();
    void Draw();
    void Update(Bullet bullet);
    Vector2 GetPos();
    ~Enemy();
private:
    int hp;
    Vector2 position;
    float width;
    float height;
    Rectangle body;



};


