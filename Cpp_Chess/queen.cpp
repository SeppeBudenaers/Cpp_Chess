#include "queen.h"
#include "gameboard.h"

bool Queen::UpAndDown(const Coordinates<uint8_t,uint8_t>& Input)
{
    Coordinates<uint8_t,uint8_t> Temp;
    Temp.setX(Input.GetX());
    bool ValidMove = true;
    if((Input.GetX()-GetPosX()) == 0)
    {
        if(Input.GetY() < GetPosY())
        {
            for (int I = GetPosY()-1 ; I >= Input.GetY(); --I) {
                Temp.setY(I);
                if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp,GetColor()) && !(Temp.GetY() == Input.GetY())))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        else
        {
            for (int I = GetPosY()+1 ; I <= Input.GetY(); ++I) {
                Temp.setY(I);
                if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp,GetColor()) && !(Temp.GetY() == Input.GetY())))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        if(ValidMove){cout<<"Debug Leftright"<<endl;}
        return ValidMove;
    }
    return false;
}

bool Queen::LeftAndRight(const Coordinates<uint8_t,uint8_t>& Input)
{
    Coordinates<uint8_t,uint8_t> Temp;
    Temp.setY(Input.GetY());
    bool ValidMove = true;
    if((Input.GetY()-GetPosY()) == 0)
    {
        if(Input.GetX() < GetPosX())
        {
            for (int I = GetPosX()-1 ; I >= Input.GetX() ; --I) {
                Temp.setX(I);
                if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp,GetColor()) && !(Temp.GetX() == Input.GetY())))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        else
        {
            for (int I = GetPosX()+1 ; I <= Input.GetX(); ++I) {
                Temp.setX(I);
                if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp,GetColor()) && !(Temp.GetX() == Input.GetY())))
                {
                    ValidMove = false;
                    break;
                }
            }
        }
        if(ValidMove){cout<<"Debug Leftright"<<endl;}
        return ValidMove;
    }
    return false;
}

bool Queen::Diagonal(const Coordinates<uint8_t,uint8_t>& Input)
{
    Coordinates<uint8_t,uint8_t> Temp;
    bool ValidMove = true;
    if((abs(GetPosX()-Input.GetX()) == abs(GetPosY()-Input.GetY())) && ((GetPosX()-Input.GetX()) != 0))
    {
        if((GetPosY()-Input.GetY())<0) //Up
        {
            if((GetPosX()-Input.GetX())<0)//Right
            {
                for (int I = 1 ; I <= abs(GetPosY()-Input.GetY()); ++I) {
                    Temp.setX(GetPosX() + I);
                    Temp.setY(GetPosY() + I);
                    if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp ,GetColor()) && !(Temp.GetX() == Input.GetY())))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
            else if((GetPosX()-Input.GetX())>0) //Left
            {
                for (int I = 1 ; I <= abs(GetPosY()-Input.GetY()); ++I) {
                    Temp.setX(GetPosX() - I);
                    Temp.setY(GetPosY() + I);
                    if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp ,GetColor()) && !(Temp.GetX() == Input.GetY())))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
        }
        else if((GetPosY()-Input.GetY())>0)//Down
        {
            if((GetPosX()-Input.GetX())<0)//Right
            {
                for (int I = 1 ; I <= abs(GetPosY()-Input.GetY()); ++I) {
                    Temp.setX(GetPosX() + I);
                    Temp.setY(GetPosY() - I);
                    if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp ,GetColor()) && !(Temp.GetX() == Input.GetY())))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
            else if((GetPosX()-Input.GetX())>0)//Left
            {
                for (int I = 1 ; I <= abs(GetPosY()-Input.GetY()); ++I) {
                    Temp.setX(GetPosX() - I);
                    Temp.setY(GetPosY() - I);
                    if(GetGameField()->IsBlocked(Temp,GetColor())||(GetGameField()->AbleToAttack(Temp ,GetColor()) && !(Temp.GetX() == Input.GetY())))
                    {
                        ValidMove = false;
                        break;
                    }
                }
            }
        }
        if(ValidMove){cout<<"Debug diag"<<endl;}
        return ValidMove;
    }
    return false;
}

bool Queen::CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input, const bool MovePiece)
{
    if(LeftAndRight(Input)||UpAndDown(Input)||Diagonal(Input))
    {
        if(MovePiece)
        {
            SetPos(Input);
        }
        return true;
    }
    return false;
}

