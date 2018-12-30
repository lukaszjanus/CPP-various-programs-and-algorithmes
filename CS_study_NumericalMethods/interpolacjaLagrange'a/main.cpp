#include <iostream>
#include <conio.h>

using namespace std;

/*
Lukasz Janus

Interpolacja Lagrange'a - poszukujemy wielomianu stopnia nie wyzszego niz n,
takiebi, by Ln(xi)=fi dla i=0,2,3,...,n; i!=j, xi!=xj

Wybig - s.36

http://www.algorytm.org/procedury-numeryczne/interpolacja-lagrange-a.html
Przyk³adowe dane, x=5:
xi	    2	3	10
f(xi)	0	2	1

*/


int main()
{
    //tablice

    int n, value;
    double sum=0;

    cout<<"Podaj ilosc argumentow x i y ";
    cin>>n;
    cout<<"Podaj dla jakiego x liczymy wartosc: ";
    cin>>value;

    double *tabX = new double [n];
    double *tabY = new double [n];
    double *wspolczynniki = new double[n];


    for(int i=0;i<n; i++){
        cout<<"Podaj x nr "<<i+1<<": ";
        cin>>tabX[i];
        cout<<"Podaj y nr "<<i+1<<": ";
        cin>>tabY[i];
    }
//dla L(x) = y1l1(x) + y2l2(x) + y3l3(x)
//L(x) = y1((x-x2)/(x1-x2))*((x-x3)/(x1-x3))
//       + y2((x-x1)/(x2-x1))*((x-x3)/(x2-x3))
//       + y3((x-x1)/(x3-x1))*((x-x2)/(x3-x2))
//

    for(int i=0;i<n;i++){
        wspolczynniki[i] = tabY[i]; //startowy
        for(int j=0; j<n; j++){
            if(tabX[i]!=tabX[j]) {
                    wspolczynniki[i]*=(1.000*value - tabX[j]);
            }
        }
        for(int j=0;j<n;j++){
            if(tabX[i]!= tabX[j]) {
                    wspolczynniki[i]/= (1.000*tabX[i]-tabX[j]);
            }
        }
    }

    cout<<"Wynik:"<<endl;
    for(int i=0; i<n;i++){
        //if(i!=0)
        //cout<<" + ";
        sum+=(1.000*wspolczynniki[i]);
        //cout<<wspolczynniki[i];
    }
    cout<<sum<<endl;
    delete [] tabX,tabY,wspolczynniki;

    return 0;
}
