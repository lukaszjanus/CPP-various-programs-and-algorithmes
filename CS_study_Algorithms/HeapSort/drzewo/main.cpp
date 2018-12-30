#include <iostream>
#include <cstdlib>
#include <time.h>

/*
05-2017
Lukasz Janus

Algorytmy i Struktury Danych I

Program sort numbers in tree.

On start you need type:
-



*/
using namespace std;

//heap sort

int main()
{

    int n, m, k;
    int lewy, prawy;
    int temp;

    cout<<"Enter number of cases do you want to sort:"<<endl;
    cin >> k;

    for (int d = 0; d < k; d++)
    {
        cout<<"Enter numbers to sort:"<<endl;
        cin >> n;

        int *Tab = new int[n + 1];

        cout<<"Enter numbers:"<<endl;

        for (int i = 1; i <= n; i++)
        {
            cin >> Tab[i];
        }
        //wyswietlanie kontrolne losowo wypelnionej tablicy

        cout<<"Start:"<<endl;

        for (int i = 1; i <= n; i++)
        {
            //cout << Tab[i] << " ";
//            if (d[i-1] == d[i]) d[i] = rand() % 40;
        }

        //tworzenie kopca z danych z tablicy
        //	cout << endl;
        for (int i = 1; i <= n; i++)
        {
            lewy = i;
            prawy = lewy / 2;
            temp = Tab[i];
            while (prawy > 0 && Tab[prawy] < temp)
            {
                Tab[lewy] = Tab[prawy];
                lewy = prawy;
                prawy = lewy / 2;
            }
            Tab[lewy] = temp;
        }

        for (int i = n; i > 1; i--)
        {
            for (int j = 1; j <= i; j++)
                cout << Tab[j] << " ";
            swap(Tab[1], Tab[i]);
            lewy = 1;
            prawy = 2;
            while (prawy < i)
            {
                if ((prawy + 1 < i) && (Tab[prawy + 1] > Tab[prawy]))
                    m = prawy + 1;
                else
                    m = prawy;
                if (Tab[m] <= Tab[lewy])
                    break;
                swap(Tab[lewy], Tab[m]);
                lewy = m;
                prawy = lewy + lewy;
            }
            cout << endl;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << Tab[i] << " ";
        }
        cout << endl<<endl;
        delete[] Tab;
    }
    return 0;
}
