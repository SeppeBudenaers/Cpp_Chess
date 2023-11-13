#ifndef CHESSPIECE_H
#define CHESSPIECE_H


class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color)    : Xcordinate(X), Ycordinate(Y),Color(Color) {}
    int GetPosX() {return Xcordinate;}
    int GetPosY() {return Ycordinate;}
    bool GetColor() {return Color;}
    virtual bool Move(int X, int Y)	= 0;
protected:
    void SetPosX(int X) {Xcordinate = X;}
    void SetPosY(int Y) {Xcordinate = Y;}

private:
    int Xcordinate = 0;
    int Ycordinate = 0;
    bool Color = false; //white = false

};

#endif // CHESSPIECE_H
