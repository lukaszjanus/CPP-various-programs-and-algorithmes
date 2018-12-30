#include <iostream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <time.h>
#include <vector>

using namespace std;



class cGracz
{
private:
    string m_sName;
    string *m_sName2;

    cGracz *gracz1;
    cGracz *gracz2;

public:

    cGracz()
    {
        m_sName="Komputer";
    }

    cGracz(string sName2)
    {
        m_sName2= new string(sName2);
    }

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
        cout<<"\nPodaj imie: ";
        cin>>m_sName;
    }
};
class cFire;

class cEngine
{
protected:
    cGracz *gracz1;
    cGracz *gracz2;
    int m_szer;
    int m_dl;

    char **tab_org;
    char **tab_copy;

public:

    cEngine() {};
    cEngine (int szer, int dl)
    {
        gracz1=new cGracz;
        gracz2=new cGracz;

        m_dl=dl;
        m_szer=szer;
        tab_org= new char*[m_szer];
        tab_copy= new char*[m_szer];

        for (int i=0; i<m_szer; i++)
        {
            tab_org[i]=new char[m_dl];
            tab_copy[i]=new char[m_dl];
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
        }
        delete[] tab_copy;
        delete[] tab_org;
    }

    virtual void fnView()=0;
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

/*=====================================*/

class cGame: public cEngine
{
protected:

    cFire *shotG;// = new cFire;
    cFire *shotD;// = new cFire;
    cFire *shotL;// = new cFire;
    cFire *shotP;// = new cFire;
    cFire *shot;

public:
    cGame() {};

    cGame(int szer, int dl):cEngine(szer,dl)
    {
        shotG = new cFire;
        shotD = new cFire;
        shotL = new cFire;
        shotP = new cFire;
        shot = new cFire;
    };

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

    void fnStart()
    {
        cout<<"\n Zaczynamy!!! \n";

        // fnWyborGraczy();

        for(;;)
        {
            //_sleep(100);

            fnMove();
            fnView();
        }
    }

    /*=====================================*/

    void fnWyborGraczy()
    {
        cout<<"Czy grasz z komputerem (press 'k') czy z czlowiekiem press 'c')?\n";
        char cZnak;
        cin>>cZnak;

        switch (cZnak)
        {
        case 'c':
        {
            cout<<"\n Podaj nazwe pierwszego gracza: \n";
            gracz1->fnNazwaGracza();
            cout<<"\n Podaj nazwe drugiego gracza: \n";
            gracz2->fnNazwaGracza();
            break;
        }
        case 'k':
        {
            cout<<"\n Podaj swoje imie : \n";
            gracz1->fnNazwaGracza();
            break;
        }
        }
        cout<<"\n Pojedynek odbedzie sie pomiedzy: \n";
        cout<<gracz1->fnGetGracz()<<" vs "<<gracz2->fnGetGracz()<<"\n";
    }

