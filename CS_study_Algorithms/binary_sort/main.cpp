#include <math.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
/* 24-04-2016

Lukasz Janus

generuje liczby losowe zmiennoprzecinkowe (10 szt), zapisuje do tablicy funkcja tabl, nastepnie za pomoca
funkcji search podaje liczbe o wartoœci najblizszej do 7,5;
funkcja sortowanie - program sortuje babelkowo tablice od wartosci najmniejszych
funkcja binsearch - po przesortowaniu przeszukiwanie binarne wartosci tablicy dla wartości 7,5)

 )
*/

void tabl(double T[], int n);
void sortowanie(double T[], int n);
long search(double T[], int n, long& l);
long binsearch (double T[], int n, double d, long& l);
long licz1=0,licz2,licz3;
int n = 10;

/*--------------------MAIN------------------------*/
int main(int argc, char** argv)
{
	srand(100);


	double *T = new double[n];
	cout << "Wygenerowana tablica bez sortowania:" << endl;
	tabl(T, n);
	search(T, n,licz2);
	sortowanie(T,n);
	long i=	binsearch (T,10,7.5,licz3);

    cout<<("bublesearch result\t%f\t%d\n",T[i],licz2);
    cout<<("binsearch result\t%f\t%d\n",T[i],licz3);

	delete[]T;
	system("PAUSE");
	return 0;
}
/*------------------funkcja_tabl-----------------------------*/
void tabl(double T[], int n)
{
	for (int i = 0; i<n; i++)
	{
		T[i] = (20.*rand() / RAND_MAX);
		cout << fabs(T[i]) << endl;
	}
}
/*----------------------funkcja_search-----------------------------*/
long search(double T[], int n, long& l)
{
    l=0;
	double wynik = *T;
	for (int i = 0; i < n - 1; i++)
	{

		if (abs(7.5 - *(T + i))<abs(7.5 - wynik))
		{
		    l++;
		    wynik = *(T + i);
        }
	}
	cout << "Wartosc najblizsza do 7,5 to: " << abs(wynik) << endl;
	return wynik;
}
/*----------------------sortowanie_babelkowe-----------------------------*/
void sortowanie(double T[], int n)
{
	cout << "Tablica posortowana: " << endl;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (T[j] > T[j+1])
            swap(T[j],T[j+1]);

		}
	}
	for (int i = 0; i < n; i++)
    {
        cout <<T[i] << endl;
	}
}
/*----------------------wyszukiwanie_binarne-----------------------------*/
long binsearch (double T[], int n, double d, long& l)
{
    long imin=0,imax=n-1,ind;
    l=0;

    while (imax-imin>1)
    {
        l++;
        ind=(imax+imin)/2;
        if(d>T[ind])
            imin=ind;
        else
            imax=ind;
    }
    l++;
    if (fabs(T[imin]-d)<fabs(T[imax]-d))
    {
        return imin;
    }
    else
    {
        return imax;
    }
}

