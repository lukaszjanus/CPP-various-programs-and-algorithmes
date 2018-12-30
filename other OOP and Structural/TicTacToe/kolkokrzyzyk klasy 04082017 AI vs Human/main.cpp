#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

/*
Kolko-krzyzyk - wersja tekstowa

04-08-2017 - Wersja z prostym podzialem na klasy; brak wszystkich zabezpieczen
(przy wpisaniu spacji w imieniu wykrzacza sie, przy wyborze pola mozna wpisac litery - tez sie wykrzacza).
Mozna juz grac z komputerem
Hierarchia dwu-poziomowa.

IKolko - klasa bazowa (jako klasa abstrakcyjna)
    - konstruktor tworzy i wypelnia plansze z tablicy dynamicznej
    - virtualny destruktor
    - metody wirtualne dla wyswietlania planszy (fnWyswietl) i modyfikacji zawartosci (fnPlansza)
cKolko - klasa dziedziczaca
    - zawiera wskaüniki na obiekt gracz, przechowujace imiona graczy.
    - jeden gracz jest domyslny (komputer), drugi wpisywany recznie na poczatku gry
    - fnWyswietl() wyswietlania aktualny stan gry (konsola przeniesiona bedzie do klasy zewnetrznej, aby mozna bylo podlaczyc API)
    - fnPlansza() zmiany na planszy (kolejne ruchy),
    - fnRuch () sprawdzenie, czy wprowadzone cyfry nie wychodza poza zakres 1-3;
    - fnSprawdzeniePola - czy nie jest juz zajete
    - fnZapelnienie - czy sa jeszcze wolne pola; tutaj tez jest remis, jesli nie pojawi sie wczesniej zwyciezca
    - fnWygrana - sprawdzanie, czy sa utworzone linie z trzech punktow, jesli tak, to przekazanie do fnZwyciezca
    - fnZwyciezca - wypisanie zwyciezcy
    - fnIA() - liczby pseudolosowe dla gracza-komputera
    - fnSprawdzeniePolaIA() - sprawdzenie dla gracza-komputera, czy pole nie jest zajete

cGracz - klasa odpowiadajaca za dane graczy
    - jeden konstruktor 'domyslny'
    - drugi dla wprowadzanego na poczatku gry imienia
    - tworzenie gracza wywolywane jest w konstruktorze poprzez funkcje fnNazwaGracza


*/

/*=================klasa gracz==================================*/

class cGracz
{
    string m_sName;
    string *m_sName2;

public:

    cGracz()
    {
        m_sName="Komputer";
    }

    cGracz(string sName2)
    {
        // m_sName=sName;
        m_sName2= new string(sName2);
    }

    string fnGetGracz()
    {
        return m_sName;
    }

    void fnSetGracz(string sName)
    {
        m_sName=sName;
    }

    void fnNazwaGracza()
    {
        cout<<"\nPodaj imie: ";
        cin>>m_sName;
    }
};
/*==================klasa bazowa===========================*/
class IKolko
{
protected:

    int m_n;
    char **plansza = new char*[m_n];

public:

    IKolko()
    {
        m_n=5;
        for (int i=0; i<m_n; i++)
        {
            plansza[i]=new char[m_n];
        }

        for (int i=0; i<m_n; i++)
        {
            for (int j=0; j<m_n; j++)
            {
                plansza[0][j]=178;
                plansza[i][0]=178;
                plansza[m_n-1][j]=178;
                plansza[i][m_n-1]=178;

                if (i>0 && i<m_n-1 && j>0 && j<m_n-1)
                {
                    plansza[i][j]=32;
                }
                //cout<<plansza[i][j];//testowe wyswietlenie pierwszej planszy;
            }
            //cout<<endl;
        }
    };

    virtual ~IKolko() {};

    virtual void fnPlansza()=0;
    virtual void fnWyswietl()=0;
};

/*==========================================================*/

class cKolko:public IKolko
{
protected:

    cGracz *gracz1;
    cGracz *gracz2;

public:

    cKolko()
    {
        gracz1=new cGracz;
        gracz2=new cGracz;
        gracz1->fnNazwaGracza(); //testowo - ustawienie imienia gracza;
        system("cls");

    };

    ~cKolko() { delete gracz1, gracz2;};//destruktory dla cGracz

