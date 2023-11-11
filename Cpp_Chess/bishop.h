#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color) : ChessPiece(X,Y,Color)   {}
    int GetPosX()   {return Xcordinate;}
    int GetPosY()   {return Ycordinate;}
    bool GetColor() {return White;}
};

#endif // BISHOP_H
