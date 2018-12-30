#include <iostream>

using namespace std;

/*
Lukasz Janus

Rozwi¹zywanie rownan rozniczkowych - Metoda Euler'a (siecznych) i Metoda Heune'go
Opiera siê o interpretacjê geometryczn¹ równania ró¿niczkowego:
y'=f(x,y) i warunki poczatkowe (x0,y0):y0=y(x0)


*/

int main()
{
    double x[100];
    double y1[100];
    double y2[100];

    x[0] = 1;
    y1[0] = 1;
    y2[0]= 1;

    cout << "Warunek poczatkowy: x0 = " << x[0] << ", y0 = " << y1[0] << endl;


    double h = 0.05;
    cout << "Krok rowny: " << h << endl;

   // int n=100; //liczba krokow
    int n=(h*100-x[0])/h; //liczba krokow
    cout << "Liczba krokow: " << n << endl;

    double row, row2;

    for(int i=0; i<n; i++)
    {
        //row = (x[i]+y1[i])/x[i]; //funkcja (x+y)/x
        //row = -2*(x[i]*x[i]*x[i])+12*(x[i]*x[i])-(20*x[i])+8.5;   //-2x^3+12x^2-20x+8.5
         row = 1+(y1[i]/x[i]); //1+ (y/x)

        x[i+1]=x[i]+h;

        //-------------m. Eulera

        y1[i+1]=y1[i]+h*row;

        //-------------m. Heuna
        row2 = (x[i+1]+y1[i+1])/x[i+1];
        y2[i+1]=y2[i]+h*((row+row2)/2);

        cout << "Dla x=" << x[i+1] << ", y(" << x[i+1] << "):"<<endl;
        cout << "Euler: " << y1[i+1] << endl<<"Heun: " << y2[i+1] << endl<<endl;
    }


    return 0;
}
