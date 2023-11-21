#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <vector>
#include"gameboard.h"


using namespace std;
class GameManager
{
public:
    GameManager(){}
    void PrintGamePiecePosistion();
    void Turn();
private:
    struct coordinates
    {
        int X;
        int Y;
    };
    GameField gamefield;
    coordinates ScanInput();
    int CharToInt(char input);
    bool OutOfBounds(int X,int Y);
};
#endif // GAMEMANAGER_H
