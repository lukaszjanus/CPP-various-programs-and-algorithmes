#include <iostream>
#include <cstring>
//#include <ctime>
#include <cstdlib>
#include "adler.h"
using namespace std;

/*
13-05-2018
Autor: Łukasz Janus

Program sprawdzający kolizje za pomocą algorytmu Adler32
Wiki: suma kontrolna opracowana przez Marka Adlera w oparciu o sumę kontrolną Fletchera, szybsza od CRC32, ale mniej dokładna.

Dzialanie:
1. Losuje 100000 ciagow znakow k-literowych (min. 10) i policzyc adler 32 (tylko male litery)
2. Znajduje kolizje pomiedzy 1. i wyswietla oba ciagi znakow i Adler32.
3. Policzyc ile kolizji.

Te same sumy kontrolne - moga byc przy tych samych ciagach znaków
(dlatego pow. 10, aby tak nie bylo) lub jak bêda kolizje.

Dlugosc ustawic na 19 znakow.

*/

void fnStart()
{

    const unsigned int iMax=100000; //ilosc wyrazow w tablicy;
    //cout<<"Podaj n (dlugosc ciagu): ";
    //cin>>n;
    const unsigned int n=19;  //dlugosc ciagu, nie jest dodawany znak konca linii '\0' - przy adlerze zmienia wynik no i powieksza tablice

    //unsigned int *tab = new unsigned int[iMax]; //tablica na wartości adlerowe, w sumie chyba zbedna
    unsigned int counter=0; //licznik kolizji

    cAdler *Dane = new cAdler[iMax]; //tablica obiektow do przechowywania wyrazow i adlerow
    cout<<" Generowanie wyrazow - prosze czekac.\n";
    for (unsigned int i=0; i<iMax; i++)
    {
        for(unsigned int j=0; j<n; j++)
        {
            unsigned int temp=rand()%26+97;
            Dane[i].fnSetTekst((unsigned int)temp, j);
        }

        //Dane[*i].fnSetTekstEnd(); //dopisanie znaku '\0', niewykorzystane
        //Dane[i].fnSetTekst("tset");  //testowo, ale wtedy wylaczyc rand'owe generowanie tekstu
        //cout<<Dane[*i].fnGetTekst()<<endl; //testowo
        Dane[i].fnSetWynik(Dane[i].adler32());
        //cout<<Dane[*i].fnGetInt()<<endl; //testowo
        //getch();
    }

    cout<<" Szukanie kolizji - prosze czekac.\n";

    for (unsigned int i=0; i<iMax; i+=1)
    {
        for ( unsigned int j = iMax-1; j > i; j-=1)
        {
            if (Dane[i].fnGetInt()==Dane[j].fnGetInt()) //porownoje tylko wartosci wyliczone przez metode adler32
            {   //wyswietlanie zderzen:
                //cout<<"Zderzone indeksy: i: "<< i<<", j: "<<j<<"\n";
                cout<<" adler1: "<<Dane[i].fnGetTekst()<<", "<<Dane[i].fnGetInt()<<", adler2: "<<Dane[j].fnGetTekst()<<", "<<Dane[j].fnGetInt()<<"\n\n";
                //tab[i]=Dane[i].fnGetInt();
                //cout<<"bang";
                counter++;
                //getch();
            }
        }
        //cout<<endl;
    }
    cout<<"Dla ciagu "<<iMax<<" wyrazow o dlugosci "<<n<<" znakow wykryto "<<counter<<" kolizji.";

}

int main()
{
    //string m1="test";   //powinno wyjsc 73204161
    //string m2="tset";    //powinno wyjsc 74121665

    // char test[19]="test";
    // cout<<test<<endl;
    // test[4]=111;
    // cout<<test<<endl;

    fnStart();
    return 0;
}
