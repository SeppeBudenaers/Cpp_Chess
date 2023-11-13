#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y,bool Color) : ChessPiece(X,Y,Color) {}
};

#endif // QUEEN_H
