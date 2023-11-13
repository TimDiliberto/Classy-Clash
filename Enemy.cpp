#include "Enemy.h"

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
    BaseCharacter::tick(deltaTime);
};