#include <iostream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <time.h>
#include <vector>

using namespace std;

/*
wersja 19-08-2017
Prosta gra - dwa punkty poruszaja sie i strzelaja do siebie:
- jeden sterowany przez czlowieka (klawisze: EDSF, strzal - spacja)
- drugi - liczby pseudolosowe
- przeszkody mozna niszczyc
- drobne bledy w poruszaniu sie pociskow (trafiam czasami sam siebie - na ten moment blad nie wiem, gdzie)
- bug pozwalajacy przechodzic przez sciany w okreslonych przypadkach, gdy postaci sa obok siebie (testowane bez strzelania)

*/

class cGracz
{
private:
    string m_sName;
    string *m_sName2;

public:

    cGracz():m_sName("Gracz 2(Komputer)") {};

    cGracz(string sName2)
    {
        m_sName2= new string(sName2);
    }

    /*==============metody=====================*/
    string fnGetGracz()
    {
        return m_sName;
    }

    void fnSetGracz(string sName)
    {
        m_sName=sName;
    }

    void fnNazwaGracza()
    {
        cin>>m_sName;
    }

    void fnDefault1()
    {
        m_sName="Gracz1";
    }
};

/*===========kontener na pociski====================*/
class cFire
{
    vector <int> m_x;
    vector <int> m_y;
    char m_Ammo=111;

public:

    cFire()
    {
        m_x.push_back(0);
        m_y.push_back(0);
    }

    ~cFire() {};

    /*==============metody=====================*/

    char fnGetAmmo()
    {
        return m_Ammo;
    }

    void setVect(int x, int y)
    {
        m_x.push_back(x);
        m_y.push_back(y);
    }

    int getX( int nr)
    {
        return m_x[nr];
    }

    int getY( int nr)
    {
        return m_y[nr];
    }

    int getSize()
    {
        return m_x.size();
    }

    void fnErase(int nr)
    {
        vector <int>::iterator a;
        a=m_x.begin()+nr;
        m_x.erase(a);

        vector <int>::iterator b;
        b=m_y.begin()+nr;
        m_y.erase(b);
    }

    void swapVect(int x, int y, int nr)
    {
        m_x[nr]=x;
        m_y[nr]=y;
    }
};

/*===============================*/

class cEngine
{
protected:
    cGracz *gracz1;
    cGracz *gracz2;
    int m_szer;
    int m_dl;

    char **tab_org;
    char **tab_copy;
    char **tab_barricade;

    cFire *shotG;// = new cFire;
    cFire *shotD;// = new cFire;
    cFire *shotL;// = new cFire;
    cFire *shotP;// = new cFire;
    cFire *shot;

public:

    cEngine() {};
    cEngine (int szer, int dl)
    {
        gracz1=new cGracz;
        gracz2=new cGracz;

        shotG = new cFire;
        shotD = new cFire;
        shotL = new cFire;
        shotP = new cFire;
        shot = new cFire;

        m_dl=dl;
        m_szer=szer;
        tab_org= new char*[m_szer];
        tab_copy= new char*[m_szer];
        tab_barricade= new char*[m_szer];
        srand ((time(NULL)));

        for (int i=0; i<m_szer; i++)
        {
            tab_org[i]=new char[m_dl];
            tab_copy[i]=new char[m_dl];
            tab_barricade[i]=new char[m_dl];
        }

        for (int i=0; i<m_szer; i++)
        {
            for (int j=0; j<m_dl; j++)
            {
                tab_org[i][0]=176;
                tab_org[i][m_dl-1]=176;
                tab_org[0][j]=176;
                tab_org[m_szer-1][j]=176;

                if (i>0 && i<m_szer-1 && j>0 && j<m_dl-1)
                {
                    tab_org[i][j]=32;
                    tab_barricade[i][j]=32;
                    fnBarricades(tab_org,i,j);
                }
                tab_copy[i][j]=tab_org[i][j];
                //cout<<tab_copy[i][j];
            }
            //cout<<endl;
        }
        //cout<<"\n\ntest\n\n";
    }

