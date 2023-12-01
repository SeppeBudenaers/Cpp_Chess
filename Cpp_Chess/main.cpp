#include <iostream>
#include <vector>
#include "gamemanager.h"
using namespace std;


int main()
{
    GameManager gamemanager;
    while(1)
    {
       gamemanager.PrintGamePiecePosistion();
       gamemanager.Turn();
    }
    return 0;
}
