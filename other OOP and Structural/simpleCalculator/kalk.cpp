#include <iostream>
#include "kalk.h"
#include <stdio.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;


void tablica1w::tab1w(float x, float y)
{
    //tablica jednowymiarowa dynamiczna; w sumie kastowanie mogłem w funkcji, to czytelniej wyglądałby kod;
    float *tab = new float[static_cast<int>(y)];
    for (int i=0; i<static_cast<int>(y); i++)
    {
        tab[i]=x;
    }
    for (int i=0; i<y; i++)
    {
        cout<<"wypelniam tablice x'em ="<<tab[i]<<endl;
    }
    cout<<endl;
    delete &tab[static_cast<int>(y)];
    /* //gdy jest float, pojawia sie wartosc z return'a (nan, 0, albo jak tu jakas inna)
    return tab[static_cast<int>(y)];
    */
}

void tablica2w::tab2w(float x, float y)
{
    //tablica dwuwymiarowa dynamiczna;
    cout<<"Tabliczka mnozenia X x Y:\n\n";
    float  **tab = new float * [static_cast<int>(y)];
    for (int i=0; i<x; i++)//najpierw dla tablicy jednowymiarowej tworze listę kolejnych tablic
    {
        tab[i]= new float [static_cast<int>(y)];//i tu juz mam stworzony drugi wymiar
        //cout<<tab[i]<<endl;
    }
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            tab[i][j]=(i+1)*(j+1); //wypelniam standardowo;
        }
    }
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cout<<static_cast <float>(tab[i][j]); //wyswietlam tez standardowo
        }
        cout<<endl;
    }

    //zwalnianie pamięci:

    for (int i=0; i<x; i++)
    {
        delete [] tab[i];//najpierw z drugiego wymiaru
    }

    delete [] tab;//potem z pierwszego;
    cout<<endl;
//    return tab[][static_cast<int>(y)];//tab[static_cast<int>(y)][static_cast<int>(y)];
}

float kalkulator::mnoz(float x, float y)
{
    return x*y;
}
float kalkulator::add (float x, float y)
{
    return x+y;
}
float kalkulator::odej(float x, float y)
{
    return (x-y);
}
float kalkulator::dziel (float x, float y)
{
    return x/y;
}


int dzialania::wybor_opcji()
{

    system("cls");
    cout<<"menu:\n1.Dodawanie.\n2.Odejmowanie.\n3.Mnozenie.\n4.Dzielenie.\n5.Talbica jednowymiarowa.\n6.Tablica dwuwymiarowa.\n"<<endl;
    cout<<"0 - wyjscie z programu\n\n";
    cin>>a;
    if (a<0 || a>6)  //zabezpieczenie przed wartościami innymi niż z listy menu;
    {
        wybor_opcji();
    }
    cout<<endl;
    return a;
}


void dzialania::dane() //czyli zeby przypisac watroœci do x i y, to nie wchodzê tu ¿adnymi x i y;
{
    cout<<"x: "<<endl;
    cin>>x;
    cout<<"y: "<<endl;
    cin>>y;
    // return x,y;
}

int dzialania::menu()
{
    for (;;)
    {
        switch (a)
        {
        case 1:

            cout<<"Dodajemy:" <<endl;
            dane();
            cout<<test.add(x,y);
            getch();
            break;
        case 2:
            cout<<"Odejmujemy"<<endl;
            dane();
            cout<<test.odej(x,y);
            getch();
            break;
        case 3:
            cout<<"Mnozymy:"<<endl;
            dane();
            cout<<test.mnoz(x,y);
            getch();
            break;
        case 4:
            cout<<"Dzielimy:"<<endl;
            dane();
            cout<<test.dziel(x,y);
            getch();
            break;
        case 5:
            tablica1w tab1;
            cout<<"Tablica jednowymiarowa:"<<endl;
            dane();
            //cout<<tab1.tab1w(x,y); //wersja, gdy metoda jest np typu float;
            tab1.tab1w(x,y);
            getch();
            break;
        case 6:
            tablica2w tab2;
            cout<<"Tablica dwu-wymiarowa:"<<endl;
            dane();
            tab2.tab2w(x,y);
            getch();
            break;
        default:
            cout<<"Dziekujemy."<<endl;
            return 0;
            break;
        }
        wybor_opcji();
    }
}

