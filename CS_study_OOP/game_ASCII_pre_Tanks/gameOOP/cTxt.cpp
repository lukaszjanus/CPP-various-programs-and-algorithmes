#include "cTxt.h"

#include <iostream>
#include <windows.h>
using namespace std;


cTxt::cTxt() {};
cTxt::cTxt(int szer, int dl):cGame(szer,dl) {};
cTxt::~cTxt() {};

void cTxt::fnView() //pokazanie stanu planszy
{
    cout<<endl;
    for (int i=0; i<m_szer; i++)
    {
        for (int j=0; j<m_dl; j++)
        {
            cout<<tab_org[i][j];
        }
        cout<<endl;
    }
    cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n";

    cout<<"\n\nSterowanie:\n";
    cout<<"\nLewo - 'f'";
    cout<<"\nPrawo - 's'";
    cout<<"\nDo gory - 'e'";
    cout<<"\nDo dolu - 'd'";
    cout<<"\nStrzal - Spacja";

}

void cTxt::fnPowitanie()
{
    cout<<"\nZaczynamy!!! \n";
    cout<<"\nZniszcz czarnego przeciwnika, unikaj jego pociskow,";
    cout<<"\nchowaj sie za przeszkodami,";
    cout<<"\nale uwazaj - przeszkody tez mozna zniszczyc!!\n";
};

void cTxt::fnWyborGraczy()
{
    cout<<"\nCzy chcesz podac swoje imie?\n";
    cout<<"Nacisnij 't' - tak, 'n' - nie (imiona domyslne) \n";
    char cZnak;
    cin>>cZnak;

    switch (cZnak)
    {
    case 't':
    case 'T':
    {
        cout<<"\n Podaj swoje imie : \n";
        gracz1->fnNazwaGracza();
        break;
    }
    case 'n':
    case 'N':
    default:
    {
        gracz1->fnDefault1();
        break;
    }
    }
    cout<<"\n Pojedynek odbedzie sie pomiedzy: \n";
    cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n";
    Sleep(1000);
}

void cTxt::fnOdswiezenie()
{
    system("cls");
    //static int i_runda=0;
    //i_runda++;
    //cout<<"Ilosc ruchow gracza-komputera: "<<i_runda<<"\n";
}

void cTxt::fnZwyciestwo(int i_xg1, int i_yg1,int i_xg2,int i_yg2)
{
    if (tab_org[i_xg2][i_yg2]== shot->fnGetAmmo() || tab_org[i_xg1][i_yg1] == shot->fnGetAmmo() )
    {
        system("cls");
        cout<<endl;
        int t=500;
        for (int i=0; i<10; i++)
        {
            //Sleep(t);
            t-=50;
            cout<<".";
        }
        //cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n"; //testowo
        if (tab_org[i_xg2][i_yg2]== shot->fnGetAmmo()) cout<<"\nTrafiony gracz: "<<gracz2->fnGetGracz()<<"\n";
        if (tab_org[i_xg1][i_yg1] == shot->fnGetAmmo()) cout<<"\nTrafiony gracz: "<<gracz1->fnGetGracz()<<endl;
        cout<<endl<<" Koniec! ";
        getch();
        exit (0);
    }
}
