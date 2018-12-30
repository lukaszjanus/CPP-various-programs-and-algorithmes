#ifndef cGracz_H
#define cGracz_H

#include <string>
using namespace std;

class cGracz
{
private:
    string m_sName;
    string *m_sName2;

public:

    cGracz();
    cGracz(string sName2);

    /*==============metody=====================*/
    string fnGetGracz(); //pobranie imienia z obiektu
    void fnSetGracz(string sName); //metoda niewykorzystana - potrzebowa³bym przy wywo³aniu dodatkowej zmiennej.
    void fnNazwaGracza(); //wprowadzenie imienia gracza
    void fnDefault1(); //wartoœæ domyœlna dla gracza 1, gdy nie ma/nie podano imienia.
};

#endif // cGracz_H
