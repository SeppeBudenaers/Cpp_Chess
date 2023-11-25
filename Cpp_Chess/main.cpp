#include <iostream>
#include <vector>
#include "gamemanager.h"
using namespace std;


int main()
{
    GameManager gamemanager;
    gamemanager.PrintGamePiecePosistion();
    gamemanager.Turn();
    gamemanager.PrintGamePiecePosistion();
    gamemanager.Turn();
    gamemanager.PrintGamePiecePosistion();
    gamemanager.Turn();
    gamemanager.PrintGamePiecePosistion();
    gamemanager.Turn();
    gamemanager.PrintGamePiecePosistion();
    return 0;
}
