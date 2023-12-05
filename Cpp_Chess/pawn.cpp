#include "pawn.h"
#include "gameboard.h"

bool Pawn::Attack(const Coordinates<uint8_t,uint8_t>& Input)
{
    if(GetColor())
    {
        if(((GetPosX() - Input.GetX() == -1)||(GetPosX() - Input.GetX() == 1))&&(GetPosY()-Input.GetY() == 1)&&GetGameField()->AbleToAttack(Input,GetColor()))
        {
            FirstMove = false;
            return true;
        }
    }
    else
    {
        if(((GetPosX() - Input.GetX() == -1)||(GetPosX() - Input.GetX() == 1))&&(GetPosY()-Input.GetY() == -1)&&GetGameField()->AbleToAttack(Input,GetColor()))
        {
            FirstMove = false;
            return true;
        }
    }
    return false;
}

bool Pawn::Forward(const Coordinates<uint8_t,uint8_t>& Input)
{
    if(GetColor())
    {
        if((GetPosX() - Input.GetX() == 0)&&((GetPosY()-Input.GetY() == 1)||((GetPosY()-Input.GetY() == 2)&&FirstMove))&&!GetGameField()->AbleToAttack(Input,GetColor())&&!GetGameField()->IsBlocked(Input,GetColor()))
        {
            FirstMove = false;
            return true;
        }
    }
    else
    {
        if((GetPosX() - Input.GetX() == 0)&&((GetPosY()-Input.GetY() == -1)||((GetPosY()-Input.GetY() == -2)&&FirstMove))&&!GetGameField()->AbleToAttack(Input,GetColor())&&!GetGameField()->IsBlocked(Input,GetColor()))
        {
            FirstMove = false;
            return true;
        }
    }
    return false;
}

bool Pawn::CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece)
{
    if(Forward(Input)||Attack(Input))
    {
        if(MovePiece)
        {
            SetPos(Input);
        }
        return true;
    }
    return false;
}

