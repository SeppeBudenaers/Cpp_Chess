#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece // the class inherents from chesspies as it is in the game also a piece
{
public:
    Bishop(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}
    bool Move(int X, int Y); //polymorphism because the Move function is diffrent for each child
};

#endif // BISHOP_H
