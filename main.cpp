/*

*/
#include "raylib.h"
#include "raymath.h"

class Character
{
    public:
        Vector2 getWorldPos() { return worldPos; }
        void setScreenPos(int winWidth, int winHeight);
        void tick(float deltaTime);
    private:
        //Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        float rightLeft{1.f}; // +1 facing right, -1 facing left
        float runningTime{};
        const float updateTime{1.f/16.f};
        int frame{};
        const int maxFrames{6};
        const float speed{4.f};
};

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        winWidth/2.f - 4.f * (0.5f * (float)idle.width/6.f),
        winHeight/2.f - 4.f * (0.5f * (float)idle.height)
    };
}

void Character::tick(float deltaTime)
{
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
    Rectangle source{
        frame * (float)idle.width/6.f,
        0.f,
        rightLeft * (float)idle.width/6.f,
        (float)idle.height};
    Rectangle dest{
        screenPos.x,
        screenPos.y,
        4.f * (float)idle.width/6.f,
        4.f * (float)idle.height};
    DrawTexturePro(
        direction.x || direction.y != 0.f ? run : idle,
        source,
        dest,
        Vector2{},
        0.f, WHITE
    );
}

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