#include <math.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "spis.h"
using namespace std;
/*
========================= ====================
*/
/*------------------funkcja_tabl-----------------------------*/
void tabl(double T[], int n)
{
    for (int i = 0; i<n; i++)
    {
        T[i] = (20.0*rand() / RAND_MAX);
    }
}
/*----------------------funkcja_szukaj-----------------------------*/
long szukaj(double T[], int n,long& l)
{
    double wynik = *T;
    for (int i = 0; i < n - 1; i++)
    {
        l++; // -----------------------------LICZNIK licz1
        if (abs(7.5 - *(T + i))<abs(7.5 - wynik))
        {
            wynik = *(T + i);
        }
    }
    // cout<<"szukanie pierwsze - liczba operacji: "<<l<<endl;
    //   cout << "Wartosc najblizsza do 7,5 to: " << abs(wynik) << endl;
    return wynik;
}
/*----------------------sortowanie_babelkowe-----------------------------*/
void sortowanie(double T[], int n, long& lb)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            lb++;// -----------------------------LICZNIK licz2
            if (T[j] > T[j+1])
            {
                swap(T[j],T[j+1]);
            }
        }
    }
    //cout<<"sortowanie buble - liczba operacji: "<<lb/2<<endl;
}
/*----------------------wyszukiwanie_binarne-----------------------------*/
long binszukaj (double T[], int n, double d, long& ld)
{
    long imin=0,imax=n-1,ind;
    while (imax-imin>1)
    {
        ld++; // -----------------------------LICZNIK licz3
        ind=(imax+imin)/2;

        if(d>T[ind])
        {
            imin=ind;
        }
        else
        {
            imax=ind;
        }
    }
    /*     for (int i=0;i<n;i++)
         {
             cout<<i<<" "<<T[i]<<endl;
         }
         cout<<imin<<" "<<imax<<endl;
       // if (fabs(T[imin]-d)>fabs(T[imax]-d)) */
    if (fabs(T[n]-d)>fabs(T[imax]-d))
    {
        ld++; // -----------------------------LICZNIK licz3
        return T[imin];
    }
    else
    {
        ld++; // -----------------------------LICZNIK licz3
        return T[imax];
    }
}

/*--------------------  F1  ------------------------*/

long f1(double T[], int n)
{
    long licz1=0,licz2=0,licz3=0, licz4=0,suma=0;
    tabl(T, n);
    /* liczniki:
    licz1 - funkcja szukaj
    licz2 - funkcja sortowanie (bąbelkowe)
    licz3 - funkcja binszukaj (binarne)
    licz4 - funkcja quicksort
    */

    /*----------------------------- wyniki bez pêtli (jeden przebieg)-------------*/
    long i=szukaj(T, n,licz1);

    cout<<"Liczba operacji bez petli: \nSearch 7.5: "<<licz1<<endl;
    sortowanie(T,n,licz2);
    cout<<"Buble sort: "<<licz2/2<<endl;
    binszukaj (T,n,7.5,licz3);
    cout<<"Binary Search: "<<licz3<<endl;
    cout<<"Quicksort: "<<endl;
    quicksort(T,0,n-1,licz4);
    cout<<"Quicksort: "<<licz4<<endl;

    suma=(licz1+(licz2/2)+licz3+licz4)/4;
    cout<<"Srednia ilosc wszystkich operacji: "<<suma<<endl;
    // delete[]T; // jeœli tu niszczê tablicê T, to f2 musi mieæ now¹ tablicê np T2, inaczej program dzia³a b³êdnie,
    //dlatego te¿ w pierwszej wersji programu tablice niepotrzebnie dublowa³em.
}

/*--------------------  F2  ------------------------*/

long f2(double T[], int n)
{
    long licz1=0,licz2=0,licz3=0,licz4=0;
    long suma1 = 0, suma2 = 0, suma3 = 0, suma4 = 0, suma_wszystkie = 0;
    tabl(T, n);
    /*----------------------------- pêtla-------------*/
    for (int i=0; i<1000; i++)
    {
        szukaj(T, n,licz1);
        suma1+=licz1;
        sortowanie(T,n,licz2);
        suma2+=(licz2/2);
        binszukaj (T,n,7.5,licz3);
        suma3+=licz3;
        quicksort(T,0,n-1,licz4);
        suma4+=licz4;
    }
    /*----------------------------- wyniki dla pêtli-------------*/
    cout<<"\nPetla 1000x: \nSearch 7.5: "<<suma1/1000<<endl;
    cout<<"Buble sort: "<<(suma2)/1000<<endl;
    cout<<"Binary Search: "<<suma3/1000<<endl;
    cout<<"Quick sort: "<<suma4/1000<<endl;
    suma_wszystkie=((suma1+suma2+suma3+suma4)/4)/1000;
    cout<<"Srednia ilosc wszystkich operacji po powtorzeniu petli 1000 razy: "<<suma_wszystkie<<endl<<endl;

    delete[]T;
}
