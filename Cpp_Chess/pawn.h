#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"


class Pawn : public ChessPiece
{
public:
    Pawn(int X, int Y,bool Color)  : ChessPiece(X,Y,Color)   {}
    int GetPosX()   {return Xcordinate;}
    int GetPosY()   {return Ycordinate;}
    bool GetColor() {return White;}
    const char* Move();
};

#endif // PAWN_H
