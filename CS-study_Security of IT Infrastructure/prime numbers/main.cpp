#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

/*
Autor: Lukasz Janus
04.06.2018

Program zaczêty na ostatnich zajêciach - dwie metody wyliczania liczb pierwszych: trialdivision (metoda próbnych dzieleñ) i Lucas-Lehmer
Niedokoñczony, ale kolokwium koñcowe zaliczone. :)

*/

bool trialdivision(int n)
{
    long long S=4;
    bool temp;
    int M=(pow(2,n))-1;
    //long long S=n;
    int pierwiastek=sqrt(n);
    //cout<<pierwiastek<<" ";
    do
    {

            S=(S*S-2)%M;
            cout<<S<<" ";
          //  cout<<S<<" ";
            if (S==0)
            {
                temp=true;
                break;
            }
            else temp = false;

    }
    while(S>0 && n<=pierwiastek);

    return temp;
}

bool LukasL(int p)
{
    bool temp;

    int wynik=pow(2,p)-1;
    //cout<<wynik<<" ";

    return temp;
}

int main()
{

    long long p;

    int tab[10]={3,5,7,11,13,17,19,23,29,31};

    //trialdivision(5);

    for(int i=0;i<10;i++)
    {
      cout<<i<<" "<<tab[i]<<" przetestowana: "<<trialdivision(tab[i])<<"\n";
    }
   // trialdivision(4);


    return 0;
}
