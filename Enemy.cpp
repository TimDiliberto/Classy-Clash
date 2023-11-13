#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle, Texture2D run)
{
        worldPos = pos;
        idle = idle;
        run = run;
    width = idle.width/maxFrames;
    height = idle.height;
}

void Enemy::tick(float deltaTime)
{
    prevWorldPos = worldPos;

    // Update animation
    runningTime += deltaTime;
    if (runningTime >= updateTime) {
        runningTime = 0.f;
        frame++;
        if (frame >= maxFrames) frame = 0;
    }

    // Draw character
    Rectangle source{ frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{ screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(
        idle,
        source,
        dest,
        Vector2{},
        0.f, WHITE
    );
};