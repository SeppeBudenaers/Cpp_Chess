#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsKnight() const {return true;}

    bool CheckingValidMove(const int X,const int Y,const bool MovePiece = false);

    ~Knight(){}
private:
    bool Lmovement(const int X, const int Y);
};

#endif // KNIGHT_H
