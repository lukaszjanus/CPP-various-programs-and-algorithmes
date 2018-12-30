#include "view.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>


cView::cView() {};

void cView::fnMainMenu()
{
    std::cout<<"\n===================";
    std::cout<<"\n#  Choice number: #";
    std::cout<<"\n===================";
    std::cout<<"\n#   1. New Game   #";
    std::cout<<"\n#   2. End Game   #";
    std::cout<<"\n===================";
    std::cout<<"\n# Your choice is: #";
    std::cout<<"\n===================\n";
}

void cView::fnEndMenu()
{
    std::cout<<"\n======================\n";
    std::cout<<"\n= Thank you for game =\n";
    std::cout<<"\n======================\n";
    exit(0);
}


void cView::fnStart()
{
    char g;
    for(;;)
    {
        fnMainMenu();

        std::cin>>g;
        std::cout<<static_cast<int>(g);
        system("cls");
        fnMainMenu();
        fnChoice(g);

        switch(static_cast<int>(g))
        {
        case 49:
        {
            system("cls");
            fnGame();
            break;
        }
        case 50:
        {
            system("cls");
            fnEndMenu();
            break;
        }
        default:
        {
            system("cls");
//            std::cout<<"\n Nie ma takiej opcji!! Sproboj jeszcze raz!! \n";
            MessageBox(HWND_DESKTOP,"Blad","Nie ma takiej opcji",MB_OK);

            break;
        }
        }
        //if (g==2) fnEndMenu();
    }
}

void cView::fnChoice(char g) //zabezpieczenie - do zrobienia
{
    if(static_cast<int>(g) ==  49  || static_cast<int>(g) ==  50)
    {
        std::cout<<"\n\nTwoj wybor to: "<<g<<"\n\n";
    }
    //skastowane, przechodzi bez ¿adnych dodatkowych b³êdów
}

void cView::fnGame()
{
    cEngine e;
    int iDlugoscTekstu, iIloscZnakow;
    std::string sSzukany;

    //std::cout<<"\n\nPodaj dlugosc tekstu: ";
    std::cout<<"\n\nTekst sklada sie z 200 duzych liter, od A do Z, bez liter polskich.\nLitery moga sie powtarzac.";
    //std::cin>>iDlugoscTekstu;
    iDlugoscTekstu=200;
    //std::cout<<"\n\nPodaj rozmiar alfabetu: ";
    //std::cin>>iIloscZnakow;
    iIloscZnakow=25;
    e.fnGenerate(iDlugoscTekstu,iIloscZnakow);

    //system ("cls");
    std::cout<<"\n\n"<<e.sText<<"\n\n"; //tekst, w ktorym szukamy, nalezy wylaczyc powyzszy system ("cls");
    for (int i=1; i<7; i++)
    {
        std::cout<<"\n\nDlugosc szukanego wyrazu ma byc rowna dokladnie trzem znakom.\nJesli tekst bedzie za dlugi, zostanie 'skrocony' do trzech pierwszych znakow.\nJesli bedzie za krotki, zostanie uzupelniony duzymi literami 'A'.\nWpisz swoja propozycje: ";
        std::cin>>sSzukany;
        e.fnSetsSzukany(sSzukany);
        e.fnCheckLength();
        //system("cls");
        std::cout<<"\n\nPo weryfikacji dlugosci szukamy fragmentu: "<<e.sSzukany<<"\n\n";
        i=e.fnCompare(i);
    }
    //system("cls");
    std::cout<<"\n\n Koniec rundy!! Grasz ponownie?\n\n";
}
