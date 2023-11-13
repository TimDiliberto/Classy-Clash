#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}