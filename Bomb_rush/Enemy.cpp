//
// Created by jorga on 22/05/2026.
//

#include "Enemy.h"

#include "Bullet.h"


Enemy::Enemy() {
    hp = 100;
    position = {500,250};
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
            hp-=100;
        }
        else{
            std::cout << "dede";
            
        }
    }
}

Vector2 Enemy::GetPos() {
    return position;
}

Enemy::~Enemy() {

}
