#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

/* reverse modulo    */

int fnWynik(int a, int b)
{

    int *tabR = new int[0];
    int *tabS = new int[0];
    int *tabQ = new int[0];
    if (a<b)
    {
        tabR[0]=b;
        tabR[1]=a;

        tabS[1]=1;  //dwie piewrsze wartoœci b³êdnie
        tabS[0]=a/b;
    }
    if (b<a)
    {
        tabR[0]=a;
        tabR[1]=b;

        tabS[0]=b/a;
        tabS[1]=1;
    }
    tabQ[0]=tabQ[1]=0;
    // cout<<"test: "<<tabR[0]<<" "<<tabS[0]<<"Tab1: "<<tabR[1]<<tabS[1]<<endl;
    cout<<0<<" Q: "<<tabQ[0]<<" R: "<<tabR[0]<<" S: "<<tabS[0]<<endl;
    cout<<1<<" Q: "<<tabQ[1]<<" R: "<<tabR[1]<<" S: "<<tabS[1]<<endl;
    int i=1;
    while( tabR[i]!=1)
    {
        i++;
        tabQ[i]=tabR[i-2]/tabR[i-1];
        tabR[i]=tabR[i-2]%(tabR[i-1]);
        tabS[i]=tabS[i-2]-(tabQ[i]*tabS[i-1]);
        cout<<i<<" Q: "<<tabQ[i]<<" R: "<<tabR[i]<<" S: "<<tabS[i]<<endl;
        //if (tabR[i]==1) break;

        getch();
    }

    //while (true);

    cout<<"Wynik pod indeksem nr "<<i<<" Q: "<<tabQ[i]<<" R: "<<tabR[i]<<" S: "<<tabS[i]<<endl;

    return 0;
}


// niedokonczona
unsigned long long fnRevModulo(int a, int b, int c)
{

}

int main()
{
    /* //dla ponizszych wynik 699
    int a=123;
    int b=456;
    int c=789;
    cout<<fnWynik(a,b,c);
    */


    int a,b;

    cout<<" Podaj a: ";
    cin>>a;
    //a=7;
    cout<<" Podaj b: ";
    //b=10;
    cin>>b;

    cout<<"\n";
    fnWynik(a,b);

    getch();
    return 0;
}
