#ifndef ROOK_H
#define ROOK_H
#include"chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsRook() const {return true;}

    bool CheckingValidMove(const int X,const int Y,const bool MovePiece = false);

    ~Rook(){}
private:
    bool UpAndDown(const int X,const int Y);
    bool LeftAndRight(const int X,const int Y);
};

#endif // ROOK_H
