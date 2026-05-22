//
// Created by jorga on 22/05/2026.
//

#include "Bullet.h"

#include <iostream>

#include "Player.h"

Bullet::Bullet(Vector2 playerPos) {
    position = {playerPos.x,playerPos.y};
    velocity = 10;
    damage = 100;
    body = {position.x,position.y-275,20,10};
}

void Bullet::Draw() {
    DrawRectangleRec(body,BLACK);
}

void Bullet::Update() {
    body.x+=velocity;
}

int Bullet::GetVelocity() {
    return velocity;
}

Rectangle Bullet::GetBody() {
    return body;
}

int Bullet::GetDamage() {
    return damage;
}

Bullet::~Bullet() {
}
