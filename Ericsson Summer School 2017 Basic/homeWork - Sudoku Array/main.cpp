#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

/*
Łukasz Janus
Sudoku - wersja testowa, oparta o funkcje; działa, ale niedotestowana na ewentualne bledy;

tworzy 1 kwadrat 3x3 lub ich krotność, tu zaimplementowane max 4 kwadraty 3x3,
Warunki sprawdzania wygranej ustalone dla każdej części na sztywno;

main->:
start() - utworzenie (podanie wymiaru) i wyzerowanie planszy, uruchomienie funkcji sprawdzania warunków gra();
gra() - podawanie pol rzedu i kolumny do wypełnienia, sprawdzanie powtarzalnosci cyfr
koniec() - wyjscie z gry, wywolywane w gra() i pobierajace klawisz N,n,T,t dla kontynuacji/przerwania;
fn_pnansza3x3 - sprawdzanie podanej cyfry (tylko zakres od 1-9), zeby trafialy poprawne wartosci do planszy;
fn_win() - sprawdzenie cyz cala plansza zapelniona, a jak tak, to czy wiersze/kolumny nie maja powtarzajacych sie cyfr;

2017.07.15
*/


int koniec()
{
    //abort(); //tez dziala, ale wyrzuca error ;)
    exit (0);
    //return 0;
    //z forum: exit(0); nie spowoduje wywołania destruktorów obiektów lokalnych, a return 0; tak
}

int fn_win(char **tab,int in)
{
    bool flag=true;
    for (int i=1; i<in-1; i++)
    {
        for (int j=1; j<in-1; j++)
        {
            if ( tab[i][j]>57 || tab[i][j]<49  )
            {
                //  cout<<" false: "<<tab[i][j]<<endl;
                flag =false;
            }
        }
    }
    if (flag==false)
    {
        //cout<<"\n nie wszystkie pola wypelnione. :)\n";
        return 0;
    }

    char temp;

    for (int j=1; j<in-1; j++)
    {
        temp=tab[1][j];
        for (int g=2; g<in-1; ++g)
        {
            //    cout<<" j: "<<j<<" g: "<<g<<" temp "<<temp<<" tab: "<<tab[g][j]<<endl; //testowo
            if (tab [g][j] == temp)
            {
                cout<<"\n Oj, powtarza się cyfa: \n"<<tab[g][j]<<"\n";
                cout<<"\n Niestety nie udało Ci się!! \n";
                exit (0);
            }
        }
    }
    cout<<"\n Wiersze ok. \n";
    for (int j=1; j<in-1; j++)
    {
        temp=tab[j][1];
        for (int g=2; g<in-1; ++g)
        {
            //      cout<<" j: "<<j<<" g: "<<g<<" temp "<<temp<<" tab: "<<tab[j][g]<<endl; //testowo
            if (tab [j][g] == temp)
            {
                cout<<"\n Oj, powtarza się cyfa: \n"<<tab[j][g]<<"\n";
                cout<<"\n Niestety nie udało Ci się!! \n";
                exit (0);
            }
        }
    }
    cout<<"\n Kolumny Ok. \n";
    {
        cout<<"\n Gratulacje!! \n";
        exit (0);
    }

}

int fn_plansza3x3(int i_w)
{
    i_w+=48;

    /*===ponowne wprowadzenie cyfry:   */

    for(;;)
    {
        if (i_w <49 || i_w>57)
        {
            cout<<"\nPodales zla cyfre.";
            cout<<" \n Podaj cyfrę z zakresu 1-9 lub niepowtarzajaca sie w kwadracie 3x3: ";
            cin>>i_w;
            i_w+=48;
        }
        else
        {
            //    cout<<" \n Poprawiona cyfra: "<<i_w<<endl; //testowo
            break;
        }
    }
    return i_w;
}

