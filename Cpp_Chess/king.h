#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsKing() const {return true;}

    bool CheckingValidMove(int X, int Y, bool MovePiece = false);

    ~King(){}
private:
    bool Moveset(int X, int Y);
};

#endif // KING_H
