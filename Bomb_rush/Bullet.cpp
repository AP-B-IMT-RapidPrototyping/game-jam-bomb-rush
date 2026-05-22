//
// Created by jorga on 22/05/2026.
//

#include "Bullet.h"

Bullet::Bullet() {
    position = {100,100};
    velocity = {10,0};
}

void Bullet::Draw() {
    DrawRectangle(position.x,position.y,20,10,BLACK);
}

void Bullet::Update() {
    position.x+=velocity.x;
}
