#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

/*
23-05-2018
£ukasz Janus
Binary Tree - tworzenie i wypelnianie.

Wypelnianie odbywa sie poprzez funkcje rand() (mozna tez recznie - cin zakomentowalem),
liczby moga sie powtarzac.
Gdy liczba wyjdzie poza zakres drzewa (po sprawdzeniu warunku kopcowania), program zatrzymuje sie (getch),
mozna wtedy sprawdzic, czy faktycznie program ma racje.
*/

int main()
{
    int n=15;   //iloœæ elementów dla drzewa o strukturze 4-poziomowej
    bool puste[n];
    int Tab[n];
    int *korzen;
    int malo=2*n+1;
    int liczba;

    srand((int)time(NULL));

    //tworzenie wartosci startowych dwóch tablic - na liczby i bool'owskiej, informuj¹cej, czy dany wêzel jest pusty/zajêty
    //domyœlnie wszystkie ustawiam na true - czyli, ze mozna wstawic liczbe.
    for (int i=1; i<=n; i++)
    {
        puste[i]=true;
        Tab[i]=0;
    }
    //wypelnianie drzewa - liczby pseudolosowe
    for (int a=1; a<=n; a++)
    {
        liczba=rand() % 100;
        //cin>>liczba;  //opcjonalnie mo¿na wprowadziæ liczby recznie po zakomentowaniu rand()
        cout<<"\nLosowanie nr: "<<a<<" z "<<n<<"\nSzukam miejsca dla: "<<liczba<<endl;

        //wstawianie danej nr 1 do korzenia;
        if (puste[1]==true)
        {
            korzen=&Tab[1];
            *korzen=liczba;
            puste[1]=false;
        }

        else //gdy korzeñ jest niepusty, szukamy, gdzie mo¿na wstawiæ:
        {
            bool szuk=false;
            int wezel=1; // wêze³ nr 1 zajêty w kroku wczeœniejszym, st¹d wype³nianie od wêz³a 2:

            while (szuk==false)
            {
                if (puste[wezel]==true)
                {
                    szuk=true;
                    Tab[wezel]=liczba;
                    puste[wezel]=false;
                }   //pierwszy napotkany pusty wêze³ zostaje wype³niony, flagi zostaj¹ zmienione;
                //jeœli ju¿ liczba jest, to sprawdzam, czy jest wiêksza, czy mniejsza,
                else if(liczba<Tab[wezel])
                {
                    //idê poziom ni¿ej w lewo
                    wezel=2*wezel;
                }
                else
                {
                    //idê poziom ni¿ej w prawo
                    wezel=2*wezel+1;

                }
//gdybym jednak chcia³ iœæ ni¿ej, a tego 'ni¿ej' ju¿ nie ma (czyli wychodzê poza zakres tablicy)
//to liczby nie wstawiam i generujê poni¿szy komunikat.
                if(wezel>n)
                {
                    cout<<"\nLiczba " << liczba <<" wychodzi poza zakres drzewa o max liczbie "<<n<<" elementow.\n";
                    cout<<"Potrzebny bylby kolejny poziom o liczbie elementow: "<<malo<<endl;
                    cout<<"\nAby wylosowac kolejna liczbe, wciœnij dowolny klawisz.\n\n";
                    getch();
                    szuk=true; //i abym móg³ wylosowaæ now¹ liczbê, zwalniam flagê szukania wlolnego miejsca
                }
                Sleep(500);
            }
        }
        system("CLS");
        //wyswietlanie tablic
        for (int f=1; f<=n; f++)
        {
            cout<<endl<<"indeks nr: "<<f<<", bool:"<<puste[f]<<", Liczby: "<<Tab[f]<<endl;
        }



        cout<<"\n Drzewo: \n\n";
        //koncowe wyswietlanie drzewa

        int p=(n+1)/2; // w prawo
        int l=2;   // w lewo
        for (int i = 1; i<=n; i++)
        {
            for (int j=1; j<=p-1; j++)
            {
                cout<<" ";
            }
            cout<<Tab[i];
            for (int j=1; j<=p; j++)
            {
                cout<<" ";
            }
            if(i+1==l)
            {
                l+=l;
                p/=2;
                cout<<endl;
            }
        }
    }

    cout<<"\nLiczba elementow osiagnela ilosc wylosowanych liczb - koniec programu.\n";
    return 0;
}
