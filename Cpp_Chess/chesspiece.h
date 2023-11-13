#ifndef CHESSPIECE_H
#define CHESSPIECE_H


class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color)    : Xcordinate(X), Ycordinate(Y),White(Color) {}
    int Xcordinate = 0;
    int Ycordinate = 0;
    bool White = false;
private:
    virtual int GetPosX() = 0;
    virtual int GetPosY() = 0;
    virtual bool GetColor() = 0;
//    virtual const char* Move()	= 0;
};

#endif // CHESSPIECE_H
