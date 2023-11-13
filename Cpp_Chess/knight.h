#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
    bool Move(int X, int Y);
};

#endif // KNIGHT_H
