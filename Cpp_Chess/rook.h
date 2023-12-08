#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsRook(void) const {return true;}

    bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false);

    ~Rook(){}
private:
    bool UpAndDown(const Coordinates<uint8_t,uint8_t>& Input);
    bool LeftAndRight(const Coordinates<uint8_t,uint8_t>& Input);  
};

#endif // ROOK_H
