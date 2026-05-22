//
// Created by jorga on 22/05/2026.
//

#include "Bullet.h"

#include "Player.h"

Bullet::Bullet(Vector2 playerPos) {
    position = {playerPos.x,playerPos.y};
    velocity = 10;
}

void Bullet::Draw() {
    DrawRectangle(position.x,position.y,20,10,BLACK);

}

void Bullet::Update() {
    position.x+=velocity;
}

Vector2 Bullet::GetPos() {
    return position;
}


Bullet::~Bullet() {
}
