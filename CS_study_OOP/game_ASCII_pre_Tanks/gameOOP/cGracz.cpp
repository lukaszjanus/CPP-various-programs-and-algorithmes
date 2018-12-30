#include "cGracz.h"
#include "cEngine.h"

cGracz::cGracz():m_sName("Gracz 2(Komputer)") {};
cGracz::cGracz(string sName2)
{
    m_sName2= new string(sName2);
}

/*==============metody=====================*/
string cGracz::fnGetGracz()
{
    return m_sName;
}

void cGracz::fnSetGracz(string sName)
{
    m_sName=sName;
}

void cGracz::fnNazwaGracza()
{
    cin>>m_sName;
}

void cGracz:: fnDefault1()
{
    m_sName="Gracz1";
}
