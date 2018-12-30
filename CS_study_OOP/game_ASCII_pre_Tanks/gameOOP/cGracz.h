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
    void fnSetGracz(string sName); //metoda niewykorzystana - potrzebowa�bym przy wywo�aniu dodatkowej zmiennej.
    void fnNazwaGracza(); //wprowadzenie imienia gracza
    void fnDefault1(); //warto�� domy�lna dla gracza 1, gdy nie ma/nie podano imienia.
};

#endif // cGracz_H
