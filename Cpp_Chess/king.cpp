#include "king.h"
#include "math.h"
#include "gameboard.h"
#include <iostream>
bool King::Moveset(int X, int Y)
{
    if((abs(GetPosX()-X)<=1)&&(abs(GetPosY()-Y)<=1)&&!GetGameField()->IsBlocked(X,Y,GetColor()))
    {
        return true;
    }
    return false;
}

bool King::CheckingValidMove(int X, int Y, bool MovePiece)
{
    if(Moveset(X,Y))
    {
        if(MovePiece)
        {
            SetPosX(X);
            SetPosY(Y);
        }
        return true;
    }
    return false;
}
