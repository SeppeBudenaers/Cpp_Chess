#include <iostream>
#include <vector>
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
using namespace std;

enum Color
{
    White = true,
    Black = false
};

enum Xcordinantes
{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};

int main()
{
    cout << "Hello World!" << endl;

    vector<ChessPiece*> vect;
    for (int I = 0; I < 2; ++I) {
        int Y = 1;
        int YPawn = 2;
        if(I == 1 ){Y = 7 ; YPawn = 7;}
        vect.push_back(new Rook(a,Y,I));
        vect.push_back(new Rook(h,Y,I));
        vect.push_back(new Knight(b,Y,I));
        vect.push_back(new Knight(g,Y,I));
        vect.push_back(new Bishop(c,Y,I));
        vect.push_back(new Bishop(f,Y,I));
        vect.push_back(new King(e,Y,I));
        vect.push_back(new Queen(d,Y,I));
        for (int var = 0; var < 8; ++var) {
            vect.push_back(new Pawn(var,YPawn,I));
        }
    }
    for (ChessPiece* I : vect) {
        cout<<"Cord of game piece is : ";
        switch (I->GetPosX()) {
        case 0:
            cout<<"a"<<I->GetPosY();
            break;
        case 1:
            cout<<"b"<<I->GetPosY();
            break;
        case 2:
            cout<<"c"<<I->GetPosY();
            break;
        case 3:
            cout<<"d"<<I->GetPosY();
            break;
        case 4:
            cout<<"e"<<I->GetPosY();
            break;
        case 5:
            cout<<"f"<<I->GetPosY();
            break;
        case 6:
            cout<<"g"<<I->GetPosY();
            break;
        case 7:
            cout<<"h"<<I->GetPosY();
            break;
        }
        if(I->GetColor() == 0){cout<<" And the color is : White"<<endl;}
        else {cout<<" And the color is : Black"<<endl;}
    }




    return 0;
}
