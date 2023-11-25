#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}
    bool Move(int X, int Y);
private:

};

#endif // BISHOP_H
