#ifndef CHARACTER_H
#define CHARACTER_H

#include "BaseCharacter.h"
#include "raylib.h"

class Character : public BaseCharacter
{
    public:
        Character(int winWidth, int winHeight);
        virtual void tick(float deltaTime) override;
    private:
};

#endif