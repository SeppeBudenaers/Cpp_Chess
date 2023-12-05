#include "bishop.h"
#include "gameboard.h"
#include "math.h"
#include <iostream>

bool Bishop::Diagonal(const int X, const int Y)
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
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking, GetColor())||(GetGameField()->AbleToAttack(Xchecking,Ychecking,GetColor() ) && !(Ychecking  == Y)))
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
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking,GetColor() )||(GetGameField()->AbleToAttack(Xchecking,Ychecking,GetColor() ) && !(Ychecking  == Y)))
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
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking,GetColor() )||(GetGameField()->AbleToAttack(Xchecking,Ychecking,GetColor() ) && !(Ychecking  == Y)))
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
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking,GetColor() )||(GetGameField()->AbleToAttack(Xchecking,Ychecking,GetColor() ) && !(Ychecking  == Y)))
                    {;
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

bool Bishop::CheckingValidMove(const int X,const int Y,const bool MovePiece)
{
    if(Diagonal(X,Y))
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


