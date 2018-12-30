#include <iostream>
#include "spis.h"
using namespace std;
/*
=========================quicsort ====================
*/

void quicksort(double T[], long l, long p,long& licz) // wartosci n-tego elementu tablicy: l=0, p = n-1
{
    long i,j;
    i=l;
    j=p;
    double v; //zmienna do wyszukania srodka
    v=T[(l+p)/2];
    do
    {
        licz++; // licxnik 4
        while(T[i]<v) i++;
        while(T[j]>v) j--;
        if(i<=j)
        {
            swap (T[i],T[j]);
            i++;
            j--;
        }
    }
    while(i<=j);
    if (j>l) quicksort(T,l,j,licz);
    if (i<p) quicksort(T,i,p,licz);

}

/* // wyswietlanie zawartosci tablicy
void wysw(double T[], int n)
{
    cout<<"tablica z petli koncowa: "<<endl;
    for (int i = 0; i<n; i++)
    {
        cout <<T[i] << endl;
    }
}
*/
