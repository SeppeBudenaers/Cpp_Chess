#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsBishop() {return true;}

    bool Move(int X, int Y);
    bool CheckingValidMove(int X, int Y);

    ~Bishop() {}
private:
    bool Moveset(int X, int Y);
};

#endif // BISHOP_H
