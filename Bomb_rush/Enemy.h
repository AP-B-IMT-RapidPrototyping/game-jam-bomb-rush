//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <iostream>

#include "raylib.h"


class Enemy {
public:
    Enemy();
    void Draw();
    void Update();
    Vector2 GetPos();
    ~Enemy();
private:
    int hp;
    Vector2 position;



};


