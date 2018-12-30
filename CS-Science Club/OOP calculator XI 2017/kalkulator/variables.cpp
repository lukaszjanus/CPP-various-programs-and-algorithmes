#include "variables.h"
/*-----------------*/
#include <iostream>


/*----konstruktory, destruktor-----*/

cVariables::cVariables() {};
cVariables::~cVariables() {};

/*----Metody dostepowe do pol--------*/

void cVariables::SetA(double da)    {m_da=da;}
void cVariables::SetB(double db)    {m_db=db;}
void cVariables::SetC(unsigned long long ullc)  {m_ullc=ullc;}
void cVariables::SetD(unsigned long long ulld)  {m_ulld=ulld;}

double cVariables::GetA()   {return m_da;}
double cVariables::GetB()   {return m_db;}
unsigned long long cVariables::GetC()   {return m_ullc;}
unsigned long long cVariables::GetD()   {return m_ulld;}

/*----Inicjalizacja--------*/

void cVariables::c_fnFirstVariable()
{
    double da;
    std::cin>>da;
    SetA(da);
}

void cVariables::c_fnSecondVariable()
{
    double db;
    std::cin>>db;
    SetB(db);
}

void cVariables::c_fnOneVariableC()
{
    unsigned long long ullc;
    std::cin>>ullc;
    SetC(ullc);
}

void cVariables::c_fnOneVariableD()
{
    unsigned long long ulld;
    std::cin>>ulld;
    SetD(ulld);
}

