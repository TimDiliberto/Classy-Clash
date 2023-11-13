#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle, Texture2D run)
{
    worldPos = pos;
    idle_tex = idle;
    run_tex = run;
    width = idle.width/maxFrames;
    height = idle.height;
}

void Enemy::tick(float deltaTime)
{
    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    BaseCharacter::tick(deltaTime);
};