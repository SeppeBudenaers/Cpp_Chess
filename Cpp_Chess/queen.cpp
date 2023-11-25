#include "queen.h"
#include "gameboard.h"

bool Queen::UpAndDown(int X, int Y)
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

bool Queen::LeftAndRight(int X, int Y)
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

bool Queen::Diagonal(int X, int Y)
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
        return ValidMove;
    }
    return false;
}

bool Queen::Move(int X, int Y)
{
    if(LeftAndRight(X,Y)||UpAndDown(X,Y)||Diagonal(X,Y))
    {
        SetPosX(X);
        SetPosY(Y);
        return true;
    }
    return false;
}

