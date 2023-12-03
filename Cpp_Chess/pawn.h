#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsPawn() const {return true;}

    bool CheckingValidMove(int X, int Y, bool MovePiece = false);

    ~Pawn(){}
private:
    bool Attack(int X, int Y);
    bool Forward(int X, int Y);
    bool FirstMove = true;
};

#endif // PAWN_H
