#include "rook.h"
#include "gameboard.h"

bool Rook::UpAndDown(const Coordinates<uint8_t,uint8_t>& Input)
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
        return ValidMove;
    }
    return false;
}

bool Rook::LeftAndRight(const Coordinates<uint8_t,uint8_t>& Input)
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
        return ValidMove;
    }
    return false;
}

bool Rook::CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input, const bool MovePiece)
{
    if(LeftAndRight(Input)||UpAndDown(Input))
    {
        if(MovePiece)
        {
            SetPos(Input);
        }
        return true;
    }
    return false;
}
