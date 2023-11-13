#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::tick(float deltaTime)
{
    // Collect previous world position
    prevWorldPos = worldPos;
    // Update animation
    runningTime += deltaTime;
    if (runningTime >= updateTime) {
        runningTime = 0.f;
        frame++;
        if (frame >= maxFrames) frame = 0;
    }

    if (Vector2Length(velocity) != 0.0) {
        Vector2 normal {Vector2Normalize(velocity)};
        worldPos = Vector2Add(worldPos, Vector2Scale(normal , speed));
        //direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        if (velocity.x < 0.f) rightLeft = -1.f;
        if (velocity.x > 0.f) rightLeft = 1.f;
    }
    texture = velocity.x || velocity.y != 0.f ? run_tex : idle_tex;
    velocity = {};

    // Draw character
    Rectangle source{ frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{ getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(
        texture,
        source,
        dest,
        Vector2{},
        0.f, WHITE
    );
};

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}