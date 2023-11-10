/*

*/
#include "raylib.h"

int main()
{
    // Initialize window dimensions
    const int winDims[] {384, 384};
    InitWindow(winDims[0], winDims[1], "Classy Clash");

    // Set background image
    Texture2D map =
        LoadTexture("nature_tileset/(32x32) ClassyClash_worldMap.png");
    Vector2 mapPos{0.0, 0.0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Setup window data
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextureEx(map, mapPos, 0.0, 2.0, WHITE);

        EndDrawing();
    }
    
    UnloadTexture(map);
}