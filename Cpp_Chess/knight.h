#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    char IsPiece(void) const {return 'k';}
    bool IsKnight() const {return true;}

    bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false);

    ~Knight(){}
private:
    bool Lmovement(const Coordinates<uint8_t,uint8_t>& Input);
};

#endif // KNIGHT_H
