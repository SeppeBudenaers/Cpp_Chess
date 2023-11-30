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

bool King::Move(int X, int Y)
{
    if(Moveset(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        return true;
    }
    return false;
}

bool King::CheckingValidMove(int X, int Y)
{
    if(Moveset(X,Y))
    {
        return true;
    }
    return false;
}
