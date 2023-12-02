#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <vector>
#include"gameboard.h"


using namespace std;
class GameManager
{
public:
    GameManager(void) {}


    void Turn(void);

    ~GameManager(void) {}
private:
    struct coordinates
    {
        int X;
        int Y;
    };

    GameField gamefield;



    void PrintGamePiecePosistion(vector<ChessPiece*>* list);

    bool RemoveGamePiece(int X,int Y,vector<ChessPiece*>* list);

    coordinates ScanInput(void);
    int CharToInt(char input);
    bool OutOfBounds(int X,int Y);
};
#endif // GAMEMANAGER_H
