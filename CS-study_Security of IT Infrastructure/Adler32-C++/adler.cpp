#include "adler.h"
#include <string>
using namespace std;

cAdler::cAdler() {};
cAdler::~cAdler() {}

unsigned int cAdler::adler32()
{
    unsigned int A=1;
    unsigned int B=0;

    for (unsigned int i=0; i<n; i++)
        //for (int i=0; i<4;i++) //dla slowa test - cztery znaki
    {
        A=(A+tekst[i])%65521;
        B=(B+A)%65521;
    }

    //cout<<"B*65536+A";

    return B*65536+A;
}

void cAdler::fnSetTekst(unsigned int t, unsigned int i)
{
    tekst[i]=t;
}
/*
void cAdler::fnSetTekstEnd()
{
    tekst[19]= {'\0'};
}
*/
string cAdler::fnGetTekst() //metoda do obslugi wyswietlania
{
    string zwrot(tekst);  //konwersja na string - aby latwiej bylo wyswietlic, na char tylko jeden znak bylem w stanie wyciagnac
    return zwrot;
}

void cAdler::fnSetWynik(unsigned int w)
{
    wynik=w;
}

unsigned int cAdler::fnGetInt()
{
    return wynik;
}
