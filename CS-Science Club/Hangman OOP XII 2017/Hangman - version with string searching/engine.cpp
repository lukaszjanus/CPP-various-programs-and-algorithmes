#include "engine.h"

#include <string>
#include <fstream>
#include <iostream>


/*===========Constructor===========*/

cEngine::cEngine(){};

/*===========Generating random text===========*/

void cEngine::fnGenerate(unsigned int iNumOfCharacters, unsigned int iAlphabet)
{
    srand(time(NULL));
    for (int i=0; i<iNumOfCharacters; i++) //zmienic na iNumofCharacters - jako poziom trudnosci
    {
        sText+=static_cast<char>(65+rand()%iAlphabet);//
    }
    //std::cout<<sText; //testowo wyswietlenie tekstu
}

/*===========Comparing texts===========*/

int cEngine::fnCompare(int i)
{
    unsigned int uText=sText.length();
    unsigned int uSzukany=sSzukany.length();

    for (int i=0; i<uText-uSzukany; i++)
    {
        if (sSzukany == sText.substr(i,uSzukany))
        {
            bCompare=true;
            break;
        }
        else
        {
            bCompare=false;
        }
    }

    if (bCompare==true)  //odgadniecie wyrazu
    {
       // std::cout<<"sukces"; //wyswietlenie obrazka
        ilevel=0;
        fnLevel(ilevel);
       // std::cout<<" compare sukces za fnLevel ";
        i=7;
        return i;
        //break;
    }

    if (bCompare==false)  //bledny wyraz
    {
        ilevel++;

        if (ilevel == 6 ) //ostatnia petla
        {
           // std::cout<<"porazka koncowa"; //wyswietlenie obrazka
            fnLevel(ilevel);
            return i;
        }
       // std::cout<<"porazka zwykla "; //wyswietlenie obrazka
        fnLevel(ilevel);
        return i;
    }
}

/*======levels in game (from file levels.txt)======*/

void cEngine::fnLevel(unsigned int ilevel)
{
    std::fstream fFile;
    fFile.open("levels.txt", std::ios::in | std::ios::out );

    if (fFile.good()== true )
    {

        int  aktualny_nr=1;//0+ilevel*7;
        int iNrLinii;

        /*======wyliczenie levelu: ========*/

        iNrLinii=ilevel*8;

        /*======  czytanie pliku   ========*/

        std::string wiersz;

        while (getline(fFile,wiersz))
        {
            if (aktualny_nr > iNrLinii && aktualny_nr <= iNrLinii+8)
            {
                std::cout<<wiersz<<std::endl;
            }
            aktualny_nr++;
        }
    }
    else MessageBox(HWND_DESKTOP,"Blad pliku levels.txt","Blad",MB_OK);

    fFile.close();
}

void cEngine::fnCheckLength()
{

    const unsigned int uSzukany=3;
    if (sSzukany.length()<3)
    {
        for (int i=sSzukany.length();i<3;i++)
        {
            sSzukany+="A";
        }
        //std::cout<<"\n\n"<<sSzukany;
    }

    if (sSzukany.length()>3)
    {
        sSzukany.erase(3);
        //std::cout<<"\ntest2\n"<<sSzukany<<" test2" ;
    }
}

/*======Sets and Gets======*/

void cEngine::fnSetsText(std::string sT)
{
    sText=sT;
}

std::string cEngine::fnGetsText()
{
    return sText;
}

void cEngine::fnSetsSzukany(std::string sSzuk)
{
    sSzukany=sSzuk;
}

std::string cEngine::fnGetsSzukany()
{
    return sSzukany;
}
