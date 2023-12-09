#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    char IsPiece(void) const {return 'p';}
    bool IsPawn() const {return true;}

    bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false);

    ~Pawn(){}
private:
    bool Attack(const Coordinates<uint8_t,uint8_t>& Input);
    bool Forward(const Coordinates<uint8_t,uint8_t>& Input);
};

#endif // PAWN_H
