/***************************************************************************************************************
*"engine.h"
*
*
*CONTENTS:
* "Hangman (game)"
*
*Engine of that game.
*
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     27.12.2017  Orginal design													            Lukasz Janus
*
****************************************************************************************************************/

#ifndef cEngine_H
#define cEngine_H
#include <iostream>
#include <windows.h>
#include <time.h>


class cEngine
{
public:
    std::string sText="";
    std::string sSzukany="";
    bool bCompare=false; //flaga do porownywania tekstu szukanego
    unsigned int ilevel=0; //level - nr obrazka do petli.

    //unsigned int iNumOfCharacters=100; //rozmiar tekstu, w ktorym szukamy
    //unsigned int iAlphabet=3; //rozmiar szukanego fagmentu

    cEngine(); //konstruktor

    void fnGenerate(unsigned int iNumOfCharacters, unsigned int iAlphabet); //generowanie i wypelnianie tablicy losowym tekstem
    int fnCompare(int i); //sprawdzenie tekstu

    void fnLevel(unsigned int ilevel); //wyswietlenie kolejnej czesci szubiennicy
    void fnCheckLength(); //sprawdzenie dlugosci wprowadzonego wyrazu, domyslnie ustawiona dlugosc na '3'

    /*========settery i gettery ========*/

    void fnSetsText(std::string sT);
    std::string fnGetsText();
    void fnSetsSzukany(std::string sSzuk);
    std::string fnGetsSzukany();
};

#endif // cEngine_H
