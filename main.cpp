/*

*/
#include "raylib.h"
#include "raymath.h"

int main()
{
    // Initialize window dimensions
    const int winDims[] {384, 384};
    InitWindow(winDims[0], winDims[1], "Classy Clash");

    // Set background image and position
    Texture2D map =
        LoadTexture("nature_tileset/(32x32) ClassyClash_worldMap.png");
    Vector2 mapPos{0.0, 0.0};

    float speed{4.0};

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
        DrawTextureEx(map, mapPos, 0.0, 2.0, WHITE);

        // Deconstruct window
        EndDrawing();
    }
    
    // Unload textures and close window
    UnloadTexture(map);
    CloseWindow();
}