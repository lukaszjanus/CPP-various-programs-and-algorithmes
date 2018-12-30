#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

/*
Kolko-krzyzyk v.1.3
Autor: Łukasz Janus
05-08-2017 - Wersja przerobiona pod kątem podłączania interfejsów

Klasy IKolko (silnik) i cKolko (gra) nie zawiera cin'ow i c'outow;
    -   wszystko odpowiadajace za strumieniowanie zostalo przeniesione do cTxt traktowanego jako interface
    -   domyslnie na razie ustawilem, ze komputer gra sam z soba:
    -   brak zabezpieczenia dla wprowadzania liter zamiast cyfr (w przypadku przestawienia na cin-y i ręcznego wprowadzania wspolrzednych;
		zabezpieczenie zrobilbym poprzez castowanie wprowadzonych wartosci na char i sprawdzanie, czy nie wychodza poza ustalony zakres ascii: >48 && <52)

IKolko - klasa bazowa (jako klasa abstrakcyjna)
    - konstruktor tworzy i wypelnia plansze z tablicy dynamicznej
    - virtualny destruktor
    - IfnPlansza i fnWygrana - wypelniaja plansze i sprawdzaja warunki wygranej

	Uzupelnienie do powyzszych metod w formie virtualnej:
    - virtual void fnWyswRemis(char c_znak, cGracz* gracz)=0; wywolana w przypadku remisu w klasie pochodnej
    - virtual int fnZwyciezca(char c_znak, cGracz* gracz)=0; wywolana w przypadku czyjejs wygranej w klasie pochodnej
    - virtual void fnWyswietl()=0; wywolywana do wyswietlania planszy

cKolko - klasa dziedziczaca
    - fnStart - wywoluje tylko Plansze i wyswietlanie
    - fnWyswietl - tu wyswietlanie, domyslnie bedzie wirtualna - oddzielna dla trybu txt i api
    - fnPlansza - tu sie dzieje wszystko: wprowadzenie danych i przekazanie do iFnPlansza; tu tez wywolywane zabezpieczenia
    - fnRuch - sprawdzenie zakresu 1-3
    - fnIA() - losowanie pojedynczej wartosci 1-3
    - fnSprawdzeniePolaIA - sprawdzenie, czy pole nie zajete - dla komputera
    - fnSprawdzeniePola - jw, ale dla czlowieka
    - fnLosowanie2 - jak pole zajete, to szuka pierwszych wolnych wspolrzednych - optymalniejsze, niz srand, bo za wolno sie zmienial
    - virtual fnZwyciezca - wyswietlenie zwyciezcy
    - virtual fnWyswRemis - info o remisie
    - virtual fnWyswietl - wyswietlenie planszy
    - virtual fnKtory - wyswietlenie aktualnego gracza
    - virtual fnWprowadz - virtualna metoda do wprowadzania danych

Ctxt - klasa pełniąca rolę interface'u do wyswietlania gry w trybie tekstowym, metody:
    - fnZwyciezca - wyswietlenie zwyciezcy
    - fnWyswRemis - info o remisie
    - fnWyswietl - wyswietlenie planszy
    - fnKtory - wyswietlenie aktualnego gracza - txt
    - fnWprowadz - wprowadzanie danych z klawiatury

cGracz - klasa odpowiadajaca za dane graczy (bez zmian
    - jeden konstruktor 'domyslny'
    - drugi dla wprowadzanego na poczatku gry imienia
    - tworzenie gracza wywolywane jest w konstruktorze poprzez funkcje fnNazwaGracza
    - seter i geter dla zmiennych prywatnych.


*/

/*=================klasa gracz==================================*/

class cGracz
{
    string m_sName;
    string *m_sName2;

    cGracz *gracz1;
    cGracz *gracz2;

public:

    cGracz()
    {
        m_sName="Komputer";
    }

    cGracz(string sName2)
    {
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
    cGracz *gracz1;
    cGracz *gracz2;

public:

    IKolko() // budujemy mapę
    {
        //cout<<" \nkonstruktor ikolko -tworzenie planszy\n\n";
        gracz1=new cGracz;
        gracz2=new cGracz;
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

    virtual ~IKolko()
    {
        for (int i=0; i<m_n; i++)
        {
            delete[] plansza[i];
        }
        delete[] plansza;
        delete gracz1, gracz2;
    };

    void IfnPlansza(char c_znak, cGracz* gracz) //analiza mapy - zapelnienie
    {
        int temp=0;

        for (int i=1; i<m_n-1; i++)
        {
            for (int j=1; j<m_n-1; j++)
            {
                if (plansza[i][j]==88 || plansza[i][j]==79)
                {
                    temp++;
                    //cout<<" temp: "<<temp<<endl; //testowo
                    fnWygrana(c_znak, gracz);
                }
                if (temp==9)
                {
                    fnWyswRemis(c_znak, gracz);
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
    virtual void fnWyswRemis(char c_znak, cGracz* gracz)=0;
    virtual int fnZwyciezca(char c_znak, cGracz* gracz)=0;
    virtual void fnWyswietl()=0;
};

/*==========================================================*/

class cKolko:public IKolko
{

public:

    cKolko()
    {
        //cout<<" \nkonstructor ckolko \n";
    };
    ~cKolko()
    {
        //cout<<" \ndestructor ckolko \n";
    };

    void start()
    {
        gracz1->fnNazwaGracza();
        for(;;)
        {
            fnWyswietl();
            fnPlansza();
        }
    }

    virtual void fnPlansza()//analiza mapy
    {
        static int i_ktory=1;
        int t=1000; //spowolnienie, aby mozna bylo zobaczyc np ruch komputera
        int a;
        int b;
        char c_znak;

        switch (i_ktory)
        {
        case 1:
        {
            a=fnIA(); //dla testow automatycznych - ruch gracza
            b=fnIA();
            fnKtory(gracz1);
            //fnWprowadz(&a, &b); //ruch gracza cin a cin b

            fnRuch(&a,&b);
            fnSprawdzeniePola(&a,&b);
            plansza[a][b]=88;
            c_znak=88;

            IfnPlansza(c_znak,gracz1);

            Sleep(t);
            i_ktory++; //zmiana gracza

            break;
        }
        case 2:
        {
            fnKtory(gracz2);
            a=fnIA(); //ruch komputera
            b=fnIA();

            fnRuch(&a,&b);
            fnSprawdzeniePolaIA(&a,&b);
            plansza[a][b]=79;
            c_znak=79;
            IfnPlansza(c_znak,gracz2);

            Sleep(t);
            i_ktory--;

            break;
        }
        }
    };

    void fnRuch(int *a, int *b)
    {
        for(;;)
        {
            if (*a>=1 && *a<=3 && *b>=1 && *b<=3)
            {
                break;
            }
            else fnWprowadz(a, b);
        }
    }

    int fnIA()
    {
        srand(time(NULL));
        int n = (rand()%3) +1;
        return n;
    }

    void fnSprawdzeniePolaIA(int *a, int *b) //gracz komputer
    {
        for(;;)
        {
            if (plansza[*a][*b]==88 || plansza[*a][*b]==79)
            {
                fnLosowanie2(*a,*b);
                /* zakomentowana wczesniejsza wersja, bardzo wolno chodzaca*/
                //  cout<<"\n IA Pole już jest zajete, podaj ponownie wspolrzedne: \n";
                //   *a=(rand()%3) +1;
                //   cout<<endl<<*a<<endl;
                //   cout<<endl<<*b<<endl;
                //  *b=(rand()%3) +1;
            }
            else break;
        }
    }

    void fnSprawdzeniePola(int *a, int *b)
    {
        for(;;)
        {
            if (plansza[*a][*b]==88 || plansza[*a][*b]==79) //wersja dla 'czlowieka', dla testow zautomatyzowana
            {
                //          cout<<"\nPole już jest zajete, podaj ponownie wspolrzedne: \n";
                //          cout<<"\nWiersz: ";
                //cin>>*a;
                fnLosowanie2(*a,*b);
                //          cout<<endl<<*a<<endl;
                //          cout<<"\nKolumna: ";
                //cin>>*b;
                //        cout<<endl<<*b<<endl;
                fnRuch(a,b); //zabezpieczenie do wyjscia poza zakres
            }
            else break;
        }
    }

    void fnLosowanie2(int &n, int &m)
    {
        for (int i=1; i<m_n-1; i++)
        {
            for (int j=1; j<m_n-1; j++)
            {;
                if (plansza[i][j]!=88 && plansza[i][j]!=79)
                {
                    n=i;
                    m=j;
                }
            }
        }
    }

    virtual void fnKtory(cGracz *gracz)=0;
    virtual void fnWprowadz(int *a, int *b)=0;
    virtual void fnWyswietl()=0;
    virtual int fnZwyciezca(char c_znak, cGracz* gracz)=0;
    virtual void fnWyswRemis(char c_znak,cGracz* gracz)=0;
};

/*==========================================================*/

class cTxt:public cKolko
{
public:

    cTxt(){};
    ~cTxt(){};

    void fnKtory(cGracz *gracz)
    {
        cout<<"Rusza sie gracz: "<<gracz->fnGetGracz()<<endl;
    }

    void fnWprowadz(int *a, int *b)
    {
            cout<<"\nWiersz: "<<endl;
            cin>>*a;
            cout<<"\nKolumna: "<<endl;
            cin>>*b;
            system("cls");
    }

    void fnWyswietl()
    {
        system("cls");
        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<endl<<endl;

        static int licznik=-1;
        licznik++;
        if (licznik>9) licznik=9;
        cout<<"\nRunda nr: "<<licznik<<"\n\n";

        for (int i=0; i<m_n; i++)
        {
            for (int j=0; j<m_n; j++)
            {
                cout<<plansza[i][j];//testowe wyswietlenie pierwszej planszy;
            }
            cout<<endl;
        }
    };

    void fnWyswRemis(char c_znak,cGracz* gracz)
    {
        int t=1000;
        Sleep(t);
        cout<<"\n Plansza zostala zapelniona! \n";
        cout<<"\n REMIS !!! \n";
    }

    int fnZwyciezca(char c_znak, cGracz* gracz)
    {
        int t=1000;
        Sleep(t);
        fnWyswietl();
        cout<<" Zwyciezyl: "<<gracz->fnGetGracz()<<" grajacy "<<c_znak<<"!!"<<endl;
        exit (0);
    }
};

void fnStart()
{

    //cKolko *gra = new cKolko;
    //  gra->start();
//   cKolko gra;
    //  gra.start();

    cKolko *gra = new cTxt;
    gra->start();
    delete gra;
}

int main()
{
    fnStart();

    return 0;
}
