#include "BaseCharacter.h"

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

    // Draw character
    Rectangle source{ frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{ screenPos.x, screenPos.y, scale * width, scale * height};
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
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}