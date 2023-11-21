#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y, bool Color, GameBoard* gameboard) : ChessPiece(X,Y,Color,gameboard)   {}
    bool Move(int X, int Y);
};

#endif // KNIGHT_H
