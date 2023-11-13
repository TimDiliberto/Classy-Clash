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
    if (!getAlive()) return;
    
    // Get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if (Vector2Length(velocity) < radius) velocity = {};

    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
        { target->takeDamage(damagePerSec*deltaTime); }
};

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}