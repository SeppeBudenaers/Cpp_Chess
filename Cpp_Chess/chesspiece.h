#ifndef CHESSPIECE_H
#define CHESSPIECE_H
class GameField;

class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color,GameField*gamefield)    : Xcoordinate(X), Ycoordinate(Y),Color(Color),field(gamefield) {}

    int GetPosX() {return Xcoordinate;}
    int GetPosY() {return Ycoordinate;}
    bool GetColor() {return Color;}

    virtual bool IsBishop() {return false;}
    virtual bool IsKing() {return false;}
    virtual bool IsKnight() {return false;}
    virtual bool IsPawn() {return false;}
    virtual bool IsQueen() {return false;}
    virtual bool IsRook() {return false;}

    const GameField* GetGameField() const {return field;}

    void ResetMove(int X, int Y){SetPosX(X);SetPosY(Y);}
    virtual bool Move(int X, int Y)	= 0;
    virtual bool CheckingValidMove(int X, int Y)	= 0;

    virtual ~ChessPiece(){}
protected:
    void SetPosX(int X) {Xcoordinate = X;}
    void SetPosY(int Y) {Ycoordinate = Y;}

private:
    int Xcoordinate = 0;
    int Ycoordinate = 0;
    bool Color = false; //white = false
    const GameField* field;

};

#endif // CHESSPIECE_H
