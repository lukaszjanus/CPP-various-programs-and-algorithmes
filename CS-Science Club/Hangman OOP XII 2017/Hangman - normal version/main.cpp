/***************************************************************************************************************
*"main.cpp"
*
*
*CONTENTS:
*
* "Hangman (game)"
* Computer thinks of a phrase, player tries to guess it.
*
*
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0    27.12.2017  Orginal design (works as "search small text in whole text"		            Lukasz Janus
*1.1    27.12.2017  Rules correction in engine - classic Hangman - one letter is searched       Lukasz Janus
****************************************************************************************************************/

#include <iostream>
#include "view.h"

int main()
{
    cView *game;
    game->fnStart();

    return 0;
}
