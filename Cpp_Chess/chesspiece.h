#ifndef CHESSPIECE_H
#define CHESSPIECE_H


class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color)    : Xcordinate(X), Ycordinate(Y),White(Color) {}
    int GetPosX() {return Xcordinate;}
    int GetPosY() {return Ycordinate;}
    bool GetColor() {return White;}
private:
    int Xcordinate = 0;
    int Ycordinate = 0;
    bool White = false;
//    virtual const char* Move()	= 0;
};

#endif // CHESSPIECE_H
