#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsKnight() const {return true;}

    bool CheckingValidMove(int X, int Y, bool MovePiece = false);

    ~Knight(){}
private:
    bool Lmovement(int X, int Y);
};

#endif // KNIGHT_H
