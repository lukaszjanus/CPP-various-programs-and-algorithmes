#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <stdlib.h>

using namespace std;

long long fnNWD(long long a, long long b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return fnNWD(b, a%b);
}

long long fnPierwsza(long long a)
{
    int i;
    for(i = 2; i < a; i++)
    {
        if((a % i) == 0)
            return 0;
    }
    return 1;
}

long long fnPotegowanieModulo(long long a, long long b, long long c)
{
    long long result = a;

    for(int i = 1; i < b ; i++)
    {
        result = (result*a)%c;
    }

    return result;

}

long long fnReverseModulo(long long a, long long b)
{
    const int N = 1000;
    long long *q = new long long[N];
    long long *r = new long long[N];
    long long *s = new long long[N];

    q[1] = 0;
    q[2] = 0;
    r[1] = b;
    r[2] = a;
    s[1] = 0;
    s[2] = 1;
    int i = 1;
    //cout << "q = " << q[i] << " r = " << r[i] << " s = " << s[i] << endl;
    //cout << "q = " << q[i+1] << " r = " << r[i+1] << " s = " << s[i+1] << endl;

    while(1)
    {
        q[i+2] = r[i]/r[i+1];
        r[i+2] = r[i] - q[i+2]*r[i+1];
        s[i+2] = s[i] - q[i+2]*s[i+1];

        //cout << "q = " << q[i+2] << " r = " << r[i+2] << " s = " << s[i+2] << endl;

        if(r[i+2] == 1 && s[i+2] > 0)
        {
            return s[i+2];
        }
        else if(r[i+2] == 1 && s[i+2] < 0)
        {
            return s[i+2] + b;
        }
        else if(r[i+2] == 0)
        {
            return -1;
        }

        i++;
    }

    delete [] q;
    delete [] r;
    delete [] s;

}

int main()
{
    //srand(unsigned(time(NULL)));
    //long long wynik = fnReverseModulo(5, 11);    // zwraca 9 (s + b)
    //long long wynik = fnReverseModulo(7, 10);   // zwraca 3 (s)
    //long long wynik = fnReverseModulo(12767, 256);   // zwraca 31
    //long long wynik = fnReverseModulo(12768, 256);   // brak wyniku, zwraca -1
    //cout << "s = " << wynik << endl;

    long long p = 0, q = 0;     // l.pierwsze, p*q > 255

    do
    {
        cout << "Podaj p: ";
        cin >> p;
    }
    while (!fnPierwsza(p));
    do
    {
        cout << "Podaj q: ";
        cin >> q;
    }
    while (!fnPierwsza(q));

    long long n = p*q;
    cout << "n: " << n << endl;
    long long Nphi = (p - 1) * (q - 1);
    cout << "Fi = " << Nphi << endl;
    long long e = 0;    // fnNWD(Nphi, e) == 1, wzglednie pierwsze

    do
    {
        cout << "Podaj e: ";
        cin >> e;
        // e = rand() % Nphi;
    }
    while (fnNWD(Nphi, e) != 1 || e < 1 || e > Nphi);

    cout << "\ne = " << e << endl;

    long long d = fnReverseModulo(e, Nphi);       // odwrotne modulo (rozsz. Euklides)

    cout << "d = " << d << endl;

    string text;

    cin.ignore();
    cout << "\Tekst do zaszyfrowania: ";
    getline(cin, text);

    long long *c = new long long[text.length()];

    cout << "Tekst zaszyfrowany: ";

    for(int i = 0; i < text.length(); i++)
    {
        c[i] = fnPotegowanieModulo(text[i], e, n);   // poteg. modularne (szyfrowanie)
        cout << c[i];
    }

    cout << endl;
    cout << "Tekst oryginalny: ";

    for(int i = 0; i < text.length(); i++)
    {
        text[i] = fnPotegowanieModulo(c[i], d, n);   // poteg. modularne (dekodowanie)
        cout << text[i];
    }

    cout << endl << endl;

    return 0;
}
