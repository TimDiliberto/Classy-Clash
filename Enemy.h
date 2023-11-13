#include "BaseCharacter.h"
#include "raylib.h"

class Enemy : public BaseCharacter
{
    public:
        Enemy(Vector2 pos, Texture2D idle, Texture2D run);
        virtual void tick(float deltaTime) override;
    private:
};