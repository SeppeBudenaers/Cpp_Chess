#include <iostream>
#include <vector>
#include "gamemanager.h"
using namespace std;


int main()
{
    GameManager gamemanager;
    gamemanager.InitializingGame();
    gamemanager.PrintGamePiecePosistion();
    gamemanager.PlayerInput();
    gamemanager.PlayerInput();
    gamemanager.PlayerInput();
    gamemanager.PlayerInput();
    return 0;
}
