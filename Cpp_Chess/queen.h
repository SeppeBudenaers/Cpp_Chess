#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}
    bool Move(int X, int Y);
private:
    bool UpAndDown(int X, int Y);
    bool LeftAndRight(int X, int Y);
};

#endif // QUEEN_H
