/***************************************************************************************************************
*"basic.h"
*
*
*CONTENTS:
* "Mathematical Operations."
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     07.12.2017  Orginal design													            Lukasz Janus
*
****************************************************************************************************************/

#ifndef BASIC_H
#define MENU_H

#include "variables.h"
#include <string>

class cBasic
{
private:
    double m_dScore;
    unsigned long long m_ullScore;

public:

    cBasic();
    ~cBasic();

 /*----SetGet wynik--------*/

    void SetScore(double dScore);
    double GetScore();

    void SetUllScore(unsigned long long dScore);
    unsigned long long GetUllScore();

/*----Operacje--------*/

    double c_fnAdd(double a, double b);
    double c_fnSubtract(double a, double b);
    double c_fnMultiply(double a, double b);
    double c_fnDivide(double a, double b);
    double c_fnModulo(double a, double b);

    double c_fnExponentiation(double a, double b);
    unsigned long long c_fnFactorial(unsigned long long a);
    double c_fnLogarithm(double a, double b);

    std::string c_fnBinary(unsigned long long a);
    std::string c_fnHexadecimal(unsigned long long a);
};

#endif // BASIC_H
