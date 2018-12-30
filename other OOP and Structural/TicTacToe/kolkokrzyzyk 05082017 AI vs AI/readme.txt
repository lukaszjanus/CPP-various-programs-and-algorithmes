Tic Tac Toe (Kolko-Krzyzyk) v 1.0

Jest to pierwsza wersja tej gry, wi�c prosz� o wyrozumia�o��. :)

Gra w sumie napisana dzi�ki kursowi - codzienne �wiczenia pozwoli�y mi zrozumie� w pewnym stopniu klasy, dziedziczenie i polimorfizm.

Docelowo b�d� jeszcze zmiany w uk�adzie metod + jedna dodatkowa klasa, kt�ra b�dzie odpowiada� za wy�wietlanie w konsoli. W razie potrzeby t� klas� od��czam i mam gotowy silnik, kt�ry mog� pr�bowa� implementowa� pod API (cel d�ugoterminowy).

Gr� napisa�em teraz w weekend w ok. 4 godziny -  nie s� porobione jeszcze wszystkie zabezpieczenia, w destruktorach brakuje niszczenia planszy i metody odpowiadaj�cej za ruchy komputera. Za cel kr�tkoterminowy postawi�em sobie jednak zrobienie wersji dzia�aj�cej na klasach i pozwalaj�cej ju� zagra� z drug� osob�. Optymalizacja i zabezpieczenia b�d� w drugiej kolejno�ci.

Schemat:

Klasa bazowa IKolko - (spe�nia warunki na klasa abstrakcyjn� dzi�ki metodzie wy�wietl(), ale na tym etapie jest chyba zb�dna) - jej zadanie to tworzenie planszy; tablica zrobiona dynamicznie, bo jest trudniejsza od zwyk�ej.

cKolko - klasa dziedzicz�ca po IKolko- tu jest obecnie rozgrywana cala gra, czyli zape�nianie planszy, wy�wietlanie, sprawdzanie, ko�czenie gry w przypadku remisu/zwyci�stwa.

cGracz - klasa przechowuj�ca imiona graczy - jedno domy�lne ("komputer"), drugie wprowadzane r�cznie; ca�o�� obs�ugiwana w klasie cKolko.

Pobie�ny opis metod umie�ci�em w nag��wku pliku.

To tak w skr�cie - bardziej traktuj� ten kr�tki programik jako utrwalenie i rozszerzenie wiedzy z kursu, oswojenie si� z nowymi narz�dziami.

Udanej zabawy!

�ukasz Janus 