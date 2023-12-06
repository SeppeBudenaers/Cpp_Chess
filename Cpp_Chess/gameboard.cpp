#include "gameboard.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "rook.h"

bool GameField::AbleToAttack(const Coordinates<uint8_t,uint8_t>& Input,const bool Color) const
{
    for (ChessPiece* I :CurrentState){
        if((I->GetPosX() == Input.GetX() )&&(I->GetPosY() == Input.GetY())&&(I->GetColor() != Color)){return true;}
    }
    return false;
}

bool GameField::IsBlocked(const Coordinates<uint8_t,uint8_t>& Input,const bool Color) const
{
    for (ChessPiece* I :CurrentState){
        if((I->GetPosX() == Input.GetX() )&&(I->GetPosY() == Input.GetY())&&(I->GetColor() == Color)){return true;}
    }
    return false;
}

GameField::GameField()
{
    for (int I = 0; I < 2; ++I) {
        int Y = 1;
        int YPawn = 2;
        if(I == 1 ){Y = 8 ; YPawn = 7;}
        CurrentState.push_back(new Rook(a,Y,I,this));
        CurrentState.push_back(new Rook(h,Y,I,this));
        CurrentState.push_back(new Knight(b,Y,I,this));
        CurrentState.push_back(new Knight(g,Y,I,this));
        CurrentState.push_back(new Bishop(c,Y,I,this));
        CurrentState.push_back(new Bishop(f,Y,I,this));
        CurrentState.push_back(new King(e,Y,I,this));
        CurrentState.push_back(new Queen(d,Y,I,this));
        for (int var = 0; var < 8; ++var) {
            CurrentState.push_back(new Pawn(var,YPawn,I,this));
        }
    }
}

void GameField::RemovePiece(const Coordinates<uint8_t,uint8_t>& Input ,const bool Color)
{
    int Pos = 0;
    for (ChessPiece* I :CurrentState)
    {
        if((I->GetPosX() == Input.GetX())&&(I->GetPosY() == Input.GetY())&&(I->GetColor() == Color))
        {
           delete I;
            break;
        }
        Pos++;
    }
    CurrentState.erase(CurrentState.begin()+Pos);
}

GameField::~GameField()
{
    for (ChessPiece* I :CurrentState)
    {
        delete I;
    }
    CurrentState.erase(CurrentState.begin(),CurrentState.end());
}
