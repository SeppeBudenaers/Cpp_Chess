#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color, GameBoard* gameboard) : ChessPiece(X,Y,Color,gameboard)   {}
    bool Move(int X, int Y);
};

#endif // BISHOP_H