    virtual ~cEngine()
    {
        for (int i=0; i<m_szer; i++)
        {
            delete[] tab_org[m_dl];
            delete[] tab_copy[m_dl];
            delete[] tab_barricade[m_dl];
        }
        delete[] tab_copy;
        delete[] tab_org;
        delete[] tab_barricade;
    }

    /*==============metody=====================*/

    void fnBarricades(char **tab_org, int i, int j) //losowe tworzenie przeszkod
    {
        int n=rand()%5;
        if (n==1)
        {
            tab_org[i][j]=35;
            tab_barricade[i][j]=35;
        }
    }

    void fnSetBarricades(int x, int y) //usuniecie barykady w przypadku trafienia pociskiem
    {
        tab_barricade[x][y]=32;
    }

    void fnMove (int cZnak)
    {
        static int i_xg1=1; //pozycje startowe - gracz
        static int i_yg1=1;

        static int i_xg2=m_szer-2; //pozycje startowe - komputer
        static int i_yg2=m_dl-2;

        static char cZnakKier; //kierunek strzelania - pobierana kopia cZnak w celu ostatniego kierunku ruch
        int cKierunek; //obliczony kierunek strzelania idzie do switcha, gdzie juz nastepuje strzal

        fnOdswiezenie();

        /*------klawisze gracza1 i ruch gracz1--------*/
        fnRuchKier(&i_xg1, &i_yg1, cZnak);
        cKierunek=fnKier(cZnakKier);
        /*------ruch gracza 2(komputerowego)----------*/
        fnRuchKomp(&i_xg2,&i_yg2,&i_xg1, &i_yg1);
        /*-----określenie kierunku strzelania ----------*/
        if (cZnak==32)
        {
            fnShots(i_xg1, i_yg1, cKierunek);
            tab_copy[i_xg1][i_yg1]=2;
        }
        /*------obliczenia przemieszczania pociskow - dol--------*/
        for (int i=1; i<shotD->getSize(); i++)
        {
            int x=shotD->getX(i); //pobieram wspolrzedne pocisku i zapisuje w nowej zmiennej
            int y=shotD->getY(i);
            x++; //zmieniam polozenie jednej wspolrzednej
            shotD->swapVect(x,y,i); // zamieniam wartosc dla obu vectorow
            if(x==m_szer-1)
            {
                shotD->fnErase(i); //zderzenie z ramka
            }
            else if (tab_barricade[x][y]==35)
            {
                fnSetBarricades( x,  y); //zderzenie z przeszkoda
                shotD->fnErase(i); //usuniecie przeszkody
            }
            else tab_copy[x][y]=shotD->fnGetAmmo();//68; //jak zadne z powyzszych, to zapisujemy nowe polozenie pocisku
        }
        /*------obliczenia pociskow - gora--------*/
        for (int i=1; i<shotG->getSize(); i++)
        {
            int x=shotG->getX(i);
            int y=shotG->getY(i);
            x--;
            shotG->swapVect(x,y,i);
            if(x==0)
            {
                shotG->fnErase(i);
            }
            else if (tab_barricade[x][y]==35)
            {
                fnSetBarricades( x,  y);
                shotG->fnErase(i);
            }

            else tab_copy[x][y]=shotG->fnGetAmmo();//71;
        }
        /*------obliczenia pociskow - prawo--------*/
        for (int i=1; i<shotP->getSize(); i++)
        {
            int x=shotP->getX(i);
            int y=shotP->getY(i);
            y++;
            shotP->swapVect(x,y,i);
            if(y==m_dl-1) //zderzenie z ramka (mozna w sumie sciasnic w jednym if/e z ponizszymi;
            {
                shotP->fnErase(i);
            }
            else if (tab_barricade[x][y]==35) //zderzenie z przeszkoda
            {
                fnSetBarricades( x,  y);
                shotP->fnErase(i);
            }
            else tab_copy[x][y]=shotP->fnGetAmmo();//80;
        }

        /*------obliczenia pociskow - lewo--------*/

        for (int i=1; i<shotL->getSize(); i++)
        {
            int x=shotL->getX(i);
            int y=shotL->getY(i);
            y--;
            shotL->swapVect(x,y,i);
            if(y==0)
            {
                shotL->fnErase(i);
            }
            else if (tab_barricade[x][y]==35)
            {
                fnSetBarricades( x,  y);
                shotL->fnErase(i);
            }
            else tab_copy[x][y]=shotP->fnGetAmmo();//76;
        }

        /*------aktualizacja planszy--------*/

        for (int i=1; i<m_szer-1; i++)
        {
            for (int j=1; j<m_dl-1; j++)
            {
                tab_org[i][j]=tab_copy[i][j];
                tab_copy[i][j]=32;
                tab_copy[i][j]=tab_barricade[i][j];
            }
        }

        /*======zakonczenie rozgrywki==========*/
        fnZwyciestwo(i_xg1, i_yg1,i_xg2,i_yg2);

        cZnakKier=cZnak;
      //  cout<<cZnakKier; //testowo do kontroli ruchow obu graczy
    }

