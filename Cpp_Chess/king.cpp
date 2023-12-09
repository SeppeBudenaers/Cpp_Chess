#include "king.h"
#include "math.h"
#include "gameboard.h"
#include <iostream>
bool King::Moveset(const Coordinates<uint8_t,uint8_t>& Input)
{
    if((abs(GetPosX()-Input.GetX())<=1)&&(abs(GetPosY()-Input.GetY())<=1)&&!GetGameField()->IsBlocked(Input,GetColor()))
    {
        return true;
    }
    return false;
}

bool King::CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece)
{
    if(Moveset(Input))
    {
        if(MovePiece)
        {
            if(!GetFirstMove()){SetSecondMove();}
            SetFirstMove();
            SetPos(Input);
        }
        return true;
    }
    return false;
}