    void fnMove()
    {
        static char cZnak;
        static char cZnak2;

        if (kbhit())
        {
            {
                cZnak=getch();
            }
            while(kbhit()) getch();
            cZnak2=getch();
            while(kbhit()) getch();
        }
        //else _sleep(50);
        //else continue;




        static int i_xg1=5;
        static int i_yg1=5;

        static int i_xg2=10;
        static int i_yg2=10;

        int cKierunek;
        static char cZnakKier;

        int cKierunek2;
        static char cZnakKier2;

        system("cls");
        static int i_runda=0;
        i_runda++;

        cout<<"Ruchow: "<<i_runda<<"\n";

        /*------klawisze gracza1--------*/

        switch (cZnak)
        {
        case 's':
        {
            i_yg1--;
            if (i_yg1==0)
            {
                i_yg1+=1;
            }
            tab_copy[i_xg1][i_yg1]=2;
            break;
        }
        case 'f':
        {
            i_yg1++;
            if (i_yg1==m_dl-1)
            {
                i_yg1-=1;
            }
            tab_copy[i_xg1][i_yg1]=2;
            break;
        }
        case 'd':
        {
            i_xg1++;
            if (i_xg1==m_szer-1)
            {
                i_xg1-=1;
            }
            tab_copy[i_xg1][i_yg1]=2;
            break;
        }
        case 'e':
        {
            i_xg1--;
            if (i_xg1==0)
            {
                i_xg1+=1;
            }
            tab_copy[i_xg1][i_yg1]=2;
            break;
        }
        case 32: //fire
        {
            cKierunek=fnKier(cZnakKier);
            fnShots(i_xg1, i_yg1, cKierunek);
            tab_copy[i_xg1][i_yg1]=2;
            break;
        }
        default:
            tab_copy[i_xg1][i_yg1]=2;
        }

        /*------klawisze gracza2--------*/

        switch (2)
        {
        case '4':
        {
            i_yg2--;
            if (i_yg2==0)
            {
                i_yg2+=1;
            }
            tab_copy[i_xg2][i_yg2]=1;
            break;
        }
        case '6':
        {
            i_yg2++;
            if (i_yg2==m_dl-1)
            {
                i_yg2-=1;
            }
            tab_copy[i_xg2][i_yg2]=1;
            break;
        }
        case '5':
        {
            i_xg2++;
            if (i_xg2==m_szer-1)
            {
                i_xg2-=1;
            }
            tab_copy[i_xg2][i_yg2]=1;
            break;
        }
        case '8':
        {
            i_xg2--;
            if (i_xg2==0)
            {
                i_xg2+=1;
            }
            tab_copy[i_xg2][i_yg2]=1;
            break;
        }
        case 48: //fire2
        {
            cKierunek2=fnKier(cZnakKier2);
            fnShots(i_xg2, i_yg2, cKierunek2);
            tab_copy[i_xg2][i_yg2]=1;
            break;
        }
        default:
        {
            tab_copy[i_xg2][i_yg2]=1;
        }
        }

        /*------obliczenia pociskow - dol--------*/

        for (int i=1; i<shotD->getSize(); i++)
        {
            int x=shotD->getX(i);
            int y=shotD->getY(i);
            x++;
            shotD->swapVect(x,y,i);
            if(x==m_szer-1)
            {
                shotD->fnErase(i);
            }
            else tab_copy[x][y]=shotD->fnGetAmmo();//68;
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
            else tab_copy[x][y]=shotG->fnGetAmmo();//71;
        }

        /*------obliczenia pociskow - prawo--------*/

        for (int i=1; i<shotP->getSize(); i++)
        {
            int x=shotP->getX(i);
            int y=shotP->getY(i);
            y++;
            shotP->swapVect(x,y,i);
            if(y==m_dl-1)
            {
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
            else tab_copy[x][y]=shotP->fnGetAmmo();//76;
        }

        /*------aktualizacja planszy--------*/

        for (int i=1; i<m_szer-1; i++)
        {
            for (int j=1; j<m_dl-1; j++)
            {
                tab_org[i][j]=tab_copy[i][j];
                tab_copy[i][j]=32;
            }
        }

        /*======zakonczenie rozgrywki==========*/
        if (tab_org[i_xg2][i_yg2]==  shot->fnGetAmmo() || tab_org[i_xg1][i_yg1] == shot->fnGetAmmo() )
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

            cout<<endl<<" Koniec! ";
            getch();
            exit (0);
        }
        cZnakKier=cZnak2;
        cout<<cZnakKier;
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
            cout<<" lewo ";
            shotP->setVect(x,y);
            break;
        }
        case 2: //lewo
        {
            cout<<" prawo ";
            shotL->setVect(x,y);
            break;
        }
        case 3: //dol
        {
            cout<<" dol ";
            shotD->setVect(x,y);
            break;
        }
        case 4: //gora
        {
            cout<<" gora ";
            shotG->setVect(x,y);
            break;
        }
        }
    }

    virtual void fnView()=0;
};

/*===========interface konsola ============*/

class cTxt:public cGame //virtual view
{
public:

    cTxt() {};
    cTxt(int szer, int dl):cGame(szer,dl) {}; //musz¹ byæ konstruktory;
    ~cTxt() {};

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
    }
};


int main()
{
    cGame *gra = new cTxt(21,31);
    gra->fnStart();
    delete gra;

    return 0;
}
