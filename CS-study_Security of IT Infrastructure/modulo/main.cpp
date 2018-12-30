#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

/* wyliczenie dzia³ania   a do potegi b modulo c    */

unsigned long long fnWynik(unsigned long long a, unsigned long long b, unsigned long long c) //nwd
{
    unsigned long long temp=a; //g a p

    for (int i=1;i<b;i++)
    {
        temp=(temp*a)%c;
    }

    cout<<"wynik: "<< temp<<" ";
    return temp;
}


// niedokonczona
unsigned long long fnModulo(int a, int b, int c)
{
    unsigned long long temp;

    if (b==1)
    {
        temp=a%c;
        return temp;
    }
    else if (b==0)
    {
        return 1;
    }
    else if (b>1)
    {
        temp=fnWynik(a,b,c);
        return temp;
    }


}

int main()
{
    /* //dla ponizszych wynik 699
    int a=123;
    int b=456;
    int c=789;
    cout<<fnWynik(a,b,c);
    */

    unsigned long long  g,a,p,B,k;

    cout<<" Podaj g: ";
    cin>>g;
    cout<<" Podaj a: ";
    cin>>a;
    cout<<" Podaj p: ";
    cin>>p;

    unsigned long long  A=fnWynik(g,a,p);
    //unsigned long long  A=fnWynik(82,5,7);
    cout<<endl<<" Wynik A: "<<A;

    cout<<endl<<" Podaj B: ";
    cin>>B;

    k=fnWynik(B,a,p);

    cout<<endl<<" Wynik k: "<<k;

   //wersja z rekurencja (niedokonczona, potegi binarnie)
    a=82;
    int b=5;
    int c=7;

    // int a=2;
    //int b=13;
    //int c=10;

    cout<<fnModulo(a,b,c);

    getch();
    return 0;
}
