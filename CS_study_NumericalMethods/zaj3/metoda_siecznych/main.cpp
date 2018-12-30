#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

/*=============================================
£ukasz Janus
metoda siecznych - obliczanie dla funkcji:
f(x)= x^3+x^2*4-10
Punkty startowe (dobrane wg. podrêcznika T.Wibig'a analogiczne, jak dla metody falsi daj¹ ten sam wynik w 6 przebiegach);
x1=1;
x2=2;
===============================================*/

double f(double x);

int main()
{

    //double x1=1;
    //double x2=2;
    double x1;
    double x2;
    cout<<"podaj x1: ";
    cin>>x1;
    cout<<"podaj x2: ";
    cin>>x2;

    double x3;
    int i=60; //iloœæ przebiegów;
    double fy1;
    double fy2, fy3;
    double f0;

    fy1=f(x1);
    fy2=f(x2);
    cout<<"\nx1: "<<x1<<"; fy1 "<<fy1<<"; x2: "<<x2<<"; fy2 "<<fy2<<endl;
    cout<<"\nObliczenia przeciêcia:\n";
    const double prec=0.000000000000001;
    cout<<setprecision(15)<<fixed;
    while (i && (fabs(x1-x2)>prec))
    {
        if (fabs(fy1-fy2)<prec) cout<<"Brak miejsca zerowego w tym przedziale!!";

        x3=(x2*fy1-x1*fy2)/(fy1-fy2);//obliczenie punktu przeciêcia z osi¹ na podstawie wzoru metody siecznych
        f0=f(x3); //wyliczenie miejsca zerowego z funkcji

        if(fabs(f0)<prec) break; //gdy jest osi¹gniêta precyzja (15 miejsc po przecinku), pêtla przerywana
                                //wynik wyœwietlany poza pêtl¹
        //przypisanie zmiana wartoœci danych wejœciowych do kolejnej pêtli, jeœli nie jest osi¹gniêta wymagana dok³adnoœæ
        x2=x1;
        fy2=fy1;
        x1=x3;
        fy1=f0;
        //wyniki poœrednie:
        cout<<"\nx1: "<<x1<<" fy1 "<<fy1<<" x2: "<<x2<<" fy2 "<<fy2<<" x3: "<<x3<<" f0 "<<f0<<endl;
    }
    cout << "\n\n wynik ostateczny: x0 = "  << x3 << endl;
    return 0;
}

double f(double x)
{
    return (x*x*x)+(x*x*4)-10;
}