    virtual void fnOdswiezenie()=0; //odswierzenie ekranu, liczba petli (przy pojedynczych ruchach)
    virtual void  fnRuchKier(int *i_xg1, int *i_yg1, char cZnak)=0;
    virtual int fnKier(char cZnakKier)=0;//określanie kierunku ruchu gracza (potem tez zmienna kopiowana do okreslania kierunku strzalu
    virtual void fnRuchKomp(int *i_xg2,int *i_yg2, int *i_xg1,int *i_yg1)=0; //poruszanie się komputera
    virtual void fnShots(int x, int y, int cKierunek)=0; //generowanie strzalu (dodanie do tablicy wektor)
    virtual void fnZwyciestwo(int i_xg1, int i_yg1,int i_xg2,int i_yg2)=0; //ustawienie i wyswietlenie zwyciezcy
};


/*=====================================*/

class cGame: public cEngine
{
public:

    cGame() {};

    cGame(int szer, int dl):cEngine(szer,dl){};

    virtual ~cGame()
    {
        for (int i=0; i<m_szer; i++)
        {
            delete[] tab_org[m_dl];
            delete[] tab_copy[m_dl];
        }
        delete[] tab_copy;
        delete[] tab_org;

        delete shotD,shotL,shotP,shotG, shot;
    }

    /*==============metody=====================*/

    void fnStart()
    {
        fnPowitanie();
        fnWyborGraczy();

        for(;;)
        {
            fnMove2(cKlaw());
            fnView();
        }
    }

    char cKlaw()  //poruszanie gracza kommputerowego - pobranie klawisza i zapamietanie poprzedniego 'ruchu'
    {
        //static char Znak2;
        static char Znak='e';
  //      cout<<" znak: "<<Znak<<" znak 2: "<<Znak2<<endl; //roboczo - wyswietlanie, co pod ktora zmienna
        if (kbhit())
        {
            {
                //Znak2=Znak; //poruszanie sie i strzelanie jednoczesnie - sa bledy
                Znak=getch();
            }
            while(kbhit()) getch();
        }/*
        else if (Znak==32) //poruszanie sie i strzelanie jednoczesnie - czasami sa bledy
        {
            Znak=Znak2;
        }

        else if (Znak==NULL)
        {
            Znak='e'; //pozycja startowa
        } */
        else _sleep(75); //uruchomienie
        //else continue; //wczesniej ta czesc byla w petli

        return Znak;
    }
    /*=====================================*/
    void fnMove2(int cZnak)
    {
        fnMove (cZnak);
    }

