#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h> // do strcmp(char1,char2);
using namespace std;

/*

- funkcje wypisujaca wszystkie informacje o danej ksiazce
- funkcje wypisuj¹c¹ caly zbior ksiazek  //*
- funkcje wyszukuj¹c¹ ksiazke po autorze lub tytule //*
- funkcje wypisujaca serie do ktorej nalezy wybrana ksiazka (w kolejnosci serii)

*/


int fn_menu(int n)
{
    cout<<"\nMenu\n1. Wszystkie ksiazki.\n2. Wyswietl konkretna ksiazke.\n3. Podaj tytul lub nazwisko.\n4. Wypisanie serii.\n Podaj n: \n";
    cin>>n;
    return n;
}

/*=====wybor nr 1 (wszystkie ksiaski===========*/

void fn_show_all(char *i_nr, char *c_imie, char *c_nazwisko, char *c_tytul, char *i_prev, char *i_next)
{
    cout<<i_nr<<" "<<c_imie<<" "<<c_nazwisko<<" "<<c_tytul<<" "<<i_prev<<" "<<i_next<<"\n";
}

/*=====wybor nr 2 (jeden wiersz na podstawie indeksu===========*/

void fn_show(int i, int temp, char *i_nr, char *c_imie, char *c_nazwisko, char *c_tytul, char *i_prev, char *i_next)
{
    if (i==temp)
    {
        cout<<i_nr<<" "<<c_imie<<" "<<c_nazwisko<<" "<<c_tytul<<" "<<i_prev<<" "<<i_next<<"\n";
    }
    else cout<<" Brak takiej ksiazki w zbiorach ";
}

/*=====wybor nr 3 wyszukiwanie po autorze lub tytule i korzystanie z funkcji 1===========*/

//void fn_find(int g,char *temp3, char *i_nr, char *c_imie, char *c_nazwisko, char *c_tytul, char *i_prev, char *i_next)
void fn_find(char *temp3, char *i_nr, char *c_imie, char *c_nazwisko, char *c_tytul, char *i_prev, char *i_next)
{

    if (strcmp(c_nazwisko,temp3)==0 || strcmp(c_tytul,temp3)==0)
    {
        fn_show_all(i_nr,c_imie,c_nazwisko,c_tytul,i_prev,i_next);
    }
    else cout<<" Brak takiej ksiazki w zbiorach ";
    //ten wyzej dziala dobrze
    //ten nizej źle - blednie pobiera sie (jeszcze w main) sizeof temp3;
    /*
        bool test=false;
        for (int i=0; i<g; i++)
        {
            if (temp3[i]==c_nazwisko[i])
            {
                cout<<temp3[i]<<" nazwisko jest zgodna z "<<c_nazwisko[i]<<endl;
                test=true;
            }
            else test=false;
        }

        if (test==false)
        {
            for (int i=0; i<g; i++)
            {
                if  (temp3[i]==c_tytul[i])
                {
                    cout<<temp3[i]<<" tytul jest zgodna z "<<c_tytul[i]<<endl;
                    test=true;
                }
                else test=false;
            }
        }
        cout<<"\ntest flaga: "<<test<<endl;
        if (test==true)    fn_show_all(i_nr,c_imie,c_nazwisko,c_tytul,i_prev,i_next);
        //else cout<<" brak takiej ksiazki ";

    */
}

/*=====wybor nr 4 wyszukiwanie po indeksie i korzystanie z funkcji 1===========*/

void fn_series(int i, int temp, char *temp3, char *i_nr, char *c_imie, char *c_nazwisko, char *c_tytul, char *i_prev, char *i_next)
{
    //int g=0;
    if (i==temp)
    {
        cout<<i_prev<<" "<<i_next;
         //g+=(int)i_prev;
    //cout<<endl<<g<<" "<<i_prev<<" "<<(int)i_prev;
    }
//do skonczenia

}



int main()
{
    char i_nr[5];
    char *c_imie= new char[10];
    char *c_nazwisko = new char[10];
    char *c_tytul= new char[15];
    char i_prev[5], i_next[5];

    ifstream plik;
    plik.open("data.in");

    if (plik.good()==false)  //sprawdzenie, czy plik istnieje, potrzebna biblioteka cstdlib
    {
        cout<<"Plik nie istnieje!";
        exit (0);
    }

    int nr_wiersza;
    int wybor,temp;

    plik>>nr_wiersza; //ilosc przypadkow testowych z pierwszej linii.

    cout<<"\nMamy "<<nr_wiersza<<" ksiazek w zbiorach.\nCo chcesz zrobic?\n";
    wybor=fn_menu(wybor);
    if (wybor==2 || wybor==4)
    {
        cout<<" Podaj nr ksiazki: ";
        cin>>temp;
    }
    char *temp3= new char[10];
    //int g;
    if (wybor==3)
    {
        cout<<" Podaj nazwisko autora: ";
        cin>>temp3;
        //g=sizeof(temp3);
//      cout<<"\n array rozmiar "<<g<<endl;
    }
    if (wybor==4)
    {
    //    cout<<" Podaj nr serii: ";
    //    cin>>temp3;
    }
    int i=1;
    cout<<"\n Wyswietlamy: \n";

    do
    {
        //plik.getline(plik, ciag_znak, '\t' );

        plik>>i_nr;
        //cout<<" ";
        plik>>c_imie;
        //cout<<" ";
        plik>>c_nazwisko;
        //cout<<" ";
        plik>>c_tytul;
        //cout<<" ";
        plik>>i_prev;
        //cout<<" ";
        plik>>i_next;
        //cout<<"\n";
        //cout<<i_nr<<endl;
        if (plik.good())
        {
            switch(wybor)
            {
            case 1:
            {
                fn_show_all(i_nr,c_imie,c_nazwisko,c_tytul,i_prev,i_next);
                break;
            }
            case 2:
            {
                fn_show(i,temp,i_nr,c_imie,c_nazwisko,c_tytul,i_prev,i_next);
                break;
            }
            case 3:
            {
                //fn_find(g,temp3, i_nr, c_imie, c_nazwisko, c_tytul, i_prev, i_next);
                fn_find(temp3, i_nr, c_imie, c_nazwisko, c_tytul, i_prev, i_next);
                break;
            }
            case 4:
            {
                //do zrobienia
                fn_series(i, temp,temp3,i_nr,c_imie,c_nazwisko,c_tytul,i_prev,i_next);
                break;
            }
            }

        }
        else break;
        i++;
    }
    while (true);
    return 0;
}
