#include "cGame.h"
#include "cEngine.h"

#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

cGame::cGame() {};
cGame::cGame(int szer, int dl):cEngine(szer,dl) {};
cGame::~cGame()
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

void cGame::fnStart()
{
    fnPowitanie();
    fnWyborGraczy();

    for(;;)
    {
        fnMove2(cKlaw());
        fnView();
    }
}

/*=====================================*/

void cGame::fnMove2(int cZnak)
{
    fnMove (cZnak);
}

/*=====================================*/

char cGame::cKlaw()  //poruszanie gracza kommputerowego - pobranie klawisza i zapamietanie poprzedniego 'ruchu'
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
        else if (Znak==32) //poruszanie sie i strzelanie jednoczesnie - pojawia sie blad, ktorego nie znalazlem
        {                   //czasami sam sie trafia
            Znak=Znak2;
        }

        else if (Znak==NULL)
        {
            Znak='e'; //pozycja startowa
        } */
    else _sleep(100); //uruchomienie
    //else continue; //wczesniej ta czesc byla w petli w innej lokalizacji

    return Znak;
}

/*=============ruch komputera - przemieszczenie na planszy + strzelanie==========*/

void cGame::fnRuchKomp(int *i_xg2,int *i_yg2, int *i_xg1,int *i_yg1)
{
    //ASCII: 50-2(gora); 56-8(dol), 52-4(lewo),54- 6(prawo) - komputer
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

void  cGame::fnRuchKier(int *i_xg1, int *i_yg1, char cZnak)
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

int cGame::fnKier(char cZnak)
{
    switch (cZnak)
    {
    case 'f':
    case 'F':
    {
        return 1;//lewo
        break;
    }
    case 's':
    case 'S':

    {
        return 2;//prawo
        break;
    }
    case 'd':
    case 'D':
    {
        return 3;//dol
        break;
    }
    case 'e':
    case 'E':
    {
        return 4;//gora
        break;
    }
    }
}

void cGame::fnShots(int x, int y, int cKierunek)
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
