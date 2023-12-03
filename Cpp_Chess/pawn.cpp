#include "pawn.h"
#include "gameboard.h"

bool Pawn::Attack(int X, int Y)
{
    if(GetColor())
    {
        if(((GetPosX() - X == -1)||(GetPosX() - X == 1))&&(GetPosY()-Y == 1)&&GetGameField()->AbleToAttack(X,Y,GetColor()))
        {
            SetPosX(X);
            SetPosY(Y);
            FirstMove = false;
            return true;
        }
    }
    else
    {
        if(((GetPosX() - X == -1)||(GetPosX() - X == 1))&&(GetPosY()-Y == -1)&&GetGameField()->AbleToAttack(X,Y,GetColor()))
        {
            SetPosX(X);
            SetPosY(Y);
            FirstMove = false;
            return true;
        }
    }
    return false;
}

bool Pawn::Forward(int X, int Y)
{
    if(GetColor())
    {
        if((GetPosX() - X == 0)&&((GetPosY()-Y == 1)||((GetPosY()-Y == 2)&&FirstMove))&&!GetGameField()->AbleToAttack(X,Y,GetColor())&&!GetGameField()->IsBlocked(X,Y,GetColor()))
        {
            FirstMove = false;
            return true;
        }
    }
    else
    {
        if((GetPosX() - X == 0)&&((GetPosY()-Y == -1)||((GetPosY()-Y == -2)&&FirstMove))&&!GetGameField()->AbleToAttack(X,Y,GetColor())&&!GetGameField()->IsBlocked(X,Y,GetColor()))
        {
            FirstMove = false;
            return true;
        }
    }
    return false;
}

bool Pawn::CheckingValidMove(int X, int Y, bool MovePiece)
{
    if(Forward(X,Y)||Attack(X,Y))
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

