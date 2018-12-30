#include <iostream>
#include <cmath>

using namespace std;

/*

Lukasz Janus
Metoda Prostokatow - korzystamy z definicji calki oznaczonej Riemanna, w ktorej wartosc calki jest interpretowana
jako suma pol obszarow pod wykresem krzywej w zadanym przedziale calkowania <a,b>; sume ta przyblirzamy przy pomocy pol
odpowiednio dobranych prostokatow;
przedzial <a,b> dzielimy na n rowno-odleglych punktow

(w Wybigu nie znalazlem)

funkcja zaimplementowana:
sin(x)
przedzial <0,3.14>
punkty: 4 (pola 0-1,1-2,2-3,3-4)
(wynik)suma:1.89
wartosc calki oznaczonej sin(x) w tym przedziale: 2;
*/

float func(float x);

int main(){
    float a, b, dx, wynik =0;
    int i, n;

    cout<<"Podaj poczatek przedzialu calkowania : ";
    cin>>a;
    cout<<"Podaj koniec przedzialu calkowania : ";
    cin>>b;
    cout<<"Podaj ilosc punktow : ";
    cin>>n;

    dx = (b - a) / (float)n; //wedlug wzoru: dx= (a-b)/n - odleglosc miedzy dwoma punktami, jednoczesnie podstawa kazdego prostakota

    for (i=1; i<=n; i++) {
        wynik += func(a + i * dx); //suma pol kwadratow
    }
    wynik *= dx;
    cout<<"Wartosc calki wynosi w przyblizeniu : "<< wynik;

return 0;
}

float func(float x) {
return sin(x);
}
