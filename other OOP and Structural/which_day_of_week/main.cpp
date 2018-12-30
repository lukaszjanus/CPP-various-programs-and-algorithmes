#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string>

using namespace std;

/* program obliczajacy wstecz (trzy funkcje + main):
- dzien tygodnia
- wyswietlajacy dany miesiac z dniem tygodnia, liczac od pierwszego dnia miesiaca
*/

int Przestepny(int rok)
{
    if ( ((rok%4)==0) && ((rok%100)!=0) || ((rok%400)==0) ) return 1;
    else return 0;
}

/*algorytm kalendarza wiecznego: */

int f_dzienTyg(int d, int m, int y)
{
    int i;
    int x=0;
    for (i=1; i<y; i++)
        x += (7*31 + 4*30 + 28 + Przestepny(i))%7;
    for (i=1; i<m; i++)
    {
        if (i==2) x += 28 + Przestepny(y);
        else if (i<=7) x += 30 + (i%2);
        else x+= 31 - (i%2);
    }
    return (x+d)%7;
}

int szukanaData (int day, int mon, int year)
{
    cout<<"\nSzukana data to: "<<day<<" : "<<mon<<" : "<<year<<endl;

    char month_tab[43];
    for (int i=0; i<43; i++)
    {
        month_tab[i]=static_cast<int>(2);
    }

    int dzienTyg= f_dzienTyg( day, mon, year);

    string dni[]= {"xx","poniedzialek","wtorek","sroda","czwartek","piatek","sobota","niedziela"};
    if (dzienTyg==0)dzienTyg=7;
    cout<<"Szukany dzien tygodnia to nr: "<<dzienTyg<<", czyli: "<<dni[dzienTyg]<<endl<<endl;
/*obliczenie dnia tygodnia dla 1 dnia miesiąca: */
    cout<<"Wyswietlanie miesiaca:\n";
    int dzienTyg2= f_dzienTyg(1,mon,year);
    if (dzienTyg2==0)dzienTyg2=7;
    cout<<endl<<"Pierwszy dzien badanego miesiaca to nr: "<<dzienTyg2<<", czyli: "<<dni[dzienTyg2]<<endl;

    int d=1;
    for (int i=1; i<43; i++)
    {
        if (i==8 || i==15 || i==22 || i==29 || i==36)cout<<endl;
        if (mon==4 || mon ==6 || mon ==9 || mon == 11)
        {
            if (i>=dzienTyg2 && i<=31+dzienTyg2)
            {
                cout<<d;
                d++;
            }

            else cout<<month_tab[i];
        }

        if (mon==2)
        {
            if (year%4==0)
            {
                if (i>=dzienTyg2 && i<=28+dzienTyg2)
                {
                    cout<<d;
                    d++;
                }
                else cout<<month_tab[i];
                //if (dzienTyg2==1 && i>29) break;
            }
            if (year%4!=0)
            {
                if (i>=dzienTyg2 && i<28+dzienTyg2)
                {
                    cout<<d;
                    d++;
                }
                else cout<<month_tab[i];
            }
            if (i>34 && month_tab[i]==static_cast<int>(2)) break;

        }
        if (mon==1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
        {
            if (i>=dzienTyg2 && i<=30+dzienTyg2)
            {
                cout<<d;
                d++;
            }
            else cout<<month_tab[i];
        }
        cout<<" ";
    }
}

int main()
{
    tm SzukanyCzas = {0,0,0,0,0,0,0,0,0};
    tm AktualnyCzas = {0,0,0,0,0,0,0,0,0};
    tm RoznicaCzasu = {0,0,0,0,0,0,0,0,0};

    time_t Czas = time(NULL);
    AktualnyCzas  = (*localtime(&Czas));

    cout<<endl<<"Podaj date wstecz (dni max 31, miesiecy max 12: \n";

    cout<<"-dni: ";
    cin>>SzukanyCzas.tm_mday;
  //  SzukanyCzas.tm_mday=3;

    if (SzukanyCzas.tm_mday>31 || SzukanyCzas.tm_mday<0) return 0;
    cout<<"-miesiecy: ";
    cin>>SzukanyCzas.tm_mon;
  //  SzukanyCzas.tm_mon=5;

    if (SzukanyCzas.tm_mon >12 || SzukanyCzas.tm_mon < 0) return 0;

    cout<<"-lat: ";
    cin>>SzukanyCzas.tm_year;
//    SzukanyCzas.tm_year=2017;

    AktualnyCzas.tm_mon+=1;
    AktualnyCzas.tm_year+=1900;

    /*==przekroczenie zakresów (np. 4 stycznia, a ja odejmuje 5 dni i 3 miesiące): ==*/

    if (SzukanyCzas.tm_mday>=AktualnyCzas.tm_mday)
    {
        SzukanyCzas.tm_mday-=31;
        SzukanyCzas.tm_mon+=1;
        if (SzukanyCzas.tm_mon>=AktualnyCzas.tm_mon)
        {
            SzukanyCzas.tm_mon-=12;
            SzukanyCzas.tm_year+=1;
        }
    }
    if (SzukanyCzas.tm_mon>=AktualnyCzas.tm_mon)
    {
        SzukanyCzas.tm_mon-=12;
        SzukanyCzas.tm_year+=1;
    }

    /* obliczenia dat: */

    cout<<"\n Aktualny czas: dzien, miesiac, rok:\n"<<AktualnyCzas.tm_mday<<" "<<AktualnyCzas.tm_mon<<" "<<AktualnyCzas.tm_year<<" dzien tyg: "<<"\n\n";

    RoznicaCzasu.tm_mday = AktualnyCzas.tm_mday - SzukanyCzas.tm_mday;
    RoznicaCzasu.tm_mon = AktualnyCzas.tm_mon - SzukanyCzas.tm_mon;
    RoznicaCzasu.tm_year = AktualnyCzas.tm_year - SzukanyCzas.tm_year;

    /* warunki dla miesiêcy (ile dni: 30-31-28-29) i lat przestêpnych */
    if ((RoznicaCzasu.tm_mon==4 || RoznicaCzasu.tm_mon==6 ||RoznicaCzasu.tm_mon==9 || RoznicaCzasu.tm_mon==11) && RoznicaCzasu.tm_mday==31)
    {
        RoznicaCzasu.tm_mday-=1;
        cout<<"\n miesiace: kwiecien, czerwiec, wrzesien, listopad maja 30 dni,\n robie korekte -1 do mday.\n";
    }
    if ((RoznicaCzasu.tm_mon)==2)
    {
        switch (RoznicaCzasu.tm_mday)
        {
        case 29:
            if (RoznicaCzasu.tm_year%4!=0)
            {
                RoznicaCzasu.tm_mday-=1;
                cout<<"\n rok nie jest przestepny - robie korekte -1 do 28 lutego\n";
            }
            else cout<<"\nRok przestêpny.\n";
            break;

        case 30:
            if (RoznicaCzasu.tm_year%4!=0)
            {
                RoznicaCzasu.tm_mday-=2;
                cout<<"\n rok nie jest przestepny - robie korekte -2 do 28 lutego\n";
            }
            else
            {
                RoznicaCzasu.tm_mday-=1;
                cout<<"\n rok przestepny - robie korekte -1 do mday na 29 luty.\n";
            }
            break;
        case 31:
            if (RoznicaCzasu.tm_year%4!=0)
            {
                RoznicaCzasu.tm_mday-=3;
                cout<<"\n rok nie jest przestepny - robie korekte -2 do 28 lutego\n";
            }
            else
            {
                RoznicaCzasu.tm_mday-=2;
                cout<<"\n rok przestepny - robie korekte -2 do mday na 29 luty.\n";
            }
            break;
        }
    }

    /* wynik - opcjonalnie - ile dni od tamtej daty minęło: */
    // cout<<RoznicaCzasu.tm_mday<<" "<<RoznicaCzasu.tm_mon<<" "<<RoznicaCzasu.tm_year<<" dzien tyg: "<<endl;
    /*
        int Dni = ( SzukanyCzas.tm_year *365.25+SzukanyCzas.tm_mon* 30.4375 + SzukanyCzas.tm_mday);
        cout<<"dni przezyte (w przybli¿eniu): "<<Dni;
    */
    szukanaData(RoznicaCzasu.tm_mday,RoznicaCzasu.tm_mon,RoznicaCzasu.tm_year);

    return 0;
}
