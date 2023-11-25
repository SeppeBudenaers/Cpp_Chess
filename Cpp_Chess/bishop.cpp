#include "bishop.h"
#include "gameboard.h"
#include "math.h"
#include <iostream>
bool Bishop::Move(int X, int Y)
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
                    std::cout<<"debug : "<< Xchecking <<" "<<Ychecking<<std::endl;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking )||(GetGameField()->AbleToAttack(Xchecking,Ychecking ) && !(Ychecking  == Y)))
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
                    std::cout<<"debug : "<< Xchecking <<" "<<Ychecking<<std::endl;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking )||(GetGameField()->AbleToAttack(Xchecking,Ychecking ) && !(Ychecking  == Y)))
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
                    std::cout<<"debug : "<< Xchecking <<" "<<Ychecking<<std::endl;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking )||(GetGameField()->AbleToAttack(Xchecking,Ychecking ) && !(Ychecking  == Y)))
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
                    std::cout<<"debug : "<< Xchecking <<" "<<Ychecking<<std::endl;
                    if(GetGameField()->IsBlocked(Xchecking,Ychecking )||(GetGameField()->AbleToAttack(Xchecking,Ychecking ) && !(Ychecking  == Y)))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
        }
        SetPosX(X);
        SetPosY(Y);
        return ValidMove;
    }
    return false;
}
