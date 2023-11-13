#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
    bool Move(int X, int Y);
};

#endif // ROOK_H
