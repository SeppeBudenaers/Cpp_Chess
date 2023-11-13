#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
};

#endif // KNIGHT_H
