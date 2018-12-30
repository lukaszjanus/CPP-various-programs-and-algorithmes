Tic Tac Toe (Kolko-Krzyzyk) v 1.0

Jest to pierwsza wersja tej gry, wiêc proszê o wyrozumia³oœæ. :)

Gra w sumie napisana dziêki kursowi - codzienne æwiczenia pozwoli³y mi zrozumieæ w pewnym stopniu klasy, dziedziczenie i polimorfizm.

Docelowo bêd¹ jeszcze zmiany w uk³adzie metod + jedna dodatkowa klasa, która bêdzie odpowiadaæ za wyœwietlanie w konsoli. W razie potrzeby t¹ klasê od³¹czam i mam gotowy silnik, który mogê próbowaæ implementowaæ pod API (cel d³ugoterminowy).

Grê napisa³em teraz w weekend w ok. 4 godziny -  nie s¹ porobione jeszcze wszystkie zabezpieczenia, w destruktorach brakuje niszczenia planszy i metody odpowiadaj¹cej za ruchy komputera. Za cel krótkoterminowy postawi³em sobie jednak zrobienie wersji dzia³aj¹cej na klasach i pozwalaj¹cej ju¿ zagraæ z drug¹ osob¹. Optymalizacja i zabezpieczenia bêd¹ w drugiej kolejnoœci.

Schemat:

Klasa bazowa IKolko - (spe³nia warunki na klasa abstrakcyjn¹ dziêki metodzie wyœwietl(), ale na tym etapie jest chyba zbêdna) - jej zadanie to tworzenie planszy; tablica zrobiona dynamicznie, bo jest trudniejsza od zwyk³ej.

cKolko - klasa dziedzicz¹ca po IKolko- tu jest obecnie rozgrywana cala gra, czyli zape³nianie planszy, wyœwietlanie, sprawdzanie, koñczenie gry w przypadku remisu/zwyciêstwa.

cGracz - klasa przechowuj¹ca imiona graczy - jedno domyœlne ("komputer"), drugie wprowadzane rêcznie; ca³oœæ obs³ugiwana w klasie cKolko.

Pobie¿ny opis metod umieœci³em w nag³ówku pliku.

To tak w skrócie - bardziej traktujê ten krótki programik jako utrwalenie i rozszerzenie wiedzy z kursu, oswojenie siê z nowymi narzêdziami.

Udanej zabawy!

£ukasz Janus 