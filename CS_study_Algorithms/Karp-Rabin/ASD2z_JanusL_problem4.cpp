#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <cstring>

/*

Rabin–Karp Algorithms

Autor: £ukasz Janus
08.10.2017

*/

/*==========funkcja hashujaca - wzorzec=======*/

unsigned long long fnhash(char *w, unsigned long long n, int p, int q, unsigned long long h)
{
	unsigned long long  k = 1;
	int temp = 0; //gdyby ascii by³o ujemne, czyli powy¿ej 127 - do polskich znakow diakrytycznych
	for (unsigned long long i = n; i > 0; i--)
	{
		//std::cout << static_cast<int>(w[i-1]); //testowo - wyswietlanie ascii
		if (w[i - 1] < 0) temp = q;
		h += (w[i - 1] * k + q);
		k *= 10;
		//std::cout << w[i - 1]; //testowo - wyswietlanie liter
		temp = 0;
	}
	return h;
}

/*==========funkcja hashujaca 2 - wycinka z tekstu zrodlowego=======*/

unsigned long long t_hash(unsigned long long wycinek, char *t, unsigned long long m, int n, int p, int q, unsigned long long i)
{
	//cout <<"\n litery w petli: "<<endl;
	//tworzenie hasha na podstawie alfabetu i kodow ascii jako identyfikatorow liter - dla fragmentow przeszukiwanego tekstu
	unsigned long long k = 1;
	int temp = 0; //zabezpiecznie, gdyby ascii by³o ujemne - jw
	for (int j = n; j > 0; j--)
	{
		//std::cout << static_cast<int>(t[j+i - 1]); //liczby (kontrolnie)
		if (t[j + i - 1] < 0) temp = q;
		wycinek += k*t[j + i - 1] + q;
		k *= 10;
		//cout << t[j + i - 1]; //litery
		temp = 0;
	}
	return wycinek;
}

// wczytywanie tekstu - wzorzec + szukany

void start()
{
	int p = 257;
	int q = 263;
	string linia;
	string wzorzec;
	fstream plik;
	string nazwa_pliku;

	cin >> nazwa_pliku;
	//nazwa_pliku="tekst.txt";
	
	plik.open(nazwa_pliku, ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(plik, linia);
			//cout << linia;
			//plik>>linia;
		}
	}

	cin >> wzorzec;

	//cout << "\n test: wyrazy wczytane: " << wzorzec << " " << linia << endl;

	//kopiowanie stringa do chara:
	unsigned long long a = wzorzec.length() + 1;
	unsigned long long b = linia.length() + 1;
	char *w = new char[a];
	strcpy(w, wzorzec.c_str());
	char *t = new char[b];
	strcpy(t, linia.c_str());

	unsigned long long n = a;//sizeof(*w);
	n -= 1;
	unsigned long long m = b;//sizeof(*t);
	m -= 1;
	unsigned long long h = 1;
	h = fnhash(w, n, p, q, h);

	//============================

	//cout << " \ntest: " << a << " " << b << " hash wzorca:" << h << endl;
	unsigned long long wycinek = 1; //zmienna do porównania
	int licz = 0;

	for (unsigned long long i = 0; i <= m - n; i++)
	{
		wycinek = t_hash(wycinek, t, m, n, p, q, i); //wyliczenie hasha dla fragmentu tekstu
													 //cout<<" hash wycinka: "<<wycinek<<endl;
		if (h == wycinek)
		{
			licz++; //zliczanie wystapien po spelnieniu warunku równoœci hashy
		}
		wycinek = 1;
	}
	static int lp = 0;
	cout << lp << " " << licz << endl;
	lp++;

	delete[] t;
	delete[] w;
	plik.close();
}

int main()
{
	setlocale(LC_ALL, "polish");
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		start();
	}
	return 0;
}
