#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
};

#endif // KING_H
