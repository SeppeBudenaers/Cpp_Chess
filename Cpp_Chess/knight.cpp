#include "knight.h"
#include "gameboard.h"
#include "math.h"
bool Knight::Lmovement(const Coordinates<uint8_t,uint8_t>& Input)
{
    if(abs(GetPosX()-Input.GetX()) == 2 && abs(GetPosY()-Input.GetY()) == 1&&!GetGameField()->IsBlocked(Input,GetColor()))
    {
        return true;
    }
    else if(abs(GetPosX()-Input.GetX()) == 1&& abs(GetPosY()-Input.GetY()) == 2 &&!GetGameField()->IsBlocked(Input,GetColor()))
    {
        return true;
    }
    return false;
}

bool Knight::CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input, const bool MovePiece)
{
    if(Lmovement(Input))
    {
        if(MovePiece)
        {
            SetFirstMove();
            SetPos(Input);
        }
        return true;
    }
    return false;
}

