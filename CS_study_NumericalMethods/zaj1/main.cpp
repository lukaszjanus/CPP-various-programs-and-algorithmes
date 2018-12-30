#include <iostream>

using namespace std;

/*
Interpolacja liniowa i kwadratowa.

Metody numeryczne, zajecia I (zjazd III, dn. 18-03-2017)

£ukasz Janus

gr. I (niestacjonarne)

JL1
*/

float liniowa(float f_x[],float f_y[]);
float kwadratowa(float f_x[],float f_y[]);



int main()
{

    int n=5;

    //float f_x[]={1,2,17}; //dla x=1.7 (wprowadzany w funkcji) y=38.7
    //float f_y[]={31,42};

    //float f_x[]={1,1.1,1.2,1.3}; //dla x=1.15 y=0.4079 /dane z podręcznika Wybiga
    //float f_y[]={0.5403,0.4535,0.3623,0.2674};

    float f_x[]= {5,6,7}; //dla x=6.3 (wprowadzany w funkcji) y=7.8555
    float f_y[]= {3,7.2,8.3};

    cout<<liniowa(f_x,f_y)<<endl; //dla dwóch pierwszych punktów
    cout<<kwadratowa(f_x,f_y)<<endl; //dla dwóch pierwszych punktów

    return 0;
}

float liniowa(float f_x[],float f_y[])
{
    int w=1;  //numer węzła - interpolacja liniowa

    cout<<"\n podaj nr wezla (0 lub 1 dla danych wprowadzonych sztywno):\n";
    //cin>>w;
    //cout<<"\n x z przedziału: "<<f_x[w]<<" i "<<f_x[1+w]<<",\n f(y)wynosza odpowiednio: "<<f_y[w]<<" i "<<f_y[1+w]<<endl;
    float x=1.15;
    //cin>>x;

    cout<<"\nWynik - interpolacja liniowa: \n";
    return f_y[w]+( (f_y[1+w]-f_y[w])/(f_x[1+w]-f_x[w]) ) * (x-f_x[w]);
}

float kwadratowa(float f_x[],float f_y[])
{
    int w=0;    //numer węzła - interpolacja kwadratowa

    //cout<<"\n podaj nr wezla (0 lub 1 dla danych wprowadzonych sztywno):\n";
    //cin>>w;
    //cout<<"\n podaj x:\n";
    float x=6.3;
    //cin>>x;

    cout<<"\n\nWynik - interpolacja kwadratowa: \n";
    float d=(((x-f_x[1+w])*(x-f_x[2+w]))/((f_x[0+w]-f_x[1+w])*(f_x[0+w]-f_x[2+w])))*f_y[0+w]+(((x-f_x[0+w])*(x-f_x[2+w]))/((f_x[1+w]-f_x[0+w])*(f_x[1+w]-f_x[2+w])))*f_y[1+w]+(((x-f_x[0+w])*(x-f_x[1+w]))/((f_x[2+w]-f_x[0+w])*(f_x[2+w]-f_x[1+w])))*f_y[2+w];
    return d;
}