    /*=============ruch komputera - przemieszczenie na planszy + strzelanie==========*/
    void fnRuchKomp(int *i_xg2,int *i_yg2, int *i_xg1,int *i_yg1)
    {
        //50-2(gora); 56-8(dol), 52-4(lewo),54- 6(prawo)
        static int cKier;
        int kier;
        kier=rand()%5+1;
        if (kier==1)
        {
            *i_yg2-=1;
            if (*i_yg2==0) //zderzenie z ramka
            {
                *i_yg2+=1;
            }
            if (tab_barricade[*i_xg2][*i_yg2]==35) //zderzenie z barykada
            {
                *i_yg2+=1;
            }
            if (tab_copy[*i_xg2][*i_yg2]==2) //zderzenie z drugim graczem
            {
                *i_yg2+=1;
            }
            tab_copy[*i_xg2][*i_yg2]=1;
            //cout<<*i_xg1<<" "<<*i_yg1<<endl;
        }
        if (kier==2)
        {
            *i_yg2+=1;
            if (*i_yg2==m_dl-1)
            {
                *i_yg2-=1;
            }
            if (tab_barricade[*i_xg2][*i_yg2]==35)
            {
                *i_yg2-=1;
            }
            if (tab_copy[*i_xg2][*i_yg2]==2) //zderzenie z drugim graczem
            {
                *i_yg2-=1;
            }
            tab_copy[*i_xg2][*i_yg2]=1;
        }
        if (kier==3)
        {
            *i_xg2+=1;
            if (*i_xg2==m_szer-1)
            {
                *i_xg2-=1;
            }
            if (tab_barricade[*i_xg2][*i_yg2]==35)
            {
                *i_xg2-=1;
            }
            if (tab_copy[*i_xg2][*i_yg2]==2) //zderzenie z drugim graczem
            {
                *i_xg2-=1;
            }
            tab_copy[*i_xg2][*i_yg2]=1;
        }
        if (kier==4)
        {
            *i_xg2-=1;
            if (*i_xg2==0)
            {
                *i_xg2+=1;
            }
            if (tab_barricade[*i_xg2][*i_yg2]==35)
            {
                *i_xg2+=1;
            }
            if (tab_copy[*i_xg2][*i_yg2]==2) //zderzenie z drugim graczem
            {
                *i_xg2+=1;
            }
            tab_copy[*i_xg2][*i_yg2]=1;
        }
        if (kier==5)
        {
            fnShots(*i_xg2, *i_yg2, cKier);
            tab_copy[*i_xg2][*i_yg2]=1;
        }
       // cout<<kier; //testowo do kontroli ruchow obu graczy
        cKier=kier;
    }

    /*=============ruch gracza - przemieszczenie na planszy==========*/

    void  fnRuchKier(int *i_xg1, int *i_yg1, char cZnak)
    {
        switch (cZnak)
        {
        case 's':
        {
            //cout<<" s: "<<cZnak;
            *i_yg1-=1;
            if (*i_yg1==0)
            {
                *i_yg1+=1;
            }
            if (tab_barricade[*i_xg1][*i_yg1]==35)
            {
                *i_yg1+=1;
            }
            if (tab_copy[*i_xg1][*i_yg1]==1) //poprawic
            {
                *i_yg1+=1;
            }
            tab_copy[*i_xg1][*i_yg1]=2;
            //cout<<*i_xg1<<" "<<*i_yg1<<endl;
            break;
        }
        case 'f':
        {
            *i_yg1+=1;
            if (*i_yg1==m_dl-1)
            {
                *i_yg1-=1;
            }
            if (tab_barricade[*i_xg1][*i_yg1]==35)
            {
                *i_yg1-=1;
            }
            if (tab_copy[*i_xg1][*i_yg1]==1) //poprawic
            {
                *i_yg1-=1;
            }
            tab_copy[*i_xg1][*i_yg1]=2;
            break;
        }
        case 'd':
        {
            *i_xg1+=1;
            if (*i_xg1==m_szer-1)
            {
                *i_xg1-=1;
            }
            if (tab_barricade[*i_xg1][*i_yg1]==35)
            {
                *i_xg1-=1;
            }
            if (tab_copy[*i_xg1][*i_yg1]==1) //poprawic
            {
                *i_xg1-=1;
            }
            tab_copy[*i_xg1][*i_yg1]=2;
            break;
        }
        case 'e':
        {
            *i_xg1-=1;
            if (*i_xg1==0)
            {
                *i_xg1+=1;
            }
            if (tab_barricade[*i_xg1][*i_yg1]==35)
            {
                *i_xg1+=1;
            }
            if (tab_copy[*i_xg1][*i_yg1]==1) //poprawic
            {
                *i_xg1+=1;
            }
            tab_copy[*i_xg1][*i_yg1]=2;
            break;
        }
        default:
            {
                tab_copy[*i_xg1][*i_yg1]=2;
                break;
            }

        }
    }

