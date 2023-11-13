#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle, Texture2D run)
{
    worldPos = pos;
    idle_tex = idle;
    run_tex = run;
    width = idle.width/maxFrames;
    height = idle.height;
    speed = 3.f;
}

void Enemy::tick(float deltaTime)
{
    // Get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    BaseCharacter::tick(deltaTime);
};

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}