#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsKnight() const {return true;}

    bool Move(int X, int Y);
    bool CheckingValidMove(int X, int Y);

    ~Knight(){}
private:
    bool Lmovement(int X, int Y);
};

#endif // KNIGHT_H
