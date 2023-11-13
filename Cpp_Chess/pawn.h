#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"


class Pawn : public ChessPiece
{
public:
    Pawn(int X, int Y,bool Color)  : ChessPiece(X,Y,Color)   {}
    //const char* Move();
};

#endif // PAWN_H
