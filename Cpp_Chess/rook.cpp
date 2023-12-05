#include "rook.h"
#include "gameboard.h"

bool Rook::UpAndDown(const int X, const int Y)
{
    bool ValidMove = true;
    if((X-GetPosX()) == 0)
    {
        if(Y < GetPosY())
        {
            for (int I = GetPosY()-1 ; I >= Y; --I) {
                if(GetGameField()->IsBlocked(X,I,GetColor())||(GetGameField()->AbleToAttack(X,I,GetColor()) && !(I == Y)))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        else
        {
            for (int I = GetPosY()+1 ; I <= Y; ++I) {
                if(GetGameField()->IsBlocked(X,I,GetColor())||(GetGameField()->AbleToAttack(X,I,GetColor()) && !(I == Y)))
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

bool Rook::LeftAndRight(const int X, const int Y)
{
    bool ValidMove = true;
    if((Y-GetPosY()) == 0)
    {
        if(X < GetPosX())
        {
            for (int I = GetPosX()-1 ; I >= X; --I) {
                if(GetGameField()->IsBlocked(I,Y,GetColor())||(GetGameField()->AbleToAttack(I,Y,GetColor()) && !(I == X)))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        else
        {
            for (int I = GetPosX()+1 ; I <= X; ++I) {
                if(GetGameField()->IsBlocked(I,Y,GetColor())||(GetGameField()->AbleToAttack(I,Y,GetColor()) && !(I == X)))
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

bool Rook::CheckingValidMove(const int X, const int Y, const bool MovePiece)
{
    if(LeftAndRight(X,Y)||UpAndDown(X,Y))
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
