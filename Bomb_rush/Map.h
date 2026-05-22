//
// Created by jorga on 22/05/2026.
//
#pragma once
#include "raylib.h"


class Map {
    Vector2 position;

public:
    Map();
    void Draw();
    void Update();
    ~Map();
};