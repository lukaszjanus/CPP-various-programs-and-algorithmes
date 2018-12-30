#include "cEngine.h"
#include "cGame.h"
#include "cGracz.h"
#include "cFire.h"

#include <windows.h>
#include <time.h>

cEngine::cEngine() {};

cEngine::cEngine (int szer, int dl)
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

cEngine::~cEngine()
{
    delete shotD,shotL,shotP,shotG, shot;

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

void cEngine::fnBarricades(char **tab_org, int i, int j) //losowe tworzenie przeszkod
{
    int n=rand()%5;
    if (n==1)
    {
        tab_org[i][j]=35;
        tab_barricade[i][j]=35;
    }
}

void cEngine::fnSetBarricades(int x, int y) //usuniecie barykady w przypadku trafienia pociskiem
{
    tab_barricade[x][y]=32;
}

void cEngine::fnMove (int cZnak)
{
    static int i_xg1=1; //pozycje startowe - gracz
    static int i_yg1=1;

    static int i_xg2=m_szer-2; //pozycje startowe - komputer
    static int i_yg2=m_dl-2;

    static char cZnakKier; //kierunek strzelania - pobierana kopia cZnak w celu ostatniego kierunku ruch
    int cKierunek; //obliczony kierunek strzelania idzie do switcha, gdzie juz nastepuje strzal

    fnOdswiezenie(); //reset ekranu po zaktualizowaniu plansz

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
