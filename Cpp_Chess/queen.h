#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsQueen() const {return true;}

    bool CheckingValidMove(const int X,const int Y,const bool MovePiece = false);

    ~Queen() {}
private:
    bool UpAndDown(const int X,const int Y);
    bool LeftAndRight(const int X,const int Y);
    bool Diagonal(const int X,const int Y);
};

#endif // QUEEN_H
