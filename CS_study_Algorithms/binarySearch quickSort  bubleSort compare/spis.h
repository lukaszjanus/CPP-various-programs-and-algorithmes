#include <iostream>

using namespace std;
/* 11-05-2016
korekta 09-05-2016
1. Funkcja tabl - generuje liczby losowe zmiennoprzecinkowe (10 szt), zapisuje do tablicy T[] do dalszego urzytku.
2. Funkcja szukaj - podaje liczbe o wartoœci najblizszej do 7,5.
3. Funkcja sortowanie - (zlozonosc:  O(n^2) ) program sortuje babelkowo tablice od wartosci najmniejszych.
4. Funkcja binszukaj - (zlozonosc:  O(log \2/ n) )  przeszukiwanie binarne wartosci tablicy dla wartości 7,5.
5. Funkcja qucicksort - (zlozonosc:  O(n log n) ) sortowanie quick-sortem.
 Funkcje f1 i f2 - zliczają ilość operacji wiodących, f1 dla jednego liczenia, f2 dla pętli wykonanej 1000 razy
   Zmienna suma4 podaje średnią ilość wszystkich operacji dla f1 i analogicznie dla f2.
*/

long f1(double T[], int n);
long f2(double T[], int n);
void tabl(double T[], int n);
void sortowanie(double T[], int n, long& lb);
long szukaj(double T[], int n, long& l);
long binszukaj (double T[], int n, double d, long& ld);
void quicksort(double T[], long l, long p, long& licz);

//void wysw(double T[], int n);

