// Wojciech Grzeœkowiak, Album: 200884, Grupa: G1ISIII
// Opis kontenera Vector.

//sciagniete z netu

#include<iostream>
#include<algorithm>
#include<boost/assert.hpp> 
// Ay u¿ywac kontenera std:vector nale¿y do³¹czyæ plika nag³ówkowy vector.
#include<vector>

using namespace std;

// Szablon funkcji do wypisywania wszystkich elementów
// vectorów niezale¿nie od tego jakie obiekty trzymaj¹.

template<class T> void printVector(const vector<T> & _v)
{
	// size() zwraca nam liczbê elementów w vektorze.
	for(int i = 0; i < _v.size(); ++i)
		cout << _v[i] << ' ';
	cout << endl;
}

// G³owna funkcja.
int main()
{
	// Tworzymy pusty vector liczb.
	vector<int> liczby1;

	// Dodajemy do kontenera liczby1 9, 8, 7 ...
	// gdzie ka¿da kolejna wrzucana jest na koniec.
	for(int i = 9; i >= 0; --i)
		liczby1.push_back(i);

	// W tym momencie nasz vector wygl¹da tak:
	// Indeks:  [0|1|2|3|4|5|6|7|8|9]
	// Wartoœæ: [9|8|7|6|5|6|3|2|1|0]
	// Size:	10

	cout << "Liczby1: "; printVector<int>(liczby1);

	// Wyci¹gniêcie liczby z pod indeksu mo¿na zrobic na dwojaki sposób:
	int liczba6_s1 = liczby1[6];		// Tutaj korzystamy z operatora [indeks].
	int liczba6_s2 = liczby1.at(6);		// Tutaj korzystamy z funkcji at(indeks).

	// To s¹ te same liczby.
	BOOST_ASSERT(liczba6_s1 == liczba6_s2);
	
	// Tworzymy nowy vector liczby kopiuj¹c elementy z starego.
	vector<int> liczby2(liczby1);

	// Mamy wiêc identyczny vektor liczb.
	// Zwiekszmy jego rozmiar (size).
	liczby2.resize(liczby2.size() + 5, 33);

	// Funkcja size() zwróci³a nam liczbê elementów w vekorze. By³a ich tam 10.
	// Zwiekszyliœmy rozmiar do 15, wiec dodano 5 elementów o wartoœci 
	// przekazanej w drugim parametrze czyli 33. Nasz vector liczby2 wygl¹da teraz
	// nastêpuj¹co:
	// Indeks:  [0|1|2|3|4|5|6|7|8|9|10|11|12|13|14]
	// Wartoœæ: [9|8|7|6|5|6|3|2|1|0|33|33|33|33|33]
	// Size:	15

	cout << "Liczby2: "; printVector<int>(liczby2);

	// Teraz chcielibyœmy wszystkie lementy z vektora ilczby1 przeniesc
	// do liczby2 i odwrotnie. Za nas zrobi to funkcja swap().
	liczby1.swap(liczby2);

	cout << "Liczby1: "; printVector<int>(liczby1);
	cout << "Liczby2: "; printVector<int>(liczby2);

	// Vektory mo¿na tak¿e ³atwo posrotowaæ, u¿ywaj¹c algorytmów sortowania.
	// Aby ich u¿yæ nale¿y podaæ zakres liczb do sortowania, zakres ten
	// podaje siê wykorzystuj¹c iteratory. start() zwraca iterator wskazuj¹cy
	// na pocz¹tek vektora, end() na koniec.
	sort(liczby1.begin(), liczby1.end());

	// Nasze liczby s¹ ju¿ posortowane.
	// Indeks:  [0|1|2|3|4|5|6|7|8|9|10|11|12|13|14]
	// Wartoœæ: [0|1|2|3|4|5|6|7|8|9|33|33|33|33|33]
	cout << "Liczby1: "; printVector<int>(liczby1);

	// Uwórzmy kolejny vector, kopiuj¹ cniektore elmenty z poprzedniego.
	// Kopiujemy wszystko oprócz 4 pierwszych i 2 ostatnich elementów,
	// podajac w³asnie takie iteratory.
	vector<int> liczby3(liczby1.begin() + 4, liczby1.end() - 2);

	// Indeks:  [0|1|2|3|4|5| 6| 7| 8]
	// Wartoœæ: [4|5|6|7|8|9|33|33|33]
	cout << "Liczby3: "; printVector<int>(liczby3);

	// Funkcja pop_back() odrzuca ostatni element.
	// Wywo³ajmy ja 4 razy.
	for(int i = 0; i < 4; ++i)
		liczby3.pop_back();

	// Indeks:  [0|1|2|3|4]
	// Wartoœæ: [4|5|6|7|8]
	cout << "Liczby3: "; printVector<int>(liczby3);

	// Funkcja push_back(val) wrzuca na koniec wartoc val.
	liczby3.push_back(0);
	liczby3.push_back(1);

	// Indeks:  [0|1|2|3|4|5|6]
	// Wartoœæ: [4|5|6|7|8|0|1]
	cout << "Liczby3: "; printVector<int>(liczby3);

	return 0;
}