#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y, bool Color, GameManager* GameManager) : ChessPiece(X,Y,Color,GameManager)   {}
    bool Move(int X, int Y);
};

#endif // ROOK_H
