#include "king.h"
#include "math.h"
#include "gameboard.h"
#include <iostream>
bool King::Move(int X, int Y)
{
    std::cout<<"Debug : "<<abs(GetPosX()-X) <<" "<<abs(GetPosY()-Y)<<" "<<GetGameField()->IsBlocked(X,Y)<<endl;
    if((abs(GetPosX()-X)<=1)&&(abs(GetPosY()-Y)<=1)&&!GetGameField()->IsBlocked(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        return true;
    }
    return false;
}
//&&!((GetPosX() == X)&&(GetPosY() == Y))
