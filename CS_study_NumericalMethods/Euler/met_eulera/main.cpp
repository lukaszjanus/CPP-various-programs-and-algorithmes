#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <iostream>
using namespace std;

/*
Metody numeryczne 27-05-2017
Program liczy rozniczke metoda Eulera.

*/


int main()
{
    double yp= 1;
    double y;
    double x = 0.1;
    double h=0.1;
    //cout<<"Podaj h: \n";
    //cin>>h;
    double wynik;
    y = yp;
    cout<<"iter\t wynik\t\txi\t\ "<<y<<endl; //texp(-x)\t\troznica\n";
    for (int i=0; i<10; i++)
     {
        //cout<<endl<<endl;
        cout<<endl;
        cout<<i<<" y: "<<y<<" x "<<x<<" h: "<<h<<endl; //<<" wynik2: "<<wynik2<<" wynik3: "<<wynik3<<" wynik4: "<<wynik4<<endl;
        cout<<endl;
       // cout<<i<<" y/x "<<y/x<<" (y/x)+1: "<<(y/x)+1<<" *h "<<h*((y/x)+1);
        wynik = y + h*((x+y)/x); //<1-5>
        // wynik += y + h*(y/x);
       // wynik += y + h*((x*x*x)/2*y);
       // wynik += y + h*(x*x-4*x+y);
       // wynik += (y + h*((y/x)+1));
       // y+=wynik5;

        y=y+wynik;
        x += h;
        cout<<i<<" y (n): "<<y<<" wynik y(n-1): "<<wynik<<endl;
        //cout<<i<<" y + h*((x+y)/x): "<<wynik1<<" ## y + h*(y/x): "<<wynik2<<" ## y + h*((x^3)/2*y): "<<wynik3<<endl;
        //cout<<"  "<<" ## y + h*(x^2-4*x+y): "<<wynik4<<" ## (y + h*((y/x)+1)): "<<wynik5<<endl;
     //   getch();
    }

    cout<<"\n";
    return 0;
}
