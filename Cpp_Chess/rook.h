#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
    int GetPosX()   {return Xcordinate;}
    int GetPosY()   {return Ycordinate;}
    bool GetColor() {return White;}
};

#endif // ROOK_H
