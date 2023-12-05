#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsBishop() const {return true;}

    bool CheckingValidMove(const int X,const int Y,const bool MovePiece = false);

    ~Bishop() {}

private:
    bool Diagonal(const int X,const int Y);
};

#endif // BISHOP_H
