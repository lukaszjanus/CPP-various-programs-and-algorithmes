#include "engine.h"


/*===========Constructor===========*/

cEngine::cEngine() {};

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
    unsigned int iLicznik;
    unsigned int uText=sText.length();
    unsigned int uSzukany=sSzukany.length();

    for (int g=0; g<uText; g++)
    {
        if (sSzukany==sOdnaleziony.substr(g,uSzukany)) iPoints--;
    }

    for (int j=0; j<=uText; j++) //correct character
    {
        if (sSzukany == sText.substr(j,uSzukany))
        {
            iPoints++;
            sOdnaleziony.erase(j,1);
            sOdnaleziony.insert(j,sSzukany);
        }
    }

    if (sOdnaleziony==sText)  //win
    {
        ilevel=0;
        fnLevel(ilevel);
        i=7;
        return i;
    }

    else      //incorrect character
    {
        ilevel++;
        if (ilevel == 6 ) //last loop - game over
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

        /*======check, which level is now to view ========*/

        iNrLinii=ilevel*8;

        /*======  read file   ========*/

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
    if (sSzukany.length()>1)
    {
        sSzukany.erase(1);
        std::cout<<"\ntest2\n"<<sSzukany<<" test2" ;
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

   // return this.sText;  //nie dziala
}

void cEngine::fnSetsSzukany(std::string sSzuk)
{
    sSzukany=sSzuk;

    //this.sSzukany=sSzuk; //nie dziala
}

std::string cEngine::fnGetsSzukany()
{
    return sSzukany;
}
