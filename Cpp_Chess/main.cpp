#include <iostream>
#include <vector>
#include "gamemanager.h"

int main()
{
    chess::GameManager gamemanager;
    while(1)
    {
       gamemanager.Turn();
    }
    return 0;
}
