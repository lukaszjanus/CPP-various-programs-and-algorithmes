#include "cGame.h"
#include "cTxt.h"

/*
Prosta gra zblizona do 'Battle City' z Pegasus'a (popularnie nazywanej Czolgi).
Zadaniem gracza jest zniszczenie przeciwnika.
Gracz jak i przeciwnik sa ograniczeni wielkoscia planszy.
Przeciwnicy moga do siebie strzelac - trafienie drugiego gracza konczy rozgrywke.
Na planszy sa przeszkody, ktore wskutek strzalu sa niszczone.
Postac sterowana przez gracza po oddaniu kazdego strzalu zatrzymuje sie.

wersja rozbita na pliki nagłówkowe i cpp

Lukasz Janus
19-08-2017
*/

int main()
{
    cGame *gra = new cTxt(10,25);
    gra->fnStart();
    delete gra;

    return 0;
}
