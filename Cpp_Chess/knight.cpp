#include "knight.h"
#include "gameboard.h"
#include "math.h"
bool Knight::Move(int X, int Y)
{
    if(abs(GetPosX()-X) == 2 && abs(GetPosY()-Y) == 1&&!GetGameField()->IsBlocked(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        return true;
    }
    else if(abs(GetPosX()-X) == 1&& abs(GetPosY()-Y) == 2 &&!GetGameField()->IsBlocked(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        return true;
    }
    return false;
}
