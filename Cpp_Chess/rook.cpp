#include "rook.h"
#include "gameboard.h"

bool Rook::UpAndDown(int X, int Y)
{
    bool ValidMove = true;
    if((X-GetPosX()) == 0)
    {
        if(Y < GetPosY())
        {
            for (int I = GetPosY()-1 ; I >= Y; --I) {
                if(GetGameField()->IsBlocked(X,I)||(GetGameField()->AbleToAttack(X,I) && !(I == Y)))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        else
        {
            for (int I = GetPosY()+1 ; I <= Y; ++I) {
                if(GetGameField()->IsBlocked(X,I)||(GetGameField()->AbleToAttack(X,I) && !(I == Y)))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        return ValidMove;
    }
    return false;
}

bool Rook::LeftAndRight(int X, int Y)
{
    bool ValidMove = true;
    if((Y-GetPosY()) == 0)
    {
        if(X < GetPosX())
        {
            for (int I = GetPosX()-1 ; I >= X; --I) {
                if(GetGameField()->IsBlocked(I,Y)||(GetGameField()->AbleToAttack(I,Y) && !(I == X)))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        else
        {
            for (int I = GetPosX()+1 ; I <= X; ++I) {
                if(GetGameField()->IsBlocked(I,Y)||(GetGameField()->AbleToAttack(I,Y) && !(I == X)))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        return ValidMove;
    }
    return false;
}

bool Rook::Move(int X, int Y)
{
    if(LeftAndRight(X,Y)||UpAndDown(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        return true;
    }
    return false;
}
