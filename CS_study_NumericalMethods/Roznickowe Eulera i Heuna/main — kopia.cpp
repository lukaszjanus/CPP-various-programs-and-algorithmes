#include <iostream>

using namespace std;

//double funEuler(double x, double y, int h, int n);

int main()
{
/*
    double x[100];
    double y1[100];
    double y2[100];

    x[0] = 0;
    y1[0] = 1;
    y2[0]= 1;

    cout << "Warunek poczatkowy: x0 = " << x[0] << ", y0 = " << y1[0] << endl;

    int n=10; //liczba krokow
    cout << "Liczba krokow: " << n << endl;

    double h = 0.5;
    cout << "Krok rowny: " << h << endl;

    double row, row2;

    for(int i=0; i<n; i++)
    {
        row = -2*(x[i]*x[i]*x[i])+12*(x[i]*x[i])-(20*x[i])+8.5;   //moj przyklad

        x[i+1]=x[i]+h;
        //-------------m. Eulera
        y1[i+1]=y1[i]+h*row;

        //-------------m. Heuna
        row2 = -2*(x[i+1]*x[i+1]*x[i+1])+12*(x[i+1]*x[i+1])-(20*x[i+1])+8.5;   //moj przyklad
        y2[i+1]=y2[i]+h*((row+row2)/2);

        cout << "Dla x=" << x[i+1] << " ---> y(" << x[i+1] << ") = " << "m. Eulera: " << y1[i+1] << "  ||   m. Heuna: " << y2[i+1] << endl;
    }

    */

    //----------------------------------------------------------------------ZAD1
    double x[100];
    double y1[100];
    double y2[100];

    x[0] = 1;
    y1[0] = 1;
    y2[0]= 1;

    cout << "Warunek poczatkowy: x0 = " << x[0] << ", y0 = " << y1[0] << endl;
    int n=10; //liczba krokow
    cout << "Liczba krokow: " << n << endl;

    double h = 0.5;
    cout << "Krok rowny: " << h << endl;

    double row, row2;

    for(int i=0; i<n; i++)
    {
        row = (x[i]+y1[i])/x[i];

        x[i+1]=x[i]+h;
        //-------------m. Eulera
        y1[i+1]=y1[i]+h*row;

        //-------------m. Heuna
        row2 = (x[i+1]+y1[i+1])/x[i+1];
        y2[i+1]=y2[i]+h*((row+row2)/2);

        cout << "Dla x=" << x[i+1] << " ---> y(" << x[i+1] << ") = " << "m. Eulera: " << y1[i+1] << "  ||   m. Heuna: " << y2[i+1] << endl;
    }

    //----------------------------------------------------------------------ZAD2

    /*
    double x[100];
    double y1[100];
    double y2[100];

    x[0] = 1;
    y1[0] = 1;
    y2[0]= 1;

    cout << "Warunek poczatkowy: x0 = " << x[0] << ", y0 = " << y1[0] << endl;

    int n=10; //liczba krokow
    cout << "Liczba krokow: " << n << endl;

    double h = 0.5;
    cout << "Krok rowny: " << h << endl;

    double row, row2;

    for(int i=0; i<n; i++)
    {
        row = (y1[i])/x[i];

        x[i+1]=x[i]+h;
        //-------------m. Eulera
        y1[i+1]=y1[i]+h*row;

        //-------------m. Heuna
        row2 = (y1[i+1])/x[i+1];
        y2[i+1]=y2[i]+h*((row+row2)/2);

        cout << "Dla x=" << x[i+1] << " ---> y(" << x[i+1] << ") = " << "m. Eulera: " << y1[i+1] << "  ||   m. Heuna: " << y2[i+1] << endl;
    }

    */
    //----------------------------------------------------------------------ZAD3

    /*
    double x[100];
    double y1[100];
    double y2[100];

    x[0] = 1;
    y1[0] = 1;
    y2[0]= 1;

    cout << "Warunek poczatkowy: x0 = " << x[0] << ", y0 = " << y1[0] << endl;

    int n=10; //liczba krokow
    cout << "Liczba krokow: " << n << endl;

    double h = 0.5;
    cout << "Krok rowny: " << h << endl;

    double row, row2;

    for(int i=0; i<n; i++)
    {
        row = (x[i]*x[i]*x[i])/(2*y1[i]);

        x[i+1]=x[i]+h;
        //-------------m. Eulera
        y1[i+1]=y1[i]+h*row;

        //-------------m. Heuna
        row2 = (x[i+1]*x[i+1]*x[i+1])/(2*y1[i+1]);
        y2[i+1]=y2[i]+h*((row+row2)/2);

        cout << "Dla x=" << x[i+1] << " ---> y(" << x[i+1] << ") = " << "m. Eulera: " << y1[i+1] << "  ||   m. Heuna: " << y2[i+1] << endl;
    }
    */
        //----------------------------------------------------------------------ZAD4

    /*
    double x[100];
    double y1[100];
    double y2[100];

    x[0] = 1;
    y1[0] = 1;
    y2[0]= 1;

    cout << "Warunek poczatkowy: x0 = " << x[0] << ", y0 = " << y1[0] << endl;

    int n=10; //liczba krokow
    cout << "Liczba krokow: " << n << endl;

    double h = 0.5;
    cout << "Krok rowny: " << h << endl;

    double row, row2;

    for(int i=0; i<n; i++)
    {
        row = ((x[i]*x[i])-4*x[i]+y1[i]);

        x[i+1]=x[i]+h;
        //-------------m. Eulera
        y1[i+1]=y1[i]+h*row;

        //-------------m. Heuna
        row2 = ((x[i+1]*x[i+1])-4*x[i+1]+y1[i+1]);
        y2[i+1]=y2[i]+h*((row+row2)/2);

        cout << "Dla x=" << x[i+1] << " ---> y(" << x[i+1] << ") = " << "m. Eulera: " << y1[i+1] << "  ||   m. Heuna: " << y2[i+1] << endl;
    }

    */



    return 0;
}
