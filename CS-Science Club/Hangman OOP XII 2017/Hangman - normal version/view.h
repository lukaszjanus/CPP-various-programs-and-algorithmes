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
*1.1    27.12.2017  Rules correction in engine - classic Hangman	            	            Lukasz Janus
*       -fnGame - adding information about points and change length of start word
*       -delete enum
****************************************************************************************************************/

#ifndef cView_H
#define cView_H

#include "engine.h"

class cView:public cEngine
{

public:

    cView();

    void fnMainMenu(); //view of Main Menu
    void fnEndMenu(); //finishing program
    void fnStart(); //the main loop of program
    void fnChoice(char g); //information about chosen option
    void fnGame();  //the main loop of playing

};



#endif // cView_H

