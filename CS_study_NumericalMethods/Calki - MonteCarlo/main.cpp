#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "math.h"
#include <iostream>

using namespace std;

/*

Lukasz Janus
Metoda Monte Carlo - liczenie całek jako granicy sum
Wybig - str. 92

funkcja domyslnie zaimplementowana
y = sin(x)

*/


double func(double x); //funkcja - badana 'funkcja' ;)

double randomPoint(double a, double b); //siatka punktów rozłożonych 'w miarę równo'

int main(){
    double a, b, calka=0;
    int i, n;

    cout<<"Poczatek przedzialu calkowania\n";
    cin>>a;
    cout<<"Koniec przedzialu calkowania\n";
    cin>>b;
    cout<<"x(i) - punkty tworzące siatke (*=100)\n";
    cin>>n;
    n *= 100; //ilosc punktow
     srand( time( NULL ) ); //losowanie  start

    for (i=0; i<n; i++) {
        calka += func(randomPoint(a, b)); //do funkcji wrzucamy granice ->1 (suma )
    }

    calka = (calka / (double)n) * (b - a);
    cout<<"Wartosc calki: "<< calka;
    return 0;
}

double func(double x) {
    return x*sin(x); // badana funkcja
}

//losowe punkty z przedziau a b
double randomPoint(double a, double b) {
    return a + (double)rand()/(double)(RAND_MAX+1) * (b-a); //->2 zwracamy maksymalną wartość z funkcji
}

