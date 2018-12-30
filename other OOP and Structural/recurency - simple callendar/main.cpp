#include <iostream>

using namespace std;

int wysw (int n, int k);
int dni(int n, int k);

int main()
{
    cout << "Podaj numer dnia tygodnia (1-7) i iloœæ dni w miesi¹cu (28-31): " << endl;

    int a,b;
    //a=0;
    //b=31;

    cin>>a;
    cin>>b;
    if (a<0 || a>7 || b<28|| b>31) return 0;
    a-=1;

    if ((a+b)%7==0) cout<<endl;

    dni(a,b);


    return 0;
}

int licznik=0;

int dni(int n, int k)
{


    if (n>0)
    {
        cout<<" - ";
        licznik++;
        return dni(n-1,k);
    }
    if (n==0) wysw(k,k);
}

int wysw (int n, int k)
{
    int g =1;
    g-=n;
    cout<<g+k;
    if (g<0)
        {
            licznik++;
           // cout<<" licznik "<<licznik<<endl;
            if (licznik%7==0) cout<<endl;
            cout<<" ";
            return wysw(n-1,k);
    }
    if (g==0)
    {
        cout<<"\nkoniec"<<endl;
        return 0;
    }
}
