#ifndef cTxt_H
#define cTxt_H

#include "cGame.h"


class cTxt:public cGame
{
public:

    cTxt();
    cTxt(int szer, int dl);
    ~cTxt();

    /*==============metody=====================*/

    void fnView(); //wyswietlanie planszy
    void fnPowitanie(); //ekran powitalny
    void fnWyborGraczy(); //czy nadajemy imie graczowi nr 1
    void fnOdswiezenie(); //odswiezenie planszy
    void fnZwyciestwo(int i_xg1, int i_yg1,int i_xg2,int i_yg2); //koncowe napisy - kto zwyciezyl.
};

#endif // cTxt_H