int gra(int wiersz, int kolumna, int w_pola, char **tab,int in,int temp,char znak)
{
    cout<<"\n podaj wiersz: ";
    cin>>wiersz;
    cout<<"\n podaj kolumne: ";
    cin>>kolumna;
    cout<<"\n podaj wartosc: ";
    cin>>w_pola;

    w_pola=fn_plansza3x3(w_pola);

    temp=0; //ustawiam licznik - do liczenia kolejych kwadratow na 0

    /*==========sprawdzanie tablicy =======*/

    for (int i=1; i<in-1; i++)
    {
        for (int j=1; j<in-1; j++)
        {
            //              cout<<endl<<"testowo : "<<" i "<<i<<" j "<<j<<endl;
            //*===========algorytm do sprawdzania 3x3 , niestety na sztywno:================
            //*===========obejmuje max 6x6 (czyli 4 plansze o rozmiarze 3x3:================

            if (wiersz<=3 && kolumna<=3 && i>=1 && i<4 && j>=1 && j<4  && tab[i][j]==(int)w_pola)
            {
                temp=1;
                cout<<" i : "<<i <<" j: "<<j<<" err "<<tab[i][j]<<"\n"; //wyswietlanie, gdzie jest powtarzajacy sie znak - testowo
                getch();
                break;
            }
            if (wiersz<=3 && kolumna>3 && kolumna<7 && i>=1 && i<4 &&    j>=4 && j<7 && tab[i][j]==(int)w_pola)
            {
                temp=2;
                cout<<" i : "<<i <<" j: "<<j<<" err "<<tab[i][j]<<"\n";
                getch();
                break;
            }
            if (wiersz>3 && wiersz<7 && kolumna<=3 && i>=4 && i<7 && j>=1 && j<4 && tab[i][j]==(int)w_pola)
            {
                temp=3;
                cout<<" i : "<<i <<" j: "<<j<<" err "<<tab[i][j]<<"\n";
                getch();
                break;
            }
            if (wiersz>3 && kolumna>3 && i>=4 && i<7 && j>=4 && j<7 && tab[i][j]==(int)w_pola)
            {
                temp=4;
                cout<<" i : "<<i <<" j: "<<j<<" err "<<tab[i][j]<<"\n";
                getch();
                break;
            }
        }
        cout<<"\n";
    }
    /*
     // cout<<" temp: "<<temp<<endl; //roboczo
     int g=49; // wypełnienie dla testów; dla 6x6 trzeba jeszcze inne zabezpieczenia wylaczyc
     for (int i=1; i<4; i++)
     {
         for (int j=1; j<4; j++)
         {
             tab[i][j]=(int)g;
             g++;
         }
     }
     // tab[6][6]=54;
     */
    /*==========zapis wartosci po sprawdzeniu ew. powturzen lub komunikat o powturzeniu znaku =======*/

    switch (temp)
    {
    case 0:
    {
        cout<<" no error ";
        tab[wiersz][kolumna]=(int)w_pola;
        break;
    }
    case 1:
    {
        cout<<"\nTa liczba juz tu jest, podaj inna:\n";
        break;
    }
    case 2:
    {
        cout<<"\nTa liczba juz tu jest, podaj inna:\n";
        break;
    }
    case 3:
    {
        cout<<"\nTa liczba juz tu jest, podaj inna:\n";
        break;
    }
    case 4:
    {
        cout<<"\nTa liczba juz tu jest, podaj inna:\n";
        break;
    }
    }
    cout<<"\n";

    /*==========wyswietlanie aktualnego stanu =======*/

    system ("cls");

    cout<<" gra w toku: \n";
    for (int i=0; i<in; i++)
    {
        for (int j=0; j<in; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";
    }

    fn_win(tab,in);
    /*======================wyjscie/kontynuacja: =====================================*/
    for(;;)
    {
        cout<<"Kontynuujemy? 'N'- nie, 'T' - tak. \n";
        znak=getch();
        if( znak == 78 || znak == 110)  //27 wg ascii - escape :)
        {

            cout << "Koniec!!\n";
            koniec();
        }
        if (znak == 84 || znak == 116)
        {

            break;
        }
    }

}

/*======================poczatek gry - inicjacja zmiennych, tworzenie palnszy: =====================================*/

void start()
{
    int n, in; //wielkosc planszy

    // cout<<" podaj ilosc kwadratow: ";
    cout<<" plansza startowa: \n";
    //cin>>n;
//poniewaz pola maja byc 3x3, to robimy najpierw 3x3 *1, potem ew. 3x3 *2 (czyli dwie plansze ?
// to takie wstepne planowanie; domyslnie moge zrobic dynamiczne nxn i ma byc wypelniane liczbami
    n=2;
    in=(3*n)+2; //+ 2 jako ramka;

    char znak; //zmienna do pobierania znaku z klawiatury (do przerwania petli)
    char **tab = new char *[in]; //deklaracja tablicy dynamicznej - początek
    int temp; //zmienna do switcha (
    for (int i=0; i<in; i++)
    {
        tab[i]=new char[in]; //drugi rząd tablicy dynamicznej - kolumny
    }
    cout<<"\n";

    /*==========stworzenie planszy startowej do gry =======*/

    for (int i=0; i<in; i++)
    {
        for (int j=0; j<in; j++)
        {
            tab[i][0]=(int)176;
            tab[0][j]=(int)176;
            tab[i][in-1]=(int)176;
            tab[in-1][j]=(int)176;

            if (i>0&&i<in-1&&j>0&&j<in-1)
            {
                tab[i][j]=(int)(32);
            }
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";
    }
    int wiersz, kolumna, w_pola;

    /*==========start gry - wprowadzamy dane i gramy do zapelnienia pol=======*/

    for(;;)
    {
        gra(wiersz, kolumna, w_pola, tab,in,temp,znak);
    }
    cout<<" Koniec! ";

    /*========== zwalnianie pamieci ========*/

    for (int i = 0; i<in; i++)
        {
            delete [] tab[i];
        }

    delete [] tab;
}

/*======================main: =====================================*/

int main()
{
    start();

    return 0;
}
