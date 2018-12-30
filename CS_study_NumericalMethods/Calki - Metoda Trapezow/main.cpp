#include <iostream>
#include <cmath>
using namespace std;

/*
Lukasz Janus
Kwadratury interpolacyjne: Metoda Trapezow.
- dokladniejsza od metody prostokatow, trapezy sa dokladniejsze, bo zamiast prostej na wierzcholku wzdloz krzywej jest bok trapeza
- calkujemy reszte identycznie jak w kwadratach, czyli n rownych przedzialow

Wybig, s. 77.

funkcja na sztywno zaimplementowana:
y=sin(x)

*/


//funkcja dla ktorej obliczamy calke
double func(double x) {
return sin(x);
}

int main(){
    double xp, xk, dx, wynik = 0;
    double i, n;

    cout<<"Poczatek przedzialu  : ";
    cin>>xp;
    cout<<"Koniec przedzialu : ";
    cin>>xk;
    cout<<"Ilosc przedzialow : ";
    cin>>n;

    dx = (xk - xp) / (double)n;
    for (i=1; i<n; i++) {
        wynik += func(xp + i * dx);
    }
    wynik += (func(xp) + func(xk)) / 2;
    wynik *= dx;

    cout<<"Wynik : "<< wynik;

    return 0;
}
