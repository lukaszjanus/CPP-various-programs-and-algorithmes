#ifndef cFire_H
#define cFire_H

#include <iostream>
#include <conio.h>
#include <vector>


using namespace std;

class cFire
{
    vector <int> m_x;
    vector <int> m_y;
    char m_Ammo=111;

public:

    cFire();
    ~cFire();

    /*==============metody=====================*/

    char fnGetAmmo(); //wyswietlanie pocisku (char)
    void setVect(int x, int y); //wlorzenie nowych wspolrzednych do vectora - nowy pocisk
    int getX(int nr); //pobranie wspolrzednej x
    int getY(int nr); //pobranie wspolrzednej y
    int getSize(); //pobranie aktualnego rozmiaru tabllicy vector
    void fnErase(int nr); //usuniecie wspolrzednych pocisku z tablic - na podstawie indeksu z petli wykonanej w cEngine
    void swapVect(int x, int y, int nr); //aktualizacja polozenia pocisku
};

#endif // cFire_H
