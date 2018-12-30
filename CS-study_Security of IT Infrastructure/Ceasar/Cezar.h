#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Cezar{

public:
    string sWczytany="";

    int i_Przesuniecie;

    Cezar();
    ~Cezar();

    void fnWczytaj(string sNazwa); //wczytanie textu z pliku

    void fnMenu();
    void fnSzyfruj(int i_przesuniecie);
    void fnDeszyfruj(int i_przesuniecie);

    void fnZapisz();


};
