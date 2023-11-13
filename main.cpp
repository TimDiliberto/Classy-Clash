/*

*/
#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Enemy.h"
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

    Enemy goblin(
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    );
    goblin.setTarget(&knight);

    Prop props[2]{
        Prop{Vector2{150.f, 400.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Log.png")}
    };

    // Set ideal FPS and begin game loop
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Build window
        BeginDrawing();
        ClearBackground(BLACK);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw Textures
        DrawTextureEx(map, mapPos, 0.f, mapScale, WHITE);

        for (auto prop : props) { prop.Render(knight.getWorldPos()); }

        // Update character data
        knight.tick(GetFrameTime());
        // Check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + winDims[0] > map.width * mapScale ||
            knight.getWorldPos().y + winDims[1] > map.height * mapScale)
        { knight.undoMovement(); }

        // Check for player collision with props
        // Figure out how to make player glide alongside prop and not get stuck
        for (auto prop : props) {
            bool collision{
                CheckCollisionRecs(
                    knight.getCollisionRec(), 
                    prop.getCollisionRec(knight.getWorldPos()))
            };
            if (collision) { knight.undoMovement(); }
        }

        goblin.tick(GetFrameTime());

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionRecs(
                goblin.getCollisionRec(),
                knight.getWeaponCollisionRec())) { goblin.setAlive(false); }
        }

        // Deconstruct window
        EndDrawing();
    }
    
    // Unload textures and close window
    UnloadTexture(map);
    CloseWindow();
}