    void fnPlansza()
    {
        static int i_ktory=1;

        int a;
        int b;
        char c_znak;

        cout<<"\nGracze:\n";

        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<endl<<endl;

        switch (i_ktory)
        {
        case 1:
        {
            cout<<"\nRusza sie gracz: "<<gracz1->fnGetGracz()<<endl;
            cout<<"\nWiersz: "<<endl;
            cin>>a;
            cout<<"\nKolumna: "<<endl;
            cin>>b;
            cout<<endl;

            fnRuch(&a,&b);
            fnSprawdzeniePola(&a,&b);
            plansza[a][b]=88;
            c_znak=88;
            fnZapelnienie(c_znak, gracz1);

            i_ktory++; //zmiana gracza

            break;
        }
        case 2:
        {
            cout<<"\nRusza sie gracz: "<<gracz2->fnGetGracz()<<endl;

            a=fnIA();
            b=fnIA();
            fnSprawdzeniePolaIA(&a,&b);

            cout<<"\nWiersz: "<<endl;
            int i_t=500;
            for (int i=0;i<10;i++)
            {
                Sleep(i_t);
                cout<<".";
                i_t-=50;
            }
            cout<<a;
            cout<<"\nKolumna: "<<endl;
            i_t=500;
            for (int i=0;i<10;i++)
            {
                Sleep(i_t);
                cout<<".";
                i_t-=50;
            }
            cout<<b;

            plansza[a][b]=89;
            c_znak=89;
            fnZapelnienie(c_znak, gracz2);

            i_ktory--;

            break;
        }

        cout<<endl;
        }
        getch();
        system("cls");
    }

    void fnWyswietl()
    {
        static int licznik=0;
        licznik++;

        cout<<"\nRunda nr: "<<licznik<<endl;
        cout<<"\nGracze:\n";

        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<endl<<endl;

        //getch();
        for (int i=0; i<m_n; i++)
        {
            for (int j=0; j<m_n; j++)
            {
                // plansza[i][j]=1;  //// wrzucanie danych
                cout<<plansza[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void fnRuch(int *a, int *b)
    {
        for(;;)
        {
            if (*a<1|| *a>3)
            {
                cout<<"\n Bledna wartosc dla wiersza, podaj jeszcze raz, z zakresu 1-3:\n";
                cin>>*a;
            }
            else break;
        }
        for(;;)
        {
            if (*b<1|| *b>3)
            {
                cout<<"\n Bledna wartosc dla kolumny, podaj jeszcze raz, z zakresu 1-3:\n";
                cin>>*b;
            }
            else break;
        }
    }

    void fnSprawdzeniePola(int *a, int *b)
    {
        for(;;)
        {
            if (plansza[*a][*b]==88 || plansza[*a][*b]==89)
            {
                cout<<"\nPole juø jest zajete, podaj ponownie wspolrzedne: \n";
                cout<<"\nWiersz: ";
                cin>>*a;
                cout<<"\nKolumna: ";
                cin>>*b;
                fnRuch(a,b);
            }
            else break;
        }
    }

    void fnZapelnienie(char c_znak, cGracz *gracz)
    {
        int temp=0;
        //cout<<" =========test sprawdzennia: "<<gracz->fnGetGracz()<<" "<<c_znak<<endl; //testowo
        for (int i=1; i<m_n-1; i++)
        {
            for (int j=1; j<m_n-1; j++)
            {
                if (plansza[i][j]==88 || plansza[i][j]==89)
                {
                    temp++;
                //    cout<<" temp: "<<temp; //testowo
                    fnWygrana(c_znak, gracz);
                }
                if (temp==9)
                {
                    cout<<"\n Plansza zostala zapelniona! \n";
                    cout<<"\n REMIS !!! \n";
                    exit (0);
                }
            }
        }
    }

    void fnWygrana(char c_znak, cGracz* gracz)
    {
        if (plansza[1][1]==c_znak && plansza[2][2]==c_znak && plansza[3][3]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[1][3]==c_znak && plansza[2][2]==c_znak && plansza[3][1]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[1][1]==c_znak && plansza[2][1]==c_znak && plansza[3][1]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[1][2]==c_znak && plansza[2][2]==c_znak && plansza[3][2]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[1][3]==c_znak && plansza[2][3]==c_znak && plansza[3][3]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[1][1]==c_znak && plansza[1][2]==c_znak && plansza[1][3]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[2][1]==c_znak && plansza[2][2]==c_znak && plansza[2][3]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
        if (plansza[3][1]==c_znak && plansza[3][2]==c_znak && plansza[3][3]==c_znak)
        {
            fnZwyciezca(c_znak,gracz);
        }
    }

    int fnZwyciezca(char c_znak, cGracz* gracz)

    {
        fnWyswietl();
        cout<<" Zwyciezyl: "<<gracz->fnGetGracz()<<" grajacy "<<c_znak<<"!!"<<endl;
         exit (0);
    }

    int fnIA()
    {
        srand(time(NULL));
        int n = (rand()%3) +1;

        return n;
    }

    void fnSprawdzeniePolaIA(int *a, int *b)
    {
        for(;;)
        {
            if (plansza[*a][*b]==88 || plansza[*a][*b]==89)
            {
                *a=(rand()%3) +1;
                *b=(rand()%3) +1;
            }
            else break;
        }
    }
};



/*==========================================================*/

void fnStart()
{
    IKolko *gra = new cKolko;
    cout<<"\nRozpoczynamy zmagania: \n";
    for(;;)
    {
        gra->fnPlansza();
        gra->fnWyswietl();
    }
    delete gra;
}
/*==========================================================*/

int main()
{
    fnStart();

    return 0;
}
