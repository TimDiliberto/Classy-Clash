/*

*/
#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
    // Initialize window dimensions
    const float winDims[] {384, 384};
    InitWindow(winDims[0], winDims[1], "Classy Clash");

    // Set background image and position
    Texture2D map =
        LoadTexture("nature_tileset/(32x32) ClassyClash_worldMap.png");
    Vector2 mapPos{0.f, 0.f};
    const  float mapScale = 2.f;

    // Initialize character
    Character knight(winDims[0], winDims[1]);

    // Initialize props
    Prop rock{ Vector2{0.f, 0.f}, LoadTexture("nature_tileset/Rock.png") };

    // Set ideal FPS and begin game loop
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Build window
        BeginDrawing();
        ClearBackground(BLACK);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw Textures
        DrawTextureEx(map, mapPos, 0.f, mapScale, WHITE);

        rock.Render(knight.getWorldPos());

        // Update character data
        knight.tick(GetFrameTime());
        // Check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + winDims[0] > map.width * mapScale ||
            knight.getWorldPos().y + winDims[1] > map.height * mapScale)
        { knight.undoMovement(); }

        // Deconstruct window
        EndDrawing();
    }
    
    // Unload textures and close window
    UnloadTexture(map);
    CloseWindow();
}