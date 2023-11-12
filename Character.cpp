#include "raylib.h"
#include "raymath.h"
#include "Character.h"

Character::Character()
{
    width = idle.width/maxFrames;
    height = idle.height;
}

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        winWidth/2.f - 4.f * (0.5f * width),
        winHeight/2.f - 4.f * (0.5f * height)
    };
}

void Character::tick(float deltaTime)
{
    // Collect previous world position
    prevWorldPos = worldPos;
    // Check for movement
    Vector2 direction{};
    if (IsKeyDown(KEY_A)) direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) direction.x += 1.0;
    if (IsKeyDown(KEY_W)) direction.y -= 1.0;
    if (IsKeyDown(KEY_S)) direction.y += 1.0;
    if (Vector2Length(direction) != 0.0) {
        Vector2 normal {Vector2Normalize(direction)};
        worldPos = Vector2Add(worldPos, Vector2Scale(normal , speed));
        //direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        if (direction.x < 0.f) rightLeft = -1.f;
        if (direction.x > 0.f) rightLeft = 1.f;
    }

    // Update animation
    runningTime += deltaTime;
    if (runningTime >= updateTime) {
        runningTime = 0.f;
        frame++;
        if (frame >= maxFrames) frame = 0;
    }

    // Draw character
    Rectangle source{ frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{ screenPos.x, screenPos.y, 4.f * width, 4.f * height};
    DrawTexturePro(
        direction.x || direction.y != 0.f ? run : idle,
        source,
        dest,
        Vector2{},
        0.f, WHITE
    );
}