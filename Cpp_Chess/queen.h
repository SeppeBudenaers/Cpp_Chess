#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
    int GetPosX()   {return Xcordinate;}
    int GetPosY()   {return Ycordinate;}
    bool GetColor() {return White;}
};

#endif // QUEEN_H
