#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
};

#endif // ROOK_H
