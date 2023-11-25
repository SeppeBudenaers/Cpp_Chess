#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}
    bool Move(int X, int Y); //polymorphism because the Move function is diffrent for each child
private:
    bool UpAndDown(int X, int Y);
    bool LeftAndRight(int X, int Y);
};

#endif // ROOK_H
