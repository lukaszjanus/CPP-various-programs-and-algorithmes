#include <iostream>
#include <ctime>

using namespace std;

/*

Program, ktory ma miec klase DATE z
miesiac dzien godzina i sekunda;
w konstruktorze inicjjemy dane aktualnym czasem/data

napisac przeladowanie operatora, aby mozna bylo wyswietlac ww w cout - jedna klasa,

jedna funkcja, jeden main;
*/

class cCzas{
public:
    int day;
    int month;
    int year;
    time_t t;
    struct tm *czass;

    cCzas(){
        t=time(0);
        czass = localtime(&t);

        day=czass->tm_mday;
        month=czass->tm_mon;
        year=czass->tm_year;
    }

};

    ostream& operator << ( ostream& lhs,cCzas& rbs) //zwracany jest ostream&, bo strumieniowanie dziala nazasadzie tasmy:
//cout.operator<<(str1.operator<<(str2.operator<<(str3))) (method chaining - bez rozpisywania w kolejnych liniach

     {
lhs<<rbs.year+1900<<"\t"<<rbs.month+1<<"\t"<<rbs.day<<endl;
         lhs<<"dds";
         lhs<<endl<<"test2";
         return lhs;
     }

int main()
{//tutaj takie ogolne dzialanie tm:
    time_t t=time(0); //zwraca ilosc milisekund od 1900 roku
    struct tm *now = localtime(&t); //zwraca wskaznik na strukture tm, podajac ta ilosc sekund
    cout << (now->tm_year+1900)<<"/"<<now->tm_mon+1 << endl;
//tutaj obiekt z przeciazeniem:
    cCzas czas;
    cout<<czas;

    return 0;
}
