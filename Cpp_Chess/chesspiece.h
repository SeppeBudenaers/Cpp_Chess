#ifndef CHESSPIECE_H
#define CHESSPIECE_H
class GameManager;

class ChessPiece
{
    friend class GameManager;
public:
    ChessPiece(int X, int Y, bool Color,GameManager*GameManager)    : Xcordinate(X), Ycordinate(Y),Color(Color),Manager(GameManager) {}
    int GetPosX() {return Xcordinate;}
    int GetPosY() {return Ycordinate;}
    bool GetColor() {return Color;}
    const GameManager* GetGameManager() const {return Manager;}
    virtual bool Move(int X, int Y)	= 0;
protected:
    void SetPosX(int X) {Xcordinate = X;}
    void SetPosY(int Y) {Xcordinate = Y;}

private:
    const GameManager* Manager;
    int Xcordinate = 0;
    int Ycordinate = 0;
    bool Color = false; //white = false

};

#endif // CHESSPIECE_H
