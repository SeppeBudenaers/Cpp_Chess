#ifndef BISHOP_H
#define BISHOP_H
#include"chesspiece.h"

class Bishop :public ChessPiece
{
public:
    Bishop(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsBishop() const {return true;}

    bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false);

    ~Bishop() {}

private:
    bool Diagonal(const Coordinates<uint8_t,uint8_t>& Input);
};

#endif // BISHOP_H
