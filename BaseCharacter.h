#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
    public:
        BaseCharacter();
        virtual void tick(float deltaTime);
        Vector2 getWorldPos() { return worldPos; }
        void undoMovement() { worldPos = prevWorldPos; }
        Rectangle getCollisionRec();
    protected:
        Texture2D texture{LoadTexture("characters/goblin_idle_spritesheet.png")};
        Texture2D idle_tex{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run_tex{LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 prevWorldPos{};
        float rightLeft{1.f}; // +1 facing right, -1 facing left
        float runningTime{};
        float updateTime{1.f/16.f};
        int frame{};
        int maxFrames{6};
        float speed{4.f};
        float width{};
        float height{};
        float scale{4.f};
};

#endif