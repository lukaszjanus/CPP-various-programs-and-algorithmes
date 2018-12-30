#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include <conio.h>

#include "zycie.h"
using namespace std;

/*
Program Zycie wersja 1. 18.03.2017;
Symulacja gry w życie (opis w wikipedii); strukturalnie, bez wskaźników, enum'ów, define'ów (przydałyby się,
gdyby zaszła potrzeba zmiany znaku-symbolu wyswietlania zywej komórki z ascii) strukturalnie, bez funkcji i klas.
*/

int main()
{
    cout<<"Tablica  - podaj rozmiar (nie mniejszy niz 3x3):\nWysokosc\n"<<endl;
    //const int n=20,m=20;
	unsigned int n,m; //n,m - rozmiar planszy
    cin>>n;
    cout<<"Szerokosc:\n";
    cin>>m;
    char tab[n][m];
    char tab_copy [n][m];
    unsigned int i_pokolenie=0, i_zywe=0; //ilość pokoleń i ilosc zywych komorek
    char znak; //do pobrania znaku z klawiatury

    //================stworzenie i wyzerowanie tablicy===========
    for (int i=0; i<n;)
    {
        for (int j=0; j<m; j++)
        {
            tab_copy[i][j]=static_cast<char>(32);
            tab[i][j]=static_cast<char>(32);
            tab[0][j]=static_cast<char>(35);
            tab[i][0]=static_cast<char>(35);
            tab[i][m-1]=static_cast<char>(35);
            tab[n-1][j]=static_cast<char>(35);
        }
        i++;
    }
    //================wypelnienie ablicy===========
    /*
        tab[5][5]=1;
        tab[5][6]=1;
        tab[5][7]=1;
        tab[6][5]=1;
        tab[7][6]=1;
        */
    cout<<"Sposob wypelnienia planszy: ręczny - R lub losowy (l)"<<endl;
    char g;
    cin>>g;
    switch (g)
    {
    case 'R':
    case 'r':
    {
        int ile,a,b;
        cout<<"maksymalna ilosc komorek na tej planszy to: "<<(m-2)*(n-2)<<endl;
        cout<<"Ile komórek chcesz ozywic?\n";
        cin>>ile;
        cout<<"Podaj wspołrzedne z zakresu (uzupełnic): \n";
        for (int i=0; i<ile; i++)
        {
            {
                cin>>a;
                cin>>b;
                tab[a][b]=1;
            }
        }
        break;
    }
    default:  //===========wartość losowa
    {
        srand (static_cast<int> (time(NULL)));
        for (int i=1; i<n-1;)
        {
            for (int j=1; j<m-1; j++)
            {
                tab[i][j]=rand()%2;
            }
            i++;
        }
        break;
    }
    }
    //cout<<endl;
    //==================wyswietlenie tablicy początek pętli nieskończonej
    system ("cls");
    i_pokolenie = 1;
    cout<<"Zaczynamy.\nPokolenie nr 1.\n\n";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (tab[i][j]==static_cast<char>(1)) i_zywe++;
            cout<<tab[i][j];
        }
        cout<<endl;
    }
    cout<<"Komorki zywe w ilosci: "<<i_zywe<<endl;
    i_zywe=0;
    getch();
//==================wyswietlenie tablicy
    for (;;)
    {
        system ("cls");
        i_pokolenie++;
        cout<<"Pokolenie nr: "<<i_pokolenie;
//==================sprawdzanie stanu komórek
        for (int i=0; i+1<n-1; i++)
        {
            {
                for (int j=0; j+1<m-1; j++)
                {
                    /*==sprawdzanie żywotności sąsiadów==*/
                    int sasiad=0;
                    if (tab[i+1][j-1]==1) sasiad++;
                    if (tab[i+1][j]==1) sasiad++;
                    if (tab[i+1][j+1]==1) sasiad++;
                    if (tab[i][j+1]==1) sasiad++;
                    if (tab[i][j-1]==1) sasiad++;
                    if (tab[i-1][j-1]==1) sasiad++;
                    if (tab[i-1][j]==1) sasiad++;
                    if (tab[i-1][j+1]==1) sasiad++;

                    /*==zasady ożywania/umierania==*/
                    if (sasiad==3 && tab[i][j]==static_cast<char>(32))
                        tab_copy[i][j]=1;

                    if ((sasiad < 2 || sasiad > 3) && tab[i][j]==static_cast<char>(32))
                        tab_copy[i][j]=static_cast<char>(32);

                    if ((sasiad==2 || sasiad==3) && tab[i][j]==1)
                        tab_copy[i][j]=1;

                    if ((sasiad<2 || sasiad>3) && tab[i][j]==1 )
                        tab_copy[i][j]=static_cast<char>(32);
                    sasiad=0;
                }
            }
        }
//===========wyswietlenie kontrolne tab_copy
        /*
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                cout<<tab_copy[i][j];
            }
            cout<<endl;
        }
        cout<<endl<<"tab copy (wyżej)"<<endl;
        */
//=======skopiowanie zawartości z tablicy-kopii=========
        for (int i=1; i<n-1; i++)
        {
            for (int j=1; j<m-1; j++)
            {
                tab[i][j]=tab_copy[i][j];
            }
        }
//========zerowanie tab_copy i wyświetlanie aktualnego stanu planszy
        cout<<"\n\n\n";
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                tab_copy[i][j]=static_cast<char>(32);
                cout<<tab[i][j];
                if (tab[i][j]==static_cast<char>(1)) i_zywe++;
            }
            cout<<endl;
        }

        cout<<"Komorki zywe w ilosci: "<<i_zywe<<endl;
        i_zywe=0;
        //cout<<"Koniec bloku"<<endl;
        //getch(); //zakomentowane, bo dublowalo sie z if'em ze sprawdzeniem, jaki znak jest pobrany.

        /*=================wyjście z programu za pomocą klawisza esc======*/
        znak=getch();
        if( znak == 27 )  //27 wg ascii - escape :)
        {
            cout << "Koniec!!\n";
            break;
        }
    }
}
