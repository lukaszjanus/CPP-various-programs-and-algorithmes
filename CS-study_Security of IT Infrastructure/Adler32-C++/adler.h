#include <string>
using namespace std;

class cAdler
{
    static const unsigned int n=19;
    //char tekst[5]={'t','e','s','t','\0'}; //dla testu
    char tekst[n];
    unsigned int wynik;

    public:

    cAdler();
    ~cAdler();

    unsigned int adler32(); //metoda wyliczajaca wartosc adler32

    void fnSetTekst(unsigned int t, unsigned int i);
  //  void fnSetTekstEnd();
    string fnGetTekst();
    void fnSetWynik(unsigned int w);
    unsigned int fnGetInt();

};
