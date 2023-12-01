#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsRook() const {return true;}

    bool Move(int X, int Y);
    bool CheckingValidMove(int X, int Y);

    ~Rook(){}
private:
    bool UpAndDown(int X, int Y);
    bool LeftAndRight(int X, int Y);
};

#endif // ROOK_H
