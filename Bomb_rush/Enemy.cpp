//
// Created by jorga on 22/05/2026.
//

#include "Enemy.h"

#include "Bullet.h"


Enemy::Enemy() {
    hp = 100;
    position = {200,200};
    width = 20;
    height = 40;
    body = {position.x,position.y,width,height};
}

void Enemy::Draw() {
    DrawRectangleRec(body,RED);
}

void Enemy::Update(Bullet bullet) {
    if (CheckCollisionRecs(bullet.GetBody(),body)) {
        std::cout << "yooo";
        if (hp>0) {
            bullet.GetDamage()-hp;
        }
    }
    if (hp<=0) {
        delete this;
    }
}

Vector2 Enemy::GetPos() {
    return position;
}

Enemy::~Enemy() {
    delete this;
}
