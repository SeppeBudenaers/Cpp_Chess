#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}
    bool Move(int X, int Y);
};

#endif // KING_H
