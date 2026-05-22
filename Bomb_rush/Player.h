//
// Created by jorga on 22/05/2026.
//

#pragma once
#include "raylib.h"

class Player {
    Vector2 position = {385, 500};
    Vector2 size = {30, 50};

public:
    void Draw();
    void Update();
    Vector2 GetPos();
    void Shoot();
};


