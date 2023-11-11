#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
    int GetPosX()   {return Xcordinate;}
    int GetPosY()   {return Ycordinate;}
    bool GetColor() {return White;}
};

#endif // KNIGHT_H
