#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsKing() const {return true;}


    bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false);

    ~King(){}
private:
    bool Moveset(const Coordinates<uint8_t,uint8_t>& Input);
};

#endif // KING_H
