#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y, bool Color, GameBoard* gameboard) : ChessPiece(X,Y,Color,gameboard)   {}
    bool Move(int X, int Y);
};

#endif // QUEEN_H
