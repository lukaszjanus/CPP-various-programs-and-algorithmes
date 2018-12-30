/***************************************************************************************************************
*"basic.h"
*
*
*CONTENTS:
* "Calculator Menu."
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     07.12.2017  Orginal design													            Lukasz Janus
*
****************************************************************************************************************/

#ifndef MENU_H
#define MENU_H

#include "basic.h"

class cMenu
{
    int m_nMenuChoice;

public:

/*----konstruktory, destruktor-----*/

    cMenu();
    ~cMenu();

/*----Metody dostepowe do pol--------*/

    void SetMenuChoice(int nMenuChoice);
    int GetMenuChoice();

/*----Obsluga Menu--------*/

    void c_fnStart();
    static void c_fnView();
    void c_fnYourChoice();
};

#endif // MENU_H
