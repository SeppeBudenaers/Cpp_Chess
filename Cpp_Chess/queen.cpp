#include "queen.h"
#include "gameboard.h"

bool Queen::UpAndDown(const int X, const int Y)
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

bool Queen::LeftAndRight(const int X, const int Y)
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

bool Queen::Diagonal(const int X, const int Y)
{
    bool ValidMove = true;
    if((abs(GetPosX()-X) == abs(GetPosY()-Y)) && ((GetPosX()-X) != 0))
    {
        if((GetPosY()-Y)<0) //Up
        {
            if((GetPosX()-X)<0)//Right
            {
                for (int I = 1 ; I <= abs(GetPosY()-Y); ++I) {
                    int Xchecking = GetPosX() + I;
                    int Ychecking = GetPosY() + I;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking ,GetColor())||(GetGameField()->AbleToAttack(Xchecking,Ychecking ,GetColor()) && !(Ychecking  == Y)))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
            else if((GetPosX()-X)>0) //Left
            {
                for (int I = 1 ; I <= abs(GetPosY()-Y); ++I) {
                    int Xchecking = GetPosX() - I;
                    int Ychecking = GetPosY() + I;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking ,GetColor())||(GetGameField()->AbleToAttack(Xchecking,Ychecking ,GetColor()) && !(Ychecking  == Y)))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
        }
        else if((GetPosY()-Y)>0)//Down
        {
            if((GetPosX()-X)<0)//Right
            {
                for (int I = 1 ; I <= abs(GetPosY()-Y); ++I) {
                    int Xchecking = GetPosX() + I;
                    int Ychecking = GetPosY() - I;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking ,GetColor())||(GetGameField()->AbleToAttack(Xchecking,Ychecking ,GetColor()) && !(Ychecking  == Y)))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
            else if((GetPosX()-X)>0)//Left
            {
                for (int I = 1 ; I <= abs(GetPosY()-Y); ++I) {
                    int Xchecking = GetPosX() - I;
                    int Ychecking = GetPosY() - I;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking ,GetColor())||(GetGameField()->AbleToAttack(Xchecking,Ychecking ,GetColor()) && !(Ychecking  == Y)))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
        }
        return ValidMove;
    }
    return false;
}

bool Queen::CheckingValidMove(const int X, const int Y, const bool MovePiece)
{
    if(LeftAndRight(X,Y)||UpAndDown(X,Y)||Diagonal(X,Y))
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

