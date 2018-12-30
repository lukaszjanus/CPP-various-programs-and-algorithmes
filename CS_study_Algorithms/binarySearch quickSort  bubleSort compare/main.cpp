#include <cstdlib>
#include <iostream>
#include "spis.h"
using namespace std;
/* 11-05-2016
korekta 09-05-2016
1. Funkcja tabl - generuje liczby losowe zmiennoprzecinkowe (10 szt), zapisuje do tablicy T[] do dalszego urzytku.
2. Funkcja szukaj - podaje liczbe o wartoœci najblizszej do 7,5.
3. Funkcja sortowanie - program sortuje babelkowo tablice od wartosci najmniejszych.
4. Funkcja binszukaj - przeszukiwanie binarne wartosci tablicy dla wartości 7,5.
5. Funkcja qucicksort - sortowanie quick-sortem.
 Funkcje f1 i f2 - zliczają ilość operacji wiodących, f1 dla jednego liczenia, f2 dla pętli wykonanej 1000 razy
   Zmienna suma4 podaje średnią ilość wszystkich operacji dla f1 i analogicznie dla f2.
*/

/*--------------------
       MAIN
---------------------*/



int main(int argc, char** argv)
{
    int n = 10;  //ilosc elementow tablicy
    //cout<<"ile elementow tablicy: "<<endl;
    //cin>>n;
    double *T = new double[n];
    srand(100);
    f1(T,n);
    f2(T,n);

    system("PAUSE");
    return 0;
}

