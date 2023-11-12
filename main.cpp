/*

*/
#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    // Initialize window dimensions
    const float winDims[] {384, 384};
    InitWindow(winDims[0], winDims[1], "Classy Clash");

    // Set background image and position
    Texture2D map =
        LoadTexture("nature_tileset/(32x32) ClassyClash_worldMap.png");
    Vector2 mapPos{0.f, 0.f};

    // Initialize character
    Character knight;
    knight.setScreenPos(winDims[0], winDims[1]);

    // Set ideal FPS and begin game loop
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Build window
        BeginDrawing();
        ClearBackground(BLACK);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw Textures
        DrawTextureEx(map, mapPos, 0.f, 2.f, WHITE);

        // Update character data
        knight.tick(GetFrameTime());

        // Deconstruct window
        EndDrawing();
    }
    
    // Unload textures and close window
    UnloadTexture(map);
    CloseWindow();
}