#include "pawn.h"
#include "gameboard.h"

bool Pawn::Attack(int X, int Y)
{
    if(GetColor())
    {
        if(((GetPosX() - X == -1)||(GetPosX() - X == 1))&&(GetPosY()-Y == 1)&&GetGameField()->AbleToAttack(X,Y))
        {
            SetPosX(X);
            SetPosY(Y);
            FirstMove = false;
            return true;
        }
    }
    else
    {
        if(((GetPosX() - X == -1)||(GetPosX() - X == 1))&&(GetPosY()-Y == -1)&&GetGameField()->AbleToAttack(X,Y))
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
    cout<<"debug"<<GetPosX() - X<<GetPosY()-Y;
    if(GetColor())
    {
        if((GetPosX() - X == 0)&&((GetPosY()-Y == 1)||((GetPosY()-Y == 2)&&FirstMove))&&!GetGameField()->AbleToAttack(X,Y)&&!GetGameField()->IsBlocked(X,Y))
        {
            FirstMove = false;
            return true;
        }
    }
    else
    {
        if((GetPosX() - X == 0)&&((GetPosY()-Y == -1)||((GetPosY()-Y == -2)&&FirstMove))&&!GetGameField()->AbleToAttack(X,Y)&&!GetGameField()->IsBlocked(X,Y))
        {
            cout<<"debug";
            FirstMove = false;
            return true;
        }
    }
    return false;
}

bool Pawn::Move(int X, int Y)
{
    if(Forward(X,Y)||Attack(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        cout<<"debug"<<GetPosX()<<GetPosY();
        return true;
    }
    else{return false;}
}

