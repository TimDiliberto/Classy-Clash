/*

*/
#include "raylib.h"
#include "raymath.h"

int main()
{
    // Initialize window dimensions
    const float winDims[] {384, 384};
    InitWindow(winDims[0], winDims[1], "Classy Clash");

    // Set background image and position
    Texture2D map =
        LoadTexture("nature_tileset/(32x32) ClassyClash_worldMap.png");
    Vector2 mapPos{0.0, 0.0};
    // Movement speed
    float speed{4.0};

    Texture2D knightIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightRun = LoadTexture("characters/knight_run_spritesheet.png");
    Vector2 knightPos {
        winDims[0]/2.f - 4.f * (0.5f * (float)knightIdle.width/6.f),
        winDims[1]/2.f - 4.f * (0.5f * (float)knightIdle.height)
    };
    // Animation variables
    float rightLeft{1.f}; // +1 facing right, -1 facing left
    float runningTime{};
    float updateTime{1.0/16.0};
    int frame{};
    const int maxFrames{6};

    // Set ideal FPS and begin game loop
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Build window
        BeginDrawing();
        ClearBackground(BLACK);

        // Check for movement
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0) {
            Vector2 dirNorm{Vector2Normalize(direction)};
            mapPos = Vector2Subtract(mapPos, Vector2Scale(dirNorm, speed));
            //direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            if (direction.x < 0.f) rightLeft = -1.f;
            if (direction.x > 0.f) rightLeft = 1.f;
        }

        // Update animation
        runningTime += GetFrameTime();
        if (runningTime >= updateTime) {
            runningTime = 0.f;
            frame++;
            if (frame >= maxFrames) frame = 0;
        }

        // Draw Textures
        DrawTextureEx(map, mapPos, 0.f, 2.f, WHITE);
        Rectangle source{
            frame * (float)knightIdle.width/6.f,
            0.f,
            rightLeft * (float)knightIdle.width/6.f,
            (float)knightIdle.height};
        Rectangle dest{
            knightPos.x,
            knightPos.y,
            4.f * (float)knightIdle.width/6.f,
            4.f * (float)knightIdle.height};
        DrawTexturePro(
            direction.x || direction.y != 0.f ? knightRun : knightIdle,
            source,
            dest,
            Vector2{},
            0.f, WHITE
        );

        // Deconstruct window
        EndDrawing();
    }
    
    // Unload textures and close window
    UnloadTexture(map);
    CloseWindow();
}