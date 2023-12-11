#include <iostream>
#include <vector>
#include "customerror.h"
#include "gamemanager.h"

int main()
{
    chess::GameManager gamemanager;
    while(1)
    {
        try{
            gamemanager.Turn();
        }
        catch(help& e) {std::cout <<e.what()<< std::endl;} // still need to write what to pinr
        catch(canceld& e) {std::cout <<e.what()<< std::endl;}
        catch(resign& e) {std::cout <<e.what()<< std::endl;} // resign function to tell who won ect.
        catch(nopiece& e) {std::cout <<e.what()<< std::endl;}
        catch(invalidmove& e) {std::cout <<e.what()<< std::endl;}
        catch(samepiece& e) {std::cout <<e.what()<< std::endl;}
        catch(check& e) {std::cout <<e.what()<< std::endl; gamemanager.ResetTurn();} // reset gamefield
        catch(noking& e) {std::cout <<e.what()<< std::endl;}
    }
    return 0;
}
