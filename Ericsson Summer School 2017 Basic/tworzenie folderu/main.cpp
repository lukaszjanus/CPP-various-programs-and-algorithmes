#include <iostream>
#include <windows.h>

//tworzenie folderu w c++ - mala sciaga

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

     CreateDirectory(TEXT(".\\import-export"), NULL); // .\\import-export - w lokalizacji pliku *.exe;
			//mozna rowniez normalna sciezke podac, np. "c:\\import-export" - tylko wtedy uprawnienia do zapisu na dysku moga sie pojawic

    return 0;
}
