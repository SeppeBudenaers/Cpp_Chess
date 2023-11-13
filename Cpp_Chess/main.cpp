#include <iostream>
#include <vector>
#include "gamemanager.h"
using namespace std;


int main()
{
    cout << "Hello World!" << endl;
    GameManager gamemanager;
    gamemanager.InitializingGame();
    gamemanager.PrintGamePiecePosistion();
    return 0;
}
