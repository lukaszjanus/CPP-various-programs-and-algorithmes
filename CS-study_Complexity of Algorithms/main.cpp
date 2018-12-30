#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <conio.h>

/*

Program na zaliczenie laboratorium informatycznego - porownanie czasow wykonania trzech algorytmow wyszukiwania wzorca w tekscie:
- Karp-Rabin (mozna go jeszcze lekko poprawic)
- algorytm naiwny
- Morris Prat

Compare time of three algorithms with different strings:
- Karp-Rabin
- Naive string-search
- Morris-Prat

Lukasz Janus

07/02/2018


*/

using namespace std;

unsigned int fnNaiwny( string sTekst, string sWzorzec, unsigned int iTekst, unsigned int iWzorzec)
{
    unsigned int iOperacje=0;
    unsigned int i;
    //cout<<"Naiwny start"<<endl;
    for(i = 0; i < iTekst-iWzorzec; i++)
    {
        //cout << (sWzorzec == sTekst.substr(i,iWzorzec) ? "^" : " ");
        if (sWzorzec == sTekst.substr(i,iWzorzec))
        {
            iOperacje++;
            //cout<<"^";
        }
    }
    //cout<<"Naiwny stop"<<endl;
    return iOperacje;
}

unsigned int fnMP(string sTekst, string sWzorzec, unsigned int iTekst, unsigned int iWzorzec)
{
    int iPI[iWzorzec + 1],b,pp;

    unsigned int iOperacje=0;
    int i;

    iPI[0] = b = -1;
    for(i = 1; i <= iWzorzec; i++)
    {
        while((b > -1) && (sWzorzec[b] != sWzorzec[i - 1])) b = iPI[b];
        iPI[i] = ++b;
    }


    pp = b = 0;
    for(i = 0; i < iTekst; i++)
    {
        while((b > -1) && (sWzorzec[b] != sTekst[i])) b = iPI[b];
        if(++b == iWzorzec)
        {
            iOperacje++;
            while(pp < i - b + 1)
            {
                //cout << " ";
                pp++;
            }
            //cout << "^";
            pp++;
            b = iPI[b];
        }
    }

    return iOperacje;
}

/*======================karp rabin==============================*/

//unsigned int fnhash(char *w, unsigned int n, int p, int q, unsigned int h)
unsigned int fnhash(string w, unsigned int n, int p, int q, unsigned int h)
{
    unsigned int  k = 1;
    int temp = 0; //gdyby ascii by³o ujemne, czyli powy¿ej 127 - do polskich znakow diakrytycznych
    for (unsigned int i = n; i > 0; i--)
    {
        if (w[i - 1] < 0) temp = q;
        h += (w[i - 1] * k + q);
        k *= 10;
        temp = 0;
    }
    return h;
}

/*==========funkcja hashujaca 2 - wycinka z tekstu zrodlowego=======*/

//unsigned int t_hash(unsigned int wycinek, char *t, unsigned int m, unsigned int n, int p, int q, unsigned int i)
unsigned int t_hash(unsigned int wycinek, string t, unsigned int m, unsigned int n, int p, int q, unsigned int i)
{
    unsigned int k = 1;
    int temp = 0;
    for (int j = n; j > 0; j--)
    {
        if (t[j + i - 1] < 0) temp = q;
        wycinek += k*t[j + i - 1] + q;
        k *= 10;
        temp = 0;
    }

    return wycinek;
}


unsigned int fnKR(string sTekst, string sWzorzec, unsigned int iTekst, unsigned int iWzorzec)
{

    const unsigned int p = 257;
    const unsigned int q = 263;

    const unsigned int n = iWzorzec;
    const unsigned int m = iTekst;

    unsigned int h = 1;
    //h=fnhash(sWzorzec, n, p, q, h);
    unsigned int  k = 1;
    int temp = 0; //gdyby ascii by³o ujemne, czyli powy¿ej 127 - do polskich znakow diakrytycznych
    for (unsigned int i = n; i > 0; i--)
    {
        if (sWzorzec[i - 1] < 0) temp = q;

        h += (sWzorzec[i - 1] * k + q);
        k *= 10;
        temp = 0;
    }

    //============================

    unsigned int wycinek = 1;
    int iOperacje = 0;

    for (unsigned int i = 0; i <= m - n; i++)
    {
        //wycinek = t_hash(wycinek, sTekst, m, n, p, q, i);
        unsigned int k = 1;
        int temp = 0;
        for (int j = n; j > 0; j--)
        {
            if (sTekst[j + i - 1] < 0) temp = q;
            wycinek += k*sTekst[j + i - 1] + q;
            k *= 10;
            temp = 0;
        }


       if (h == wycinek)iOperacje++; //zakomentowanie nie ma wp³ywu na algorytm
       wycinek = 1;
    }

    return iOperacje;
}
/*
unsigned int fnKR2(string sTekst, string sWzorzec, unsigned int iTekst, unsigned int iWzorzec)
{
    //cout<<sWzorzec;
    const unsigned int p = 257;
    const unsigned int q = 263;

    //kopiowanie stringa do chara:
    const unsigned int a = iWzorzec + 1;
    const unsigned int b = iTekst + 1;

    char *w = new char[a];
    strcpy(w, sWzorzec.c_str());
    char *t = new char[b];
    strcpy(t, sTekst.c_str());

    unsigned int n = a-1;
    unsigned int m = b-1;
    unsigned int h = 1;
    h=fnhash(w, n, p, q, h);

    //============================

    //cout << " \ntest: " << a << " " << b << " hash wzorca:" << h << endl;
    unsigned int wycinek = 1; //zmienna do porównania
    int iOperacje = 0;

    for (unsigned int i = 0; i <= m - n; i++)
    {
        wycinek = t_hash(wycinek, t, m, n, p, q, i); //wyliczenie hasha dla fragmentu tekstu
        if (h == wycinek)iOperacje++; //zliczanie wystapien po spelnieniu warunku równoœci hashy
        wycinek = 1;
    }

    delete[] t;
    delete[] w;

    return iOperacje;
}
*/

