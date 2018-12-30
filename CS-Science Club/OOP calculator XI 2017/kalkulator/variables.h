/***************************************************************************************************************
*"variables.h"
*
*
*CONTENTS:
* "Variables for cBasic class"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     07.12.2017  Orginal design													            Lukasz Janus
*
****************************************************************************************************************/

#ifndef VARIABLES_H
#define MENU_H

class cVariables
{
private:
    double m_da;
    double m_db;
    unsigned long long m_ullc;
    unsigned long long m_ulld;

public:

/*----konstruktory, destruktor-----*/

    cVariables();
    ~cVariables();

/*----Metody dostepowe do pol--------*/

    void SetA(double da);
    void SetB(double db);
    void SetC(unsigned long long ullc);
    void SetD(unsigned long long ulld);

    double GetA();
    double GetB();
    unsigned long long GetC();
    unsigned long long GetD();


/*----Inicjalizacja--------*/

    void c_fnFirstVariable();
    void c_fnSecondVariable();
    void c_fnOneVariableC();
    void c_fnOneVariableD();
};

#endif // VARIABLES_H
