#include <iostream>
#include <vector>
#include "customerror.h"
#include "gamemanager.h"

int main()
{
    chess::GameManager gamemanager;
    bool GameOnGoing = true;
    while(GameOnGoing)
    {
        try{
            gamemanager.Turn();
            system("cls");
        }

        catch(canceld& e) {system("cls");std::cout <<e.what()<< std::endl;}
        catch(nopiece& e) {system("cls");std::cout <<e.what()<< std::endl;}
        catch(noking& e) {system("cls");std::cout <<e.what()<< std::endl;}
        catch(invalidmove& e) {system("cls");std::cout <<e.what()<< std::endl;}
        catch(samepiece& e) {system("cls");std::cout <<e.what()<< std::endl;}

        catch(check& e) {system("cls");std::cout <<e.what()<< std::endl; gamemanager.ResetTurn();} // resets gamefield

        catch(help& e) {system("cls");gamemanager.PrintHelp();} // still need to write what to pinr

        catch(resign& e) {GameOnGoing = false;}
    }
    gamemanager.PrintEndOfgame();
    return 0;
}
