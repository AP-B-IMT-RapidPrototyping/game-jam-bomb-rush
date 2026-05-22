//
// Created by jorga on 22/05/2026.
//

#include "Enemy.h"



Enemy::Enemy() {
    hp = 100;
    position = {20,20};
}

void Enemy::Draw() {
    DrawRectangle(position.x,position.y,100,100,BLUE);
}
