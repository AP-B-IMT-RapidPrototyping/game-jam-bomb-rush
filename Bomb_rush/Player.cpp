//
// Created by jorga on 22/05/2026.
//

#include "Player.h"
#include "Bullet.h"

Player::Player() {
    position = {385, 550};
    speed = 0;
    canJump = false;
    playerRect = {position.x - 15, position.y -50, 30, 50};
}

void Player::Update(Map *envItems, int envItemsLength, float delta) {
    if (IsKeyDown(KEY_A)) {
        position.x -= 250 * delta;
        lookingLeft = true;
    }
    if (IsKeyDown(KEY_D)) {
        position.x += 250 * delta;
        lookingLeft = false;
    }
    if (IsKeyPressed(KEY_SPACE) && canJump) {
        speed = -500;
        canJump = false;
    }

    bool hitObstacle = false;
    for (int i = 0; i < envItemsLength; i++) {
        Map *ei = envItems + i;
        Vector2 *p = &position;
        if (ei->blocking &&
            ei->rect.x <= p->x &&
            ei->rect.x+ei->rect.width >= p->x &&
            ei->rect.y >= p->y &&
            ei->rect.y <= p->y + speed*delta)
        {
            hitObstacle = true;
            speed = 0;
            p->y = ei->rect.y;
        }
    }

    if (!hitObstacle) {
        position.y += speed*delta;
        speed += 750*delta;
        canJump = false;
    }
    else {
        canJump = true;
    }
}

Vector2 Player::GetPos() {
    return position;
}

