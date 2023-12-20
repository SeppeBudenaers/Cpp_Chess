#include "gamemanager.h"
#include "coordinates.h"
#include "customerror.h"
#include "math.h"
#include <cstdint>
#include <fstream>

using namespace chess;
uint8_t GameManager::CharToUint8_T(const char Input)
{
    if (isdigit(Input))
    {
        return static_cast<uint8_t>(Input - '0');
    }
    else if (isalpha(Input))
    {
        return static_cast<uint8_t>(tolower(Input) - 'a');
    }
    return 0;
}

bool GameManager::OutOfBounds(const Coordinates<uint8_t, uint8_t> &Input)
{
    if((Input.GetX()<8)&&(0<Input.GetY())&&(Input.GetY()<9))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void GameManager::ScanInput(Coordinates<uint8_t,uint8_t>& Input)
{
    bool CordinatesAquired = false;
    uint8_t Xinput = 0;
    uint8_t Yinput = 0;

    while (!CordinatesAquired) {
        cin>>Xinput>>Yinput;
        if(Xinput == '-')
        {
            Yinput = tolower(Yinput);
            if(Yinput == 'h'){throw help();}
            else if(Yinput == 'r'){throw resign();}
            else if(Yinput == 'c'){throw canceld();}
        }
        Xinput = CharToUint8_T(Xinput);
        Yinput = CharToUint8_T(Yinput);
        Input.setX(Xinput);
        Input.setY(Yinput);
        if(!OutOfBounds(Input)){CordinatesAquired = true;}
        else
        {
            cout<<"Coordinates are out of bounds."<<endl;
            cout<<"Try again :";
        }
    }

}

void GameManager::PrintGamePiecePosistion(const vector<ChessPiece*>& list)
{
    for (ChessPiece* I : list) {
        cout<<"Co ords of game piece is : "<<uint8_t(I->GetPosX()+'a')<<(+I->GetPosY());

        if(I->GetColor() == 0){cout<<" And the color is : White"<<endl;}
        else {cout<<" And the color is : Black"<<endl;}
    }
}

void GameManager::PrintBoard(const vector<ChessPiece *> &list)
{
    string BlackPiece = "\033[38;5;232m";
    string WhitePiece = "\033[38;5;255m";
    string BlackSquare = "\033[48;5;239m";
    string WhiteSquare = "\033[48;5;144m";
    string Reset = "\033[0m";

    cout<<"   a  b  c  d  e  f  g  h"<<endl;
    cout<<" +------------------------+"<<endl;
    for (int Y = 8; Y > 0; --Y) {
        string Buffer;
        Buffer.push_back(char(Y + '0'));
        Buffer.push_back(char('|'));
        for (int X = 0; X < 8; ++X) {
            bool FoundPiece = false;
            if((X+Y)%2 == 0){Buffer.append(WhiteSquare);}
            else{Buffer.append(BlackSquare);}
            for (ChessPiece* I :list)
            {
                if((I->GetPosX() == X)&&(I->GetPosY() == Y))
                {
                    if(!I->GetColor()){Buffer.append(WhitePiece);}
                    else{Buffer.append(BlackPiece);}
                    Buffer.push_back(' ');
                    Buffer.append("\033[1m");
                    Buffer.push_back(I->IsPiece());
                    Buffer.push_back(' ');
                    FoundPiece = true;
                    break;
                }
            }
            if(!FoundPiece)
            {
             Buffer.append("   ");
            }
           Buffer.append(Reset);
        }
        Buffer.push_back(char('|'));
        Buffer.push_back(char(Y + '0'));
        cout<<Buffer<<endl;
    }
    cout<<" +------------------------+"<<endl;
    cout<<"   a  b  c  d  e  f  g  h"<<endl;
}

bool GameManager::RemoveGamePiece(const Coordinates<uint8_t,uint8_t>& Input,vector<ChessPiece*>& list)
{
    bool RemovingPiece = false;
    int pos = 0;
    for (ChessPiece* I :list)
    {
        if((I->GetPosX() == Input.GetX() )&&(I->GetPosY() == Input.GetY())&&(I->GetColor() != gamefield.GetTurn()))
        {
            RemovingPiece = true;
            break;
        }
        pos++;
    }
    if(RemovingPiece){list.erase(list.begin()+pos);}
    return RemovingPiece;
}

void GameManager::CheckingForCheck(const vector<ChessPiece*>& list)
{
    ChessPiece* King = nullptr;
    for (ChessPiece* I :list)
    {
        if((I->GetColor() == gamefield.GetTurn())&&I->IsKing())
        {
            King = I;
            break;
        }
    }
    if(King != nullptr)
    {
        for (ChessPiece* I :list)
        {
            if((I->GetColor() !=gamefield.GetTurn()) && I->CheckingValidMove(King->GetPos()))
            {
             throw check();
            }
        }
    }
    else
    {
        throw noking();
    }
}

void GameManager::LoggingMove(Coordinates<uint8_t, uint8_t> &Begin, Coordinates<uint8_t, uint8_t> &End)
{
    ofstream myfile;
    myfile.open ("xample.txt",ios::app);
    if(gamefield.GetTurn())
    {
        myfile <<"black "<<uint8_t(Begin.GetX()+'a')<<(+Begin.GetY())<<" TO "<<uint8_t(End.GetX()+'a')<<(+End.GetY())<<endl;
    }
    else
    {
        myfile <<"white "<<uint8_t(Begin.GetX()+'a')<<(+Begin.GetY())<<" TO "<<uint8_t(End.GetX()+'a')<<(+End.GetY())<<endl;
    }
    myfile.close();
}

bool GameManager::Castle(Coordinates<uint8_t, uint8_t> &Begin, Coordinates<uint8_t, uint8_t> &End)
{
    ChessPiece* King = nullptr;
    ChessPiece* Rook = nullptr;
    for (ChessPiece* I : gamefield.GetVector())
    {
        if(((I->GetPosX() == Begin.GetX())&&(I->GetPosY() == Begin.GetY()))||((I->GetPosX() == End.GetX())&&(I->GetPosY() == End.GetY())))
        {
            if(I->IsKing()){King = I;}
            else if(I->IsRook()){Rook = I;}
        }
    }

    if((King != nullptr)&&(Rook != nullptr)) //correct way to input to trigger castel
    {
        CheckingForCheck(gamefield.GetVector());
        if(King->GetFirstMove() && Rook->GetFirstMove())
        {
            bool Check = false;
            int Direction = (Rook->GetPosX() - King->GetPosX());
            if(Direction > 0) //Rechts castlen
            {
                Coordinates<uint8_t, uint8_t> KingEndPos((Rook->GetPosX()-1),Rook->GetPosY());
                Coordinates<uint8_t, uint8_t> RookEndPos((Rook->GetPosX()-2),Rook->GetPosY());
                if(Rook->CheckingValidMove(KingEndPos)&&Rook->CheckingValidMove(RookEndPos))
                {
                    for (ChessPiece* I :gamefield.GetVector())
                    {
                        if((I->GetColor() !=gamefield.GetTurn()) && (I->CheckingValidMove(KingEndPos)||I->CheckingValidMove(RookEndPos)))
                        {
                            Check = true;
                        }
                    }
                    if(!Check)
                    {
                        King->ResetMove(KingEndPos);
                        Rook->ResetMove(RookEndPos);
                        return true;
                    }
                }
            }
            else if(Direction < 0) //Links castlen
            {
                Coordinates<uint8_t, uint8_t> Pos1((Rook->GetPosX()+1),Rook->GetPosY());
                Coordinates<uint8_t, uint8_t> KingEndPos((Rook->GetPosX()+2),Rook->GetPosY());
                Coordinates<uint8_t, uint8_t> RookEndPos((Rook->GetPosX()+3),Rook->GetPosY());
                if(Rook->CheckingValidMove(Pos1)&&Rook->CheckingValidMove(KingEndPos)&&Rook->CheckingValidMove(RookEndPos))
                {
                    for (ChessPiece* I :gamefield.GetVector())
                    {
                        if((I->GetColor() !=gamefield.GetTurn()) && (I->CheckingValidMove(RookEndPos)||I->CheckingValidMove(KingEndPos)))
                        {
                            Check = true;
                        }
                    }
                    if(!Check)
                    {
                        King->ResetMove(KingEndPos);
                        Rook->ResetMove(RookEndPos);
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

bool GameManager::EnPassant(ChessPiece *&Piece, Coordinates<uint8_t, uint8_t> &End)
{
    bool CorrectBeginPos = false;
    bool CorrectEndPos = false;
    bool EnPassant = false;
    if(Piece->IsPawn())
    {
        if(!Piece->GetColor()&&(Piece->GetPosY() == 5))//correct Beginposition for white
        {
            CorrectBeginPos = true;
        }
        else if(Piece->GetColor()&&(Piece->GetPosY() == 4))//correct Beginposition for black
        {
            CorrectBeginPos = true;
        }

        if(abs(Piece->GetPosX()-End.GetX()) == 1)
        {
            if(!Piece->GetColor()&&((Piece->GetPosY() - End.GetY()) == -1))//correct Endposition for white
            {
                CorrectEndPos = true;
            }
            else if(Piece->GetColor()&&(Piece->GetPosY() - End.GetY()) == 1)//correct position for black
            {
                CorrectEndPos = true;
            }
        }

        if(CorrectBeginPos && CorrectEndPos)
        {
            int Direction = Piece->GetPosX() - End.GetX();
            Coordinates<uint8_t, uint8_t> AdjacentToPawn((Piece->GetPosX()),Piece->GetPosY());

            if(Direction == 1) //right
            {
                AdjacentToPawn.setX((Piece->GetPosX()-1));
            }
            else if(Direction == -1) //left
            {
                AdjacentToPawn.setX((Piece->GetPosX()+1));
            }
            for (ChessPiece* I :gamefield.GetVector()) // Searching for Viable Adjacent Piece
            {
                if((I->GetPosX()==AdjacentToPawn.GetX())&&(I->GetPosY()==AdjacentToPawn.GetY())&&(I->GetColor()!=Piece->GetColor())&&I->IsPawn()&&I->GetSecondMove())
                {
                    EnPassant = true;
                }
            }

            if(EnPassant)
            {
                gamefield.RemovePiece(AdjacentToPawn,!Piece->GetColor());
                Piece->ResetMove(End);
                return true;
            }
        }
    }
    return false;
}

void GameManager::PromotingPawn(ChessPiece* & Piece)
{

    if(Piece->IsPawn() && ((!Piece->GetColor() && (Piece->GetPosY() == 8)) || (Piece->GetColor() && (Piece->GetPosY() == 1))) )
    {

        Coordinates<uint8_t, uint8_t> Position(Piece->GetPosX(),Piece->GetPosY());
        bool Color = Piece->GetColor();
        char Piece;

        bool NewPiece = false;
        while(!NewPiece){
            cout<<"Promoting pawn :" <<endl;
            cout<<"Knight = k" <<endl;
            cout<<"Bishop = b" <<endl;
            cout<<"Rook   = r" <<endl;
            cout<<"Queen  = q" <<endl;
            cout<<"please select a piece for position "<< uint8_t(Position.GetX() + 'a')<<(+Position.GetY()) << " :";
            cin>>Piece;
            Piece = tolower(Piece);
            if((Piece = 'k')||(Piece = 'b')||(Piece = 'r')||(Piece = 'q'))
            {
                NewPiece = true;
            }
            else{cout<<"Invalid action"<<endl;}
        }
        gamefield.RemovePiece(Position,Color);
        gamefield.AddPiece(Position,Color,Piece);
    }
}

void GameManager::PrintEndOfgame()
{
    system("cls");
    if(gamefield.GetTurn()){cout<<"WHITE HAS WON"<<endl;}
    else{cout<<"BLACK HAS WON"<<endl;}
    PrintBoard(gamefield.GetVector());
}

void GameManager::PrintHelp()
{
    cout<<"Special commands :"<<endl;
    cout<<"-h = Help"<<endl;
    cout<<"-c = Cancel"<<endl;
    cout<<"-r = Resign"<<endl<<endl;

    cout<<"Game Pieces : "<<endl;
    cout<<"p = Pawn"<<endl;
    cout<<"r = Rook"<<endl;
    cout<<"k = knight"<<endl;
    cout<<"b = bishop"<<endl;
    cout<<"Q = Queen"<<endl;
    cout<<"K = King"<<endl<<endl;

    cout<<"Movement :"<<endl;
    cout<<"select a piece by entering its `XY` coordinate for example `a2`"<<endl;
    cout<<"When the piece is selected move it towards another legal square by entering the desired `xy` coordinate for example `a4`"<<endl<<endl;
}

void GameManager::Turn()
{
    bool TurnCompleted = false;

    while(!TurnCompleted)
    {

        //flags
        bool FoundPiece = false;
        bool ValidMove = false;
        bool RemovingPiece = false;
        SelectedPiece = nullptr;
        BeginPosition.setX(0);
        BeginPosition.setY(0);

        vector<ChessPiece*> list = gamefield.GetVector();
        Coordinates<uint8_t,uint8_t> EndPosition;

        //Turn info
        PrintBoard(gamefield.GetVector());
        if(gamefield.GetTurn()){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
        else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}

        //begin postion
        ScanInput(BeginPosition);
        for (ChessPiece* I :list)
        {
            if((I->GetPosX() == BeginPosition.GetX() )&&(I->GetPosY() == BeginPosition.GetY())&&(I->GetColor() == gamefield.GetTurn()))
            {
                SelectedPiece = I;
                FoundPiece = true;
            }
        }

        if(!FoundPiece){throw nopiece();}

        //end position
        cout<<"To ?:";
        ScanInput(EndPosition);
        SelectedPiece->SamePiece(EndPosition,list);

        ValidMove = SelectedPiece->CheckingValidMove(EndPosition,true);
        cout<<ValidMove<<endl;
        //special moves
        if(!ValidMove)
        {
            ValidMove = Castle(BeginPosition,EndPosition);
        }

        if(!ValidMove)
        {
            ValidMove = EnPassant(SelectedPiece,EndPosition);
        }

        if(!ValidMove){throw invalidmove();}

        RemovingPiece = RemoveGamePiece(EndPosition,list);

        CheckingForCheck(list);

        PromotingPawn(SelectedPiece);

        if(RemovingPiece)
        {
            gamefield.RemovePiece(EndPosition,!gamefield.GetTurn());
        }
        LoggingMove(BeginPosition,EndPosition);
        TurnCompleted = true;
    }
    gamefield.EndTurn();
}




