#ifndef CHESSPIECE_H
#define CHESSPIECE_H
class GameBoard;

class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color,GameBoard*gameboard)    : Xcoordinate(X), Ycoordinate(Y),Color(Color),Board(gameboard) {}
    int GetPosX() {return Xcoordinate;}
    int GetPosY() {return Ycoordinate;}
    bool GetColor() {return Color;}
    const GameBoard* GetGameBoard() const {return Board;}
    virtual bool Move(int X, int Y)	= 0;
protected:
    void SetPosX(int X) {Xcoordinate = X;}
    void SetPosY(int Y) {Ycoordinate = Y;}

private:
    int Xcoordinate = 0;
    int Ycoordinate = 0;
    bool Color = false; //white = false
    const GameBoard* Board;

};

#endif // CHESSPIECE_H
