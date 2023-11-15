#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(int X,int Y, bool Color, GameManager* GameManager) : ChessPiece(X,Y,Color,GameManager)   {}
    bool Move(int X, int Y);
};

#endif // KING_H
