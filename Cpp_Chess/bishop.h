#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color) : ChessPiece(X,Y,Color)   {}
};

#endif // BISHOP_H
