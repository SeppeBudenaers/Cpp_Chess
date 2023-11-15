#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"


class Pawn : public ChessPiece
{
public:
    Pawn(int X,int Y, bool Color, GameManager* GameManager) : ChessPiece(X,Y,Color,GameManager)   {}
    bool Move(int X, int Y);
private:
    bool FirstMove = true;
};

#endif // PAWN_H
