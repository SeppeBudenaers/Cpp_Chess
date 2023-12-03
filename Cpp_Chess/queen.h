#ifndef QUEEN_H
#define QUEEN_H
#include"chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int X,int Y, bool Color, GameField*gamefield) : ChessPiece(X,Y,Color,gamefield)   {}

    bool IsQueen() const {return true;}

    bool CheckingValidMove(int X, int Y, bool MovePiece = false);

    ~Queen() {}
private:
    bool UpAndDown(int X, int Y);
    bool LeftAndRight(int X, int Y);
    bool Diagonal(int X, int Y);
};

#endif // QUEEN_H
