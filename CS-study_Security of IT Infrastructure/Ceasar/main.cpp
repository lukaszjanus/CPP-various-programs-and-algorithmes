#include <iostream>
#include "Cezar.h"

using namespace std;

/*
24.03.2018
Szyfr cezara

Program :
- wczytuje tekst z pliku tekstowego (nazwe nalezy podac)
- uzytkownik wybiera szyfrowanie/deszyfrowanie + wybiera wielkosc przesuniecia
- program zmienia wszystkie litery na duze, np.: a -> E i A -> E
- program szyfruje wszystko du¿ymi literami
- spacje cyfry, interpunkcja (kropki,przecinki) zostawia bez zmian
- zapisuje tekst do pliku wynik.txt
*/



int main()
{
    Cezar c;
    c.fnMenu();

    return 0;
}
