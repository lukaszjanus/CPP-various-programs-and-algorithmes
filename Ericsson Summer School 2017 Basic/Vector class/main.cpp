#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

/* prosta klasa (przygotowana do obslugi gry z pojemnikiem wektorowym:
w konstruktorze tworzy pusty wektor (rozmiar 0) dla wspolrzednych x,y;
- setVect - dodaje dane do wektora
- getX, getY - zwraca dane (wyœwietla wartoœæ), niezbedny jest indeks tablicy - 'nr'
- getSize - potzebne do poxniejszego wyswietlania np w main wszystkich elementow tablicy w petli
- fnErase - do usuwania elementow z vectora - rowniez potrzebny indeks (pobiera sie z petli), ale jest on przerabiany
            na tzw. iterator - wskaznik do odszukania elementu w wektorze i usuniecia go metoda erase
            ( erase automatycznie zmniejsza rozmiar vectora, przesuwa indeksy)
*/


class cFire
{
    vector <int> m_x; //tworzymy vector przechowujacy int
    vector <int> m_y;
    char m_Ammo=111; //symbol pocisku do gry - ascii, lit. 'o'

public:
    cFire()
    {
        m_x.push_back(0);
        m_y.push_back(0);
    }
    ~cFire() {};


    char fnGetAmmo()
    {
        return m_Ammo;
    }



 void setVect(int x, int y)
    {
        m_x.push_back(x);
        m_y.push_back(y);
    }
    int getX( int nr)
    {
        return m_x[nr];
    }
    int getY( int nr)
    {
        return m_y[nr];
    }
    int getSize()
    {
        return m_x.size();
    }
    void fnErase(int nr) //wchodzimy intem z wielkosci vectora
    {
        vector <int>::iterator a; //aby dostac sie do n-tego elementu, tworzymy intowy wskaxnik - iterator bedacy pod zmienna a
        a=m_x.begin()+nr; //idziemy na poczatek vectora i przesuwamy sie o n pol - wtedy mamy adres, ktory wrzucamy do a (mozna tez od konca) 
        m_x.erase(a); //bezposrednie usuniecie elementu z vectora

        vector <int>::iterator b;
        b=m_y.begin()+nr;
        m_y.erase(b);
    }
};







int main()
{
    srand(time(NULL));
    int k,g;

    cFire *test = new cFire;

    for (int i=1; i<5; i++)
    {
        k=(rand()%10)*(rand()%10)+1;
        g=(rand()%10)*(rand()%10)*(-1);
        test->setVect(k,g); //wrzucenie danych do vectora
    }

    for (int i=0; i<test->getSize(); i++)
    {
        cout<<test->getX(i)<<" "<<test->getY(i)<<endl; //wyswietlenie zawartosci tablicy vectora
    }

    cout<<endl;
    cout<<test->getSize()<<endl; //pobranie ilosci elementow vectora
    test->fnErase(2); //usuniecie pozycji nr 3 (0,1,2...) - funkcja
    cout<<endl;
    cout<<test->getSize()<<endl<<endl; //pobranie ponowne ilosci elementow - powinno byc mniejsze o jeden od wczesniejszego
    for (int i=0; i<test->getSize(); i++) //wyswietlenie ilosci elementow - ograniczeniem rozmiar vectora
    {
        cout<<test->getX(i)<<" "<<test->getY(i)<<endl; //ponowne wyswietlenie
    }

    /*
        vector <int> kolejka;
        kolejka.push_back(0);


        for (int i=0;i<10;i++)
        {
             k=(rand()%10)*(rand()%10)+1;
            kolejka.push_back(k);
        }


        for (int i=0;i<10;i++)
        {
            cout<<kolejka[i]<<endl;
        }
        cout<<endl<<endl;
        int g=kolejka[2];
        cout<<g;
    */
    return 0;
}
