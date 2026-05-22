//
// Created by jorga on 22/05/2026.
//

#include "Player.h"

void Player::Draw() {
    DrawRectangle(position.x, position.y, size.x, size.y, BLUE);
}

void Player::Update() {
}

Vector2 Player::GetPos() {
    return this->position;
}
