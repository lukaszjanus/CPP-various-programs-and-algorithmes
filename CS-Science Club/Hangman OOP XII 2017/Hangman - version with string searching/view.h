/***************************************************************************************************************
*"view.h"
*
*
*CONTENTS:
* "Hangman (game)"
*
*Console interface for that game.
*
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     27.12.2017  Orginal design													            Lukasz Janus
*
****************************************************************************************************************/

#ifndef cView_H
#define cView_H

#include "engine.h"


//enum GameChoice {start=1, stop=2};


class cView:public cEngine
{

public:

    cView();

    void fnStart(); //petla glowna programu
    void fnChoice(char g); //zabezpiecznie od blednie wpisanych znakow (do dokonczenia)
    void fnMainMenu(); //wyswietlenie menu glownego
    void fnEndMenu(); //w zakonczneie gry (wyjscie z gry)
    void fnGame();  //rozpoczecie gry (wejscie z menu glownego

};



#endif // cView_H