/*

int h(string & x)
{
  int i, hx;

  hx = 0;
  for(i = 0; i < 26; i++)
    hx = 3 * hx + (x[i] - 65);
  return hx;
}


const int zp = 65;  // kod pierwszego znaku alfabetu
const int zk = 67;  // kod ostatniego znaku alfabetu

void Karp(string sTekst, string sWzorzec, unsigned int iTekst, unsigned int iWzorzec)
{

const int N  = iTekst;  // d³ugoœæ ³añcucha s
const int M  = iWzorzec;

string s=sTekst,p=sWzorzec;
  int pp,i,Hp,Hs;

  // obliczamy hasz wzorca

  Hp = h(p);

  // obliczamy hasz okna wzorca

  Hs = h(s);

  // szukamy pozycji wzorca w ³añcuchu

  pp = i = 0;

  while(true)
  {
    if((Hp == Hs) && (p == s.substr(i,M)))
    {
      while(pp < i)
      {
        cout << " "; pp++;
      }
      cout << "^"; pp++;
    }
    i++;
    if(i == N - M) break;
    Hs = (Hs-(s[i-1]-65)*27)*3+s[i+M-1]-65;
  }
  cout << endl;
}

*/

void start()
{
    string sTekst="",sWzorzec="";
    unsigned int i;
    //const unsigned int iT=1000000, iW=26;

    unsigned int iT=1000000, iW=26;
    cout<<"\nProsze podac dlugosc lancucha znakow (tekst, w ktorym szukamy,\n(min. 100.000): ";
    cin>>iT;
    cout<<"\nProsze podac dlugosc wzorca (tekst wyszukiwany, min 2 znaki): ";
    cin>>iW;

    srand((unsigned)time(NULL));

/*=====tekst===========*/


    for(i = 0; i <iT; i++) sTekst += char(65 + (rand() % 26 ));
/*=====wzorzec===========*/

    for(i = 0; i < iW; i++) sWzorzec += char(65 + (rand() % 26));

    const unsigned int iTekst=sTekst.length();
    const unsigned int iWzorzec=sWzorzec.length();

    cout<<"\n\nDlugosc Tekstu: "<<iTekst<<", dlugosc wzorca: "<<iWzorzec<<", szukany tekst: "<<sWzorzec;
    //cout<<sTekst<<endl;


    /*=========poczatek algorytmu Naiwnego:======*/

    unsigned long tCzasN=0;
    unsigned int iOperacjeNaiwne=0;

    for (i=0; i<10; i++)
    {
        clock_t start = clock();
        iOperacjeNaiwne+=fnNaiwny( sTekst, sWzorzec, iTekst, iWzorzec);
        //fnNaiwny( sTekst, sWzorzec, iTekst, iWzorzec);
        tCzasN+=(static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000);
    }
     cout<<"\nCzas N: "<<tCzasN;
    //cout<<"\nOperacji: "<<iOperacjeNaiwne;


    /*=========poczatek algorytmu MP:======*/

    unsigned long tCzasMP=0;
    unsigned int iOperacjeMP=0;

    for (i=0; i<10; i++)
    {
        clock_t start = clock();
        iOperacjeMP+=fnMP( sTekst, sWzorzec, iTekst, iWzorzec);
        //fnMP( sTekst, sWzorzec, iTekst, iWzorzec);
        tCzasMP+=(static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000);
    }
    cout<<"\nCzas MP: "<<tCzasMP;
    //cout<<"\nOperacji: "<<iOperacjeMP;


    /*=========poczatek algorytmu KR:======*/

    unsigned long tCzasKR=0;
    unsigned int iOperacjeKR=0;

    for (i=0; i<10; i++)
    {
        clock_t start = clock();
        iOperacjeKR+=fnKR( sTekst, sWzorzec, iTekst, iWzorzec);
        //fnKR( sTekst, sWzorzec, iTekst, iWzorzec);
        tCzasKR+=(static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000);
    }
    cout<<"\nCzas KR: "<<tCzasKR;
    //cout<<"\nOperacji: "<<iOperacjeKR;


    /*=========poczatek algorytmu KR - string:======*/
/*
        cout<<"\n\nAlgorytm KR - char:";
        unsigned long tCzasKR2=0;
        unsigned int iOperacjeKR2=0;

        for (i=0; i<10; i++)
        {
            clock_t start = clock();
            //iOperacjeKR+=fnKR( sTekst, sWzorzec, iTekst, iWzorzec);
            //fnKR2( sTekst, sWzorzec, iTekst, iWzorzec);
            Karp(sTekst, sWzorzec, iTekst, iWzorzec);

            tCzasKR2+=(static_cast<long>(clock() - start)*CLOCKS_PER_SEC/1000);
        }
        cout<<"\nCzas: "<<tCzasKR2;
        //cout<<"\nOperacji: "<<iOperacjeKR2;
*/

}

int main()
{
    for(int i=0;i<15;i++)
    {
        start();
        //getch();
    }

    return 0;
}
