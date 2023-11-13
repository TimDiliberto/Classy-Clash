#include "BaseCharacter.h"
#include "Character.h"
#include "raylib.h"

class Enemy : public BaseCharacter
{
    public:
        Enemy(Vector2 pos, Texture2D idle, Texture2D run);
        virtual void tick(float deltaTime) override;
        void setTarget(Character* character) { target = character; }
        virtual Vector2 getScreenPos() override;
    private:
        Character* target;
        float damagePerSec{10.f};
        float radius{25.f};
};