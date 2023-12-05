#include "knight.h"
#include "gameboard.h"
#include "math.h"
bool Knight::Lmovement(const int X,const int Y)
{
    if(abs(GetPosX()-X) == 2 && abs(GetPosY()-Y) == 1&&!GetGameField()->IsBlocked(X,Y,GetColor()))
    {
        return true;
    }
    else if(abs(GetPosX()-X) == 1&& abs(GetPosY()-Y) == 2 &&!GetGameField()->IsBlocked(X,Y,GetColor()))
    {
        return true;
    }
    return false;
}

bool Knight::CheckingValidMove(const int X, const int Y, const bool MovePiece)
{
    if(Lmovement(X,Y))
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