    int fnKier(char cZnak)
    {
        switch (cZnak)
        {
        case 'f':
        case '6':
        {
            return 1;//lewo
            break;
        }
        case 's':
        case '4':

        {
            return 2;//prawo
            break;
        }
        case 'd':
        case '5':
        {
            return 3;//dol
            break;
        }
        case 'e':
        case '8':
        {
            return 4;//gora
            break;
        }
        }
    }

    void fnShots(int x, int y, int cKierunek)
    {
        switch (cKierunek)
        {
        case 1: //prawo
        {
         //   cout<<" lewo "; //roboczo
            shotP->setVect(x,y);
            break;
        }
        case 2: //lewo
        {
         //   cout<<" prawo ";
            shotL->setVect(x,y);
            break;
        }
        case 3: //dol
        {
         //   cout<<" dol ";
            shotD->setVect(x,y);
            break;
        }
        case 4: //gora
        {
         //   cout<<" gora ";
            shotG->setVect(x,y);
            break;
        }
        }
    }

    virtual void fnPowitanie()=0; //napis witajacy gracza
    virtual void fnWyborGraczy()=0; //podanie imienia gracza glownego lub nie podawanie zadnego
    virtual void fnView()=0;
};

/*===========interface konsola ============*/

class cTxt:public cGame
{
public:

    cTxt() {};
    cTxt(int szer, int dl):cGame(szer,dl) {};
    ~cTxt() {};

    /*==============metody=====================*/

    void fnView()
    {
        cout<<endl;
        for (int i=0; i<m_szer; i++)
        {
            for (int j=0; j<m_dl; j++)
            {
                cout<<tab_org[i][j];
            }
            cout<<endl;
        }
        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n";
		
		cout<<"\n\nSterowanie:\n";
		cout<<"\nLewo - 'f'";
		cout<<"\nPrawo - 's'";
		cout<<"\nDo gory - 'e'";
		cout<<"\nDo dolu - 'd'";
		cout<<"\nStrzal - Spacja";
	
    }

    void fnPowitanie()
    {
        cout<<"\n Zaczynamy!!! \n";
		cout<<"\nZniszcz czarnego przeciwnika, unikaj jego pociskow,";
		cout<<"\nchowaj sie za przeszkodami,";
		cout<<"\nale uwazaj - przeszkody tez mozna zniszczyc!!\n";
    };

    void fnWyborGraczy()
    {
        cout<<"\nCzy chcesz podac swoje imie?\n";
		cout<<"Nacisnij 't' - tak, 'n' - nie (imiona domyslne) \n";
		char cZnak;
		cin>>cZnak;

		switch (cZnak)
		{
		case 't':
		case 'T':
		{
			cout<<"\n Podaj swoje imie : \n";
			gracz1->fnNazwaGracza();
			break;
		}
		case 'n':
		case 'N':
		default:
		{
			gracz1->fnDefault1();
			break;
		}
		}
        cout<<"\n Pojedynek odbedzie sie pomiedzy: \n";
        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n";
    }

    void fnOdswiezenie()
    {
        system("cls");
        static int i_runda=0;
        i_runda++;

        cout<<"Ruchow: "<<i_runda<<"\n";
    }

    void fnZwyciestwo(int i_xg1, int i_yg1,int i_xg2,int i_yg2)
    {
        if (tab_org[i_xg2][i_yg2]== shot->fnGetAmmo() || tab_org[i_xg1][i_yg1] == shot->fnGetAmmo() )
        {
            system("cls");
            cout<<endl;
            int t=500;
            for (int i=0; i<10; i++)
            {
                //Sleep(t);
                t-=50;
                cout<<".";
            }
            //cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n";
            if (tab_org[i_xg2][i_yg2]== shot->fnGetAmmo()) cout<<"\nTrafiony gracz: "<<gracz2->fnGetGracz()<<"\n";
            if (tab_org[i_xg1][i_yg1] == shot->fnGetAmmo()) cout<<"\nTrafiony gracz: "<<gracz1->fnGetGracz()<<endl;
            cout<<endl<<" Koniec! ";
            getch();
            exit (0);
        }
    }

};

int main()
{
    cGame *gra = new cTxt(10,25);
    gra->fnStart();
    delete gra;

    return 0;
}
