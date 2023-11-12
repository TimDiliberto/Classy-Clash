#include "raylib.h"

class Character
{
    public:
        Character();
        Vector2 getWorldPos() { return worldPos; }
        void setScreenPos(int winWidth, int winHeight);
        void tick(float deltaTime);
    private:
        Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        float rightLeft{1.f}; // +1 facing right, -1 facing left
        float runningTime{};
        float updateTime{1.f/16.f};
        int frame{};
        int maxFrames{6};
        float speed{4.f};
        float width{};
        float height{};
};