#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

/*
Kolko-krzyzyk - wersja tekstowa

05-08-2017 - Wersja przerobiona pod kątem podłączania interfejsów:

IKolko nie zawiera cin'ow i c'outow;
W cKolko ciny i ciouty co prawda są, ale w formie metod, które będą jako wirtualne i przeniesione do klasy cTxt
Cos przestala dzialac metoda sprawdzajaca zakres; domyslnie na razie ustawilem, ze komputer gra sam z soba:

IKolko - klasa bazowa (jako klasa abstrakcyjna)
    - konstruktor tworzy i wypelnia plansze z tablicy dynamicznej
    - virtualny destruktor
    - IfnPlansza i fnWygrana - wypelniaja plansze i sprawdzaja warunki wygranej
    uzupelnienie do powyzszych w formie virtualnej:
    virtual void fnWyswRemis(char c_znak, cGracz* gracz)=0; wywolana w przypadku remisu w klasie pochodnej
    virtual int fnZwyciezca(char c_znak, cGracz* gracz)=0; wywolana w przypadku czyjejs wygranej w klasie pochodnej
    virtual void fnWyswietl()=0; wywolywana do wyswietlania planszy


cKolko - klasa dziedziczaca
    - fnStart - wywoluje tylko Plansze i wyswietlanie
    - fnWyswietl - tu wyswietlanie, domyslnie bedzie wirtualna - oddzielna dla trybu txt i api
    - fnPlansza - tu sie dzieje wszystko: wprowadzenie danych i przekazanie do iFnPlansza; tu tez wywolywane zabezpieczenia
    - fnRuch - sprawdzenie zakresu 1-3
    - fnIA() - losowanie pojedynczej wartosci 1-3
    - fnSprawdzeniePolaIA - sprawdzenie, czy pole nie zajete - dla komputera
    - fnSprawdzeniePola - jw, ale dla czlowieka
    - fnLosowanie2 - jak pole zajete, to szuka pierwszych wolnych wspolrzednych - optymalniejsze, niz srand, bo za wolno sie zmienial
    - fnZwyciezca - wyswietlenie zwyciezcy
    - fnWyswRemis - info o remisie
    - fnWyswietl - wyswietlenie planszy

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
    cGracz *gracz1;
    cGracz *gracz2;

public:

    IKolko() // budujemy mapę
    {
        cout<<" \nkonstruktor ikolko -tworzenie planszy\n\n";
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
        cout<<" \ndestructor ikolko /n";
        for (int i=0; i<m_n; i++)
        {
            delete[] plansza[i];
        }
        delete[] plansza;
        delete gracz1, gracz2;
    };

    void IfnPlansza(char c_znak, cGracz* gracz) //analiza mapy - zapelnienie
    {

        //cout<<"\nIfnPlansza: \n";
        int temp=0;

        for (int i=1; i<m_n-1; i++)
        {
            for (int j=1; j<m_n-1; j++)
            {
                if (plansza[i][j]==88 || plansza[i][j]==89)
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

    cKolko(){cout<<" \nkonstructor ckolko \n";};
    ~cKolko(){cout<<" \ndestructor ckolko \n";};

    void start()
    {
        gracz1->fnNazwaGracza();
        cout<<"\nRozpoczynamy zmagania: \n";
        for(;;)
        {
            fnPlansza();
            fnWyswietl();
        }
    }

    virtual void fnPlansza()//analiza mapy
    {
        static int i_ktory=1;

        int a;
        int b;
        char c_znak;
        system("cls");
        cout<<"\nGracze:\n";

        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<endl<<endl;

        switch (i_ktory)
        {
        case 1:
        {
            cout<<"\nRusza sie gracz: "<<gracz1->fnGetGracz()<<endl;
        //    cout<<"\nWiersz: "<<endl;
            a=fnIA();
         //   cout<<"\nKolumna: "<<endl;
            b=fnIA();
            //cin>>a;
            //cin>>b;
            //cout<<endl;

            fnRuch(&a,&b);
            fnSprawdzeniePola(&a,&b);
            plansza[a][b]=88;
            c_znak=88;

            IfnPlansza(c_znak,gracz1);

            i_ktory++; //zmiana gracza


            break;
        }
        case 2:
        {
            cout<<"\nRusza sie gracz: "<<gracz2->fnGetGracz()<<endl;

            a=fnIA();
            b=fnIA();

            fnRuch(&a,&b);
            fnSprawdzeniePolaIA(&a,&b);

            plansza[a][b]=89;
            c_znak=89;
            i_ktory--;
            IfnPlansza(c_znak,gracz2);
            break;
        }

        cout<<endl;
        }

    };

    void fnWyswietl()
    {
        for (int i=0; i<m_n; i++)
        {
            for (int j=0; j<m_n; j++)
            {
                cout<<plansza[i][j];//testowe wyswietlenie pierwszej planszy;
            }
             cout<<endl;
        }
        int t=500;
        Sleep(t);

    };

    void fnRuch(int *a, int *b)
    {
        for(;;)
        {
            if (*a>=1|| *a<=3)
            {
                break;
            }
            else *a=fnIA();
        }
        for(;;)
        {
            if (*b>=1|| *b<=3)
            {
                break;
            }
            else *b=fnIA();
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
            if (plansza[*a][*b]==88 || plansza[*a][*b]==89)
            {
              //  cout<<"\n IA Pole już jest zajete, podaj ponownie wspolrzedne: \n";
             //   *a=(rand()%3) +1;
             //   cout<<endl<<*a<<endl;
             //   cout<<endl<<*b<<endl;
              //  *b=(rand()%3) +1;
               fnLosowanie2(*a,*b);
            }
            else break;
        }
    }

    void fnSprawdzeniePola(int *a, int *b)
    {
      //  cout<<"\nsprw pola: "<<gracz1->fnGetGracz()<<endl;
        for(;;)
        {
            if (plansza[*a][*b]==88 || plansza[*a][*b]==89)
            {

                cout<<"\nPole już jest zajete, podaj ponownie wspolrzedne: \n";
                cout<<"\nWiersz: ";
                //cin>>*a;
                fnLosowanie2(*a,*b);
                cout<<endl<<*a<<endl;

                cout<<"\nKolumna: ";
                //cin>>*b;


                cout<<endl<<*b<<endl;

                int t=500;
                Sleep(t);

                fnRuch(a,b); //zabezpieczenie do wyjscia poza zakres
            }
            else break;
        }
       // system("cls");
    }
    void fnLosowanie2(int &n, int &m)
    {
        for (int i=1; i<m_n-1; i++)
        {
            for (int j=1; j<m_n-1; j++)
            {
             //   cout<<i<<" "<<j<<endl;
                if (plansza[i][j]!=88 && plansza[i][j]!=89)
                {
                 //   cout<<" fn losownaie 2 : ";
                    n=i;
                    m=j;
                }
            }
        }
    }

    int fnZwyciezca(char c_znak, cGracz* gracz)

    {
        fnWyswietl();
        cout<<" Zwyciezyl: "<<gracz->fnGetGracz()<<" grajacy "<<c_znak<<"!!"<<endl;
        exit (0);
    }

    void fnWyswRemis(char c_znak,cGracz* gracz)
    {
        cout<<"\n Plansza zostala zapelniona! \n";
        cout<<"\n REMIS !!! \n";
    }
};

/*==========================================================*/

void fnStart()
{

    cKolko *gra = new cKolko;
    gra->start();

 //   cKolko gra;
  //  gra.start();
    delete gra;
}

int main()
{
    fnStart();
    getch();
    getch();

    return 0;
}
