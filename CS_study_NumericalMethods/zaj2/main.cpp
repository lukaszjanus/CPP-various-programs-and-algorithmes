#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

/*
Cubic Spline

Łukasz Janus, niestacjonarne, gr I

Metody Numeryczne
zaj z dn. 08-04-2017

Dane wprowadzone na sztywno z tabelki z zajęć; zakomentowana wersja z danymi wprowadzanymi ręcznie;
dane poprawne dla funkcji: S(x) = a(i)+ b(i)*t+c(i)*t^2+d(i)*t^3


*/

int main()
{
    cout << "Hello world!" << endl;


    int n=5; //liczba wezlow
    float f_x[n]= {1,2,3,4,5};
    float f_y[n]= {1,0.5,0.33,0.25,0.2};
//    float f_x[n];
    //float f_y[n];
    float f_h[n];
    float f_Ui[n];
    float f_Wi[n];
    float f_Vi[n];
    float f_Ci[n];
    f_Ci[0]=f_Ci[n-1]=0;
    float f_di[n];
    f_di[n]=f_di[n-1]=0;
    float f_bi;
    float f_bn[n];
    float f_A[n];

    //opcjonalnie wprowadzenie danych ręcznie
    /*
        cout<<"Podaj dane wejsiowe:\n";
        for (int i=0; i<5; i++)
        {
            cout<<"X nr "<<i+1<<":\n";
            cin>>f_x[i];
        }
        for (int i=0; i<5; i++)
        {
            cout<<"Y nr "<<i+1<<":\n";
            cin>>f_y[i];
        }
        */
    cout<<"\nDane wejsciowe: \n";
    for (int i=0; i<n; i++)
    {
        cout<<"x("<<i<<")="<<f_x[i]<<", y("<<i<<")="<<f_y[i]<<endl;
    }

    /* ------------h(i)--------------------------*/
    for (int i=0; i<n-1; i++)
    {
        f_h[i] = f_x[i+1]-f_x[i];
    }
    f_h[n-1]=1;
    //cout<<"\n h(i): \n"<<endl;


    for (int i=0; i<n; i++)
    {
        // cout<<f_h[i] <<endl;
    }
    /* ------------U(i)--------------------------*/
    for (int i=1; i<n-1; i++)
    {
        f_Ui[i]=((f_h[i-1])/(f_h[i-1]+f_h[i]));
    }

    // cout<<"\n U(i): \n"<<endl;
    for (int i=1; i<n-1; i++)
    {
        //   cout<<f_Ui[i]<<endl;
    }


    /* ------------W(i)--------------------------*/
    //cout<<"\n W(i): \n"<<endl;
    for (int i=1; i<n-1; i++)
    {
        f_Wi[i]=((f_h[i])/(f_h[i-1]+f_h[i]));
        //   cout<<f_Wi[i]<<endl;
    }

    /*----------------v(i)------------------------*/

    //cout<<"\n V(i): \n"<<endl;
    for (int i=1; i<n-1; i++)
    {
        f_Vi[i]=(((((1/f_x[i+1])-(1/f_x[i]))/f_h[i])-(((1/f_x[i])-(1/f_x[i-1]))/f_h[i-1])) / (f_h[i-1]+f_h[i]));
        // cout<<f_Vi[i]<<" "<<endl;
    }
    /*----------------wyznacznik macierzy------------------------*/

    float detA= 2*2*2-2*f_Ui[3]*f_Ui[2]-2*f_Ui[2]*f_Ui[1];
    //cout<<endl<<"Wyznacznik glowny macierzy: "<<detA<<endl;

    /*----------------C(i)------------------------*/
    //cout<<"\n C(i): \n"<<endl;
    for (int i=1; i<n-1; i++)
    {
        f_Ci[i]=(8*f_Vi[i]-2*f_Vi[i+1])/5;
    }
    for (int i=0; i<n; i++) //cout<<f_Ci[i]<<endl;
        /*----------------d(i)------------------------*/

        f_di[n]=f_di[n-1]=0;
    for (int i=0; i<(n-1); i++)
    {
        f_di[i]=( (f_Ci[i+1]-f_Ci[i])/(3*f_h[i])    );
    }
    //cout<<"\n D(i): \n"<<endl;
    for (int i=0; i<n; i++)
    {
        //  cout<<f_di[i]<<endl;
    }
    /*----------------b(i)------------------------*/

    f_bi=((1/f_h[0] )* ( f_y[1]- f_y[0] - f_Ci[0]* f_h[0]* f_h[0] - f_di[0]* f_h[0]* f_h[0]* f_h[0]));
    //cout<<"\n b(i): \n"<<endl;
    //  cout<<f_bi<<endl;
    f_bn[0]=f_bi;
    /*----------------b(n)------------------------*/
    //cout<<"\n b(n): \n"<<endl;
    for (int i=0; i<n-1; i++)
    {
        f_bn[i+1]=(f_bn[i]+(2*f_Ci[i]*f_h[i])+(3*f_di[i]*f_h[i]*f_h[i]));
    }

    for (int i=0; i<n; i++)
    {
        //      cout<<f_bn[i]<<endl;
    }

    /*----------------f_A(n)------------------------*/
    //cout<<"\n A(n): \n"<<endl;
    for (int i=0; i<n; i++)
    {
        f_A[i]=f_y[i];
    }
    for (int i=0; i<n; i++)
    {
        // cout<<f_A[i]<<endl;
    }
    /*----------------końcowe wyniki dla wspolczynnikow ------------------------*/
    cout<<"\n wynik: \n"<<endl;
    cout<<"Funkcja dla przedzialu nr 1:  y="<<f_A[0]<<"+("<<f_bn[0]<<")*(x-"<<f_x[0]<<")+"<<f_di[0]<<"*(x-"<<f_x[0]<<")^3"<<endl;
    cout<<"Funkcja dla przedzialu nr 2:  y="<<f_A[1]<<"+("<<f_bn[1]<<")*(x-"<<f_x[1]<<")+"<<f_Ci[1]<<"*(x-"<<f_x[1]<<")^2)-"<<f_di[0]<<"*(x-"<<f_x[1]<<")^3"<<endl;
    cout<<"Funkcja dla przedzialu nr 3:  y="<<f_A[2]<<"+("<<f_bn[2]<<")*(x-"<<f_x[2]<<")"<<endl;

    cout<<"\n Podaj podaj x, mieszczacy sie w podanych przedziałach:\n"<<endl;

    for (int i=1; i<=3; i++)
    {
        cout<<"Zakres nr "<<i<<" to ("<<f_x[i]<<","<<f_x[i+1]<<")\n";
    }

    float x;
    cin>>x;

    if (x>f_x[1] && x<f_x[2]) cout<<(f_A[0]+(f_bn[0])*(x-f_x[0])+f_di[0]* ( (x-f_x[0])*(x-f_x[0])*(x-f_x[0])));
    if (x>f_x[2] && x<f_x[3]) cout<<(f_A[1]+(f_bn[1])*(x-f_x[1])+f_di[1]* ( (x-f_x[1])*(x-f_x[1])*(x-f_x[1])));
    if (x>f_x[3] && x<f_x[4]) cout<<(f_A[2]+(f_bn[2])*(x-f_x[2])+f_di[2]* ( (x-f_x[2])*(x-f_x[2])*(x-f_x[2])));


    delete [] f_x;
    delete [] f_y;
    delete [] f_h;
    delete [] f_Ui;
    delete [] f_Wi;
    delete [] f_Vi;
    delete [] f_di;
    delete [] f_bn;
    delete [] f_A;

    return 0;
}
