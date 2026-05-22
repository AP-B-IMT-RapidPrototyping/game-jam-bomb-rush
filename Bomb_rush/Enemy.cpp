//
// Created by jorga on 22/05/2026.
//

#include "Enemy.h"

#include "Bullet.h"
#include "Timer.h"


Enemy::Enemy() {
    hp = 100;
    position = {510,250};
    width = 20;
    height = 40;
    body = {position.x,position.y,width,height};
}

void Enemy::Draw() {
    DrawRectangleRec(body,RED);
}

void Enemy::Update(std::vector<Bullet*> bullets,Timer timer) {
    for (int i=0;i<bullets.size();i++){
        if (CheckCollisionRecs(bullets[i]->GetBody(),body)) {
            if (hp>0) {
                std::cout << "yo";
                hp-=bullets[i]->GetDamage();
            }
            else{
                std::cout << "dead";
                width = 0;
                height = 0;
                
            }
        }
    }
}

Vector2 Enemy::GetPos() {
    return position;
}

Enemy::~Enemy() {

}
