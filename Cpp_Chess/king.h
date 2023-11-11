#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
    int GetPosX()   {return Xcordinate;}
    int GetPosY()   {return Ycordinate;}
    bool GetColor() {return White;}
};

#endif // KING_H
