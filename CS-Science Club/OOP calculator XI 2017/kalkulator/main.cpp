/***************************************************************************************************************
*Program:
*Calculator.
*Operations:
*1.Add.
*2.Subtract.
*3.Multiply.
*4.Divide.
*5.Modulo.
*6.Exponentiation.
*7.Factorial.
*8.Logarithm.
*9.Decimal to binary.
*10.Decimal to hexadecimal.
*
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     07.12.2017  Orginal design													            Lukasz Janus
*
****************************************************************************************************************/

#include "menu.h"


using namespace std;

int main()
{
    cMenu *menu=new cMenu;
    menu->c_fnStart();
    delete menu;

    return 0;
}
