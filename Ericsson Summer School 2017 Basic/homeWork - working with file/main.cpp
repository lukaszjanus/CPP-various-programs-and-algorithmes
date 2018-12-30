#include <iostream>
#include <fstream>
using namespace std;

int fn_menu(int n)
{
  //  cout<<"\n 1. Kolumna2. 2 Kolumna 2i3. \n";
    //cin>>n;
    n=3;
    return n;
}

void fn_kol2(char *b)
{
    cout<<b<<endl;
}

void fn_kol_1_2(char *a,char *b)
{
    cout<<a<<" "<<b;
}
fn_jedna_kolumna(char *a, char *b, char *c)
{
    cout<<endl<<a<<" "<<b<<" "<<c<<endl;
}



int main()
{
    ifstream plik;
    plik.open("data.in");
    if( !plik.good() )
    {
        cout<<"\nBlad wczytywania\n";
        return false;
    }
    int i_iloscwierszy=0;
    char *a = new char[5];
    char b[5],c[5];
    int nr_wiersza=0;
    plik>>nr_wiersza; //wczytana piewrsza linija - ile przypadkow testowych;
    //cout<<" nr wiersza: "<<nr_wiersza;
    int wybor;
    int temp;
    wybor=fn_menu(wybor);
    if (wybor==3) cin>>temp;
   // cout<<wybor;
    int i=0;
    do
    {

        plik>>a;
        cout<<" ";
        plik>>b;
        cout<<" ";
        plik>>c;
        cout<<"\n";
        if (plik.good())
        {
            switch (wybor)
            {
            case 1:
                {
                    fn_kol2(b);
                    break;
                }
            case 2:
                {
                    fn_kol_1_2(a,b);
                    break;
                }
            case 3:
                {
                 //   cout<<" test: ";
                    if (i==temp-1)
                    {

                        fn_jedna_kolumna(a,b,c);
                        break;
                    }
                    break;
                }
            }

        }
        else break;

        i++;
      //  cout<<"\n wiersz nr "<<i<<endl;
    }
    while(true);


    return 0;
}
