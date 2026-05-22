//
// Created by jorga on 22/05/2026.
//

#pragma once
#include <iostream>
#include <vector>

#include "Bullet.h"
#include "raylib.h"
#include "Timer.h"


class Enemy {
public:
    Enemy();
    void Draw();
    void Update(std::vector<Bullet*> bullets,Timer timer);
    Vector2 GetPos();
    ~Enemy();
private:
    int hp;
    std::vector<Vector2> spawnPoints;
    Vector2 position;
    float width;
    float height;
    Rectangle body;



};


