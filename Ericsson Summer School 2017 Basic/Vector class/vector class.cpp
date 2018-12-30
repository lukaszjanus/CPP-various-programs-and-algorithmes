// Wojciech Grze�kowiak, Album: 200884, Grupa: G1ISIII
// Opis kontenera Vector.

//sciagniete z netu

#include<iostream>
#include<algorithm>
#include<boost/assert.hpp> 
// Ay u�ywac kontenera std:vector nale�y do��czy� plika nag��wkowy vector.
#include<vector>

using namespace std;

// Szablon funkcji do wypisywania wszystkich element�w
// vector�w niezale�nie od tego jakie obiekty trzymaj�.

template<class T> void printVector(const vector<T> & _v)
{
	// size() zwraca nam liczb� element�w w vektorze.
	for(int i = 0; i < _v.size(); ++i)
		cout << _v[i] << ' ';
	cout << endl;
}

// G�owna funkcja.
int main()
{
	// Tworzymy pusty vector liczb.
	vector<int> liczby1;

	// Dodajemy do kontenera liczby1 9, 8, 7 ...
	// gdzie ka�da kolejna wrzucana jest na koniec.
	for(int i = 9; i >= 0; --i)
		liczby1.push_back(i);

	// W tym momencie nasz vector wygl�da tak:
	// Indeks:  [0|1|2|3|4|5|6|7|8|9]
	// Warto��: [9|8|7|6|5|6|3|2|1|0]
	// Size:	10

	cout << "Liczby1: "; printVector<int>(liczby1);

	// Wyci�gni�cie liczby z pod indeksu mo�na zrobic na dwojaki spos�b:
	int liczba6_s1 = liczby1[6];		// Tutaj korzystamy z operatora [indeks].
	int liczba6_s2 = liczby1.at(6);		// Tutaj korzystamy z funkcji at(indeks).

	// To s� te same liczby.
	BOOST_ASSERT(liczba6_s1 == liczba6_s2);
	
	// Tworzymy nowy vector liczby kopiuj�c elementy z starego.
	vector<int> liczby2(liczby1);

	// Mamy wi�c identyczny vektor liczb.
	// Zwiekszmy jego rozmiar (size).
	liczby2.resize(liczby2.size() + 5, 33);

	// Funkcja size() zwr�ci�a nam liczb� element�w w vekorze. By�a ich tam 10.
	// Zwiekszyli�my rozmiar do 15, wiec dodano 5 element�w o warto�ci 
	// przekazanej w drugim parametrze czyli 33. Nasz vector liczby2 wygl�da teraz
	// nast�puj�co:
	// Indeks:  [0|1|2|3|4|5|6|7|8|9|10|11|12|13|14]
	// Warto��: [9|8|7|6|5|6|3|2|1|0|33|33|33|33|33]
	// Size:	15

	cout << "Liczby2: "; printVector<int>(liczby2);

	// Teraz chcieliby�my wszystkie lementy z vektora ilczby1 przeniesc
	// do liczby2 i odwrotnie. Za nas zrobi to funkcja swap().
	liczby1.swap(liczby2);

	cout << "Liczby1: "; printVector<int>(liczby1);
	cout << "Liczby2: "; printVector<int>(liczby2);

	// Vektory mo�na tak�e �atwo posrotowa�, u�ywaj�c algorytm�w sortowania.
	// Aby ich u�y� nale�y poda� zakres liczb do sortowania, zakres ten
	// podaje si� wykorzystuj�c iteratory. start() zwraca iterator wskazuj�cy
	// na pocz�tek vektora, end() na koniec.
	sort(liczby1.begin(), liczby1.end());

	// Nasze liczby s� ju� posortowane.
	// Indeks:  [0|1|2|3|4|5|6|7|8|9|10|11|12|13|14]
	// Warto��: [0|1|2|3|4|5|6|7|8|9|33|33|33|33|33]
	cout << "Liczby1: "; printVector<int>(liczby1);

	// Uw�rzmy kolejny vector, kopiuj� cniektore elmenty z poprzedniego.
	// Kopiujemy wszystko opr�cz 4 pierwszych i 2 ostatnich element�w,
	// podajac w�asnie takie iteratory.
	vector<int> liczby3(liczby1.begin() + 4, liczby1.end() - 2);

	// Indeks:  [0|1|2|3|4|5| 6| 7| 8]
	// Warto��: [4|5|6|7|8|9|33|33|33]
	cout << "Liczby3: "; printVector<int>(liczby3);

	// Funkcja pop_back() odrzuca ostatni element.
	// Wywo�ajmy ja 4 razy.
	for(int i = 0; i < 4; ++i)
		liczby3.pop_back();

	// Indeks:  [0|1|2|3|4]
	// Warto��: [4|5|6|7|8]
	cout << "Liczby3: "; printVector<int>(liczby3);

	// Funkcja push_back(val) wrzuca na koniec wartoc val.
	liczby3.push_back(0);
	liczby3.push_back(1);

	// Indeks:  [0|1|2|3|4|5|6]
	// Warto��: [4|5|6|7|8|0|1]
	cout << "Liczby3: "; printVector<int>(liczby3);

	return 0;
}