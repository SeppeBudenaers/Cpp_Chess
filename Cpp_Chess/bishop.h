#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsBishop() const {return true;}

    bool CheckingValidMove(int X, int Y, bool MovePiece = false);

    ~Bishop() {}

private:
    bool Diagonal(int X, int Y);
};

#endif // BISHOP_H
