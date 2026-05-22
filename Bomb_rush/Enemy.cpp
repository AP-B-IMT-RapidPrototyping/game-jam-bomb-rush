//
// Created by jorga on 22/05/2026.
//

#include "Enemy.h"

#include "Bullet.h"


Enemy::Enemy() {
    hp = 100;
    position = {200,200};
    width = 100;
    height = 100;
}

void Enemy::Draw() {
    DrawRectangle(position.x,position.y,width,height,RED);
}

void Enemy::Update(bool isColliding, Bullet bullet) {
    if (bullet.GetPos().x >= position.x && bullet.GetPos().x <= position.x+width && bullet.GetPos().y >= position.y && bullet.GetPos().y <= position.y+height) {
        isColliding = true;
    }
    isColliding = false;
    if (isColliding) {
        std::cout << "yooo";
    }
}

Vector2 Enemy::GetPos() {
    return position;
}

Enemy::~Enemy() {

}
