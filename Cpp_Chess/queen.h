#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsQueen() const {return true;}

    bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false);

    ~Queen() {}
private:
    bool UpAndDown(const Coordinates<uint8_t,uint8_t>& Input);
    bool LeftAndRight(const Coordinates<uint8_t,uint8_t>& Input);
    bool Diagonal(const Coordinates<uint8_t,uint8_t>& Input);
};

#endif // QUEEN_H
