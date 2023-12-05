#include "bishop.h"
#include "gameboard.h"
#include "math.h"
#include <iostream>

bool Bishop::Diagonal(const Coordinates<uint8_t,uint8_t>& Input)
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
        return ValidMove;
    }
    return false;
}

bool Bishop::CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece)
{
    if(Diagonal(Input))
    {
        if(MovePiece)
        {
            SetPosX(Input.GetX());
            SetPosY(Input.GetY());
        }
        return true;
    }
    return false;
}


