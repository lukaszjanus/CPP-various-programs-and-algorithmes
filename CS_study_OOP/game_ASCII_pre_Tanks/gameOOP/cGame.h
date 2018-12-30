#ifndef cGame_H
#define cGame_H

#include "cEngine.h"

class cGame: public cEngine
{

public:
    cGame();
    cGame(int szer, int dl);

    virtual ~cGame();
    /*==============metody=====================*/

    void fnStart(); //wystartowanie gry

    char cKlaw(); //obsluga klawiatury
    /*=====================================*/
    void fnMove2(int cZnak); //sprawdzenie, czy byl pobrany znak z klawiatury, jesli nie, to gra toczy sie dalej bez ruchu gracza

    /*=============ruch komputera - przemieszczenie na planszy + strzelanie==========*/

    void fnRuchKomp(int *i_xg2,int *i_yg2, int *i_xg1,int *i_yg1);

    /*=============ruch gracza - przemieszczenie na planszy==========*/

    void  fnRuchKier(int *i_xg1, int *i_yg1, char cZnak); //poruszanie sie gracza

    int fnKier(char cZnak); //zamiana wartoœci char na znak
    void fnShots(int x, int y, int cKierunek); //pociski - generowanie i okreslanie, w ktora strone leca

    virtual void fnPowitanie()=0; //napis witajacy gracza, instrukcja sterowania
    virtual void fnWyborGraczy()=0; //podanie imienia gracza glownego lub nie podawanie zadnego (wtedy wartoœci domyœlne)
    virtual void fnView()=0; //wyswietlanie
};

#endif // cGame_H
