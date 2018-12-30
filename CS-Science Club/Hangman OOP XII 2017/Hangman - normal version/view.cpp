#include "view.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>


cView::cView() {};

/*==========view of Main Menu=====*/

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

/*=============finishing program===========*/

void cView::fnEndMenu()
{
    std::cout<<"\n======================\n";
    std::cout<<"\n= Thank you for game =\n";
    std::cout<<"\n======================\n";
    exit(0);
}

/*========the main loop of program==========*/

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
            MessageBox(HWND_DESKTOP,"Nie ma takiej opcji","Blad",MB_OK);

            break;
        }
        }
    }
}

/*===========information about chosen option (now it is covered by system("cls")=========*/

void cView::fnChoice(char g)
{
    if(static_cast<int>(g) ==  49  || static_cast<int>(g) ==  50)
    {
        std::cout<<"\n\nTwoj wybor to: "<<g<<"\n\n";
    }
}

/*==========the main loop of playing============*/

void cView::fnGame()
{
    cEngine e;
    int iDlugoscTekstu, iIloscZnakow;
    std::string sSzukany;

/*=========manual version of giving arguments - for tests=======*/
/*
    //system ("cls");
    //std::cout<<"\n\nPodaj dlugosc tekstu: ";
    //std::cin>>iDlugoscTekstu;
    //std::cout<<"\n\nPodaj rozmiar alfabetu: ";
    //std::cin>>iIloscZnakow;
*/
    iDlugoscTekstu=5;
    iIloscZnakow=2;

    std::cout<<"\n\nTekst sklada sie z "<<iDlugoscTekstu<<" duzych liter, od A do "<<static_cast<char>(iIloscZnakow+64) <<", bez liter polskich.\nLitery moga (ale nie musza) sie powtarzac.";
    std::cout<<"\nLitery generowane sa losowo.";
    e.fnGenerate(iDlugoscTekstu,iIloscZnakow);
    //std::cout<<"\n\n"<<e.sText<<"\n\n"; //tekst, w ktorym szukamy, nalezy wylaczyc powyzszy system ("cls");

    /*=========start of looking for word ===========*/

    unsigned iRound=0;
    for (int i=1; i<7; i++)
    {
        std::cout<<"\n\n"<<e.sOdnaleziony<<"\n\n";
        std::cout<<"\n\nPodaj litere. Jesli podasz wiecej, niz jedna, sprawdzona bedzie tylko pierwsza litera: ";
        std::cin>>sSzukany;
        e.fnSetsSzukany(sSzukany);
        e.fnCheckLength();
        system("cls");
        std::cout<<"\n\nPo weryfikacji dlugosci szukamy fragmentu: "<<e.sSzukany<<"\n\n";
        i=e.fnCompare(i);
        iRound++;
    }
    //system("cls");
    std::cout<<"\n\n Koniec rundy!!\n\nZdobyles: "<<e.iPoints<<"/5 punktow w "<<iRound<<" rundach!!\n\n Grasz ponownie?\n\n";
    std::cout<<"\n\n A szukales ciagu: "<<e.sText<<"\n\n";
}
