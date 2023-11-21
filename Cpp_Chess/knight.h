#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}
    bool Move(int X, int Y);
};

#endif // KNIGHT_H
