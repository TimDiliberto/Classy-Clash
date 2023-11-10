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

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        winDims[0]/2.f - 4.f * (0.5f * (float)knight.width/6.0),
        winDims[1]/2.f - 4.f * (0.5f * (float)knight.height)
    };

    // Set ideal FPS and begin game loop
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Build window
        BeginDrawing();
        ClearBackground(BLACK);

        // Check for movement
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            Vector2 dirNorm{Vector2Normalize(direction)};
            mapPos = Vector2Subtract(mapPos, Vector2Scale(dirNorm, speed));
        }

        // Draw Textures
        DrawTextureEx(map, mapPos, 0.f, 2.f, WHITE);
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.f * (float)knight.width/6.f, 4.f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        // Deconstruct window
        EndDrawing();
    }
    
    // Unload textures and close window
    UnloadTexture(map);
    CloseWindow();
}