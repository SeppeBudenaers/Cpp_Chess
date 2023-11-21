#include "gameboard.h"

bool GameField::AbleToAttack(int X, int Y) const
{
    for (ChessPiece* I :vect){
        if((I->GetPosX() == X )&&(I->GetPosY() == Y)&&(I->GetColor() != TurnTracker)){return true;}
    }
    return false;
}

bool GameField::IsBlocked(int X, int Y) const
{
    for (ChessPiece* I :vect){
        if((I->GetPosX() == X )&&(I->GetPosY() == Y)&&(I->GetColor() == TurnTracker)){return true;}
    }
    return false;
}
void GameField::InitializingGame()
{
    for (int I = 0; I < 2; ++I) {
        int Y = 1;
        int YPawn = 2;
        if(I == 1 ){Y = 8 ; YPawn = 7;}
        vect.push_back(new Rook(a,Y,I,this));
        vect.push_back(new Rook(h,Y,I,this));
        vect.push_back(new Knight(b,Y,I,this));
        vect.push_back(new Knight(g,Y,I,this));
        vect.push_back(new Bishop(c,Y,I,this));
        vect.push_back(new Bishop(f,Y,I,this));
        vect.push_back(new King(e,Y,I,this));
        vect.push_back(new Queen(d,Y,I,this));
//        for (int var = 0; var < 8; ++var) {
//            vect.push_back(new Pawn(var,YPawn,I,this));
//        }
    }
}
