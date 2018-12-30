#ifndef cEngine_H
#define cEngine_H

#include "cGracz.h"
#include "cFire.h"

class cEngine
{
protected:
    cGracz *gracz1;
    cGracz *gracz2;
    int m_szer;
    int m_dl;

    char **tab_org; // tabele 'operacyjne' - analogicznie, jak w grze 'zycie' do sprawdzania stanu
    char **tab_copy; //potem kopiowania zaktualizowanej wersji do drugiej tabeli
    char **tab_barricade; //tabela zawierajaca informacje o przeszkodach

    cFire *shotG;// = new cFire;
    cFire *shotD;// = new cFire;
    cFire *shotL;// = new cFire;
    cFire *shotP;// = new cFire;
    cFire *shot;

public:

    cEngine();
    cEngine (int szer, int dl);

    virtual ~cEngine();

    /*==============metody=====================*/

    void fnBarricades(char **tab_org, int i, int j);  //losowe wypelnienie tabeli przeszkodami - wywolywana tylko raz w konstruktorze
    void fnSetBarricades(int x, int y); //usuniecie barykady w przypadku trafienia pociskiem
    void fnMove (int cZnak); //plik z 'zasadami' - okresla zmiane polozenia graczy, pociskow, aktualizacje planszy
                            //zawiera czesc metod virtualnych - sa wywolywane w klasie odpowiadajacej za wyswietlanie
    virtual void fnOdswiezenie()=0; //odswierzenie ekranu, liczba petli (przy pojedynczych ruchach)
    virtual void  fnRuchKier(int *i_xg1, int *i_yg1, char cZnak)=0; //zmiana polozenia gracza, kierunek obliczany klasa fnKier()
    virtual int fnKier(char cZnakKier)=0;//określanie kierunku ruchu gracza (potem tez zmienna kopiowana do okreslania kierunku strzalu
    virtual void fnRuchKomp(int *i_xg2,int *i_yg2, int *i_xg1,int *i_yg1)=0; //poruszanie się komputera
    virtual void fnShots(int x, int y, int cKierunek)=0; //generowanie strzalu (dodanie do tablicy wektor)
    virtual void fnZwyciestwo(int i_xg1, int i_yg1,int i_xg2,int i_yg2)=0; //jesli ktos jest trafiony, to wtedy ta metoda wyswietla 'trafionego' i konczy rozgrywke
};

#endif // cEngine_H
