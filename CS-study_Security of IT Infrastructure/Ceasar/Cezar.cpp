#include "Cezar.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <cctype> //do duzych liter

using namespace std;


Cezar::Cezar()
{

}

Cezar::~Cezar() {};

void Cezar::fnWczytaj(string sNazwa)
{
    string line;
    string line2;

    ifstream plik(sNazwa);


    while (!plik.eof())
    {
        getline( plik, line);
        //   cout<<line<<endl;
        line2+=line;
    }
    // cout<<endl<<"line2:"<<endl;

    for (int i=0; i<line2.size(); i++)
    {
        sWczytany+=(toupper(line2[i]));
    }
    //cout<<sWczytany; //testowo
    plik.close();

}

void Cezar::fnMenu()
{
    int n;

    for(;;)
    {
        cout<<" 0 - szyfrowanie (opcja domyslna) \n 1- odszyfrowanie \n inne - wyjscie z programu\n Twoj wybor to: \n";
        cin>>n;

        if (n>1 || n<0)
        {
            cout<<"\n Dziekujemy! \n";
            exit(1);
        }

        cout<<" Podaj nazwê pliku:  (na razie na sztywno wpisana)\n";
        string plik;
        //plik="szyfr.txt";
        cin>>plik;
        fnWczytaj(plik);
        cout<<endl;

        switch(n)
        {
        case 0:
        {
            cout<<"Szyfrowanie - podaj przesuniecie:"<<endl;
            cin>>i_Przesuniecie;

            if(i_Przesuniecie>26)
            {
                i_Przesuniecie%=25;
            }

            fnSzyfruj(i_Przesuniecie);

            cout<<endl;

            break;
        }
        case 1:
        {

            cout<<"Deszyfrowanie - podaj przesuniecie:"<<endl;
            cin>>i_Przesuniecie;

            if(i_Przesuniecie>26)
            {
                i_Przesuniecie%=25;
            }

            fnDeszyfruj(i_Przesuniecie);

            cout<<endl;


            break;
        }
        default:
        {
            cout<<" brak takiej opcji ";
        }
        }
        system("Pause");
    }

}

void Cezar::fnSzyfruj(int i_przesuniecie)
{
    cout<<"Tekst wczytany: \n"<<sWczytany<<endl;
    for (int i=0; i<sWczytany.size(); i++)
    {
        if (sWczytany[i]>64 && sWczytany[i]<91)  //zabezpieczenie na przekroczenie zakresu
        {
            sWczytany[i]+=i_przesuniecie;
            if ( sWczytany[i]>90 )
            {
                sWczytany[i]-= 26;
            }
        }
    }

    cout<<"Zaszyfrowany tekst:\n"<<sWczytany<<endl;
    fnZapisz();
};

void Cezar::fnDeszyfruj(int i_przesuniecie)
{
    cout<<"Tekst wczytany: \n"<<sWczytany<<endl;
    for (int i=0; i<sWczytany.size(); i++)
    {
        if (sWczytany[i]>64 && sWczytany[i]<91)  //zabezpieczenie na przekroczenie zakresu
        {
            sWczytany[i]-=i_przesuniecie;
            if ( sWczytany[i]<65 )
            {
                sWczytany[i]+= 26;
            }
        }
    }

    cout<<"Rozszyfrowany tekst:\n"<<sWczytany<<endl;
    fnZapisz();
};

void Cezar::fnZapisz()
{
    fstream plik;
    plik.open("wynik.txt", ios::out | ios::trunc);
    if(plik.good() == true)
    {
        plik << sWczytany;
        plik.close();
    }
};
