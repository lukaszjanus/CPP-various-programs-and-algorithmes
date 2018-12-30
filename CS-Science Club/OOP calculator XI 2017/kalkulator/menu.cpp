#include "menu.h"
/*-----------------*/
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include <cstdio>

#include <string>
#include <sstream>


/*----konstruktory------*/

cMenu::cMenu() {}
cMenu::~cMenu() {}

/*----Metody dostepowe do pol--------*/

void cMenu::SetMenuChoice(int nMenuChoice)  {m_nMenuChoice=nMenuChoice;}
int cMenu::GetMenuChoice()  {return m_nMenuChoice;}

/*----Obsluga Menu--------*/

void cMenu::c_fnStart()
{
    for(;;)
    {
        setlocale(LC_ALL, "Polish");
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);

        system("cls");
        c_fnView();
        c_fnYourChoice();
    }
}

void cMenu::c_fnView()
{
    std::cout<<"Kalkulator obs�uguje poni�sze typy operacji:\n";
    std::cout<<"1.\tDodawanie.\n";
    std::cout<<"2.\tOdejmowanie.\n";
    std::cout<<"3.\tMno�enie.\n";
    std::cout<<"4.\tDzielenie.\n";
    std::cout<<"5.\tDzielenie Modulo.\n";
    std::cout<<"6.\tPot�gowanie.\n";
    std::cout<<"7.\tSilnia.\n"; //jeden argument
    std::cout<<"8.\tLogarytmowanie.\n";
    std::cout<<"9.\tZamiana na kod dwojkowy.\n";
    std::cout<<"10.\tZamiana na kod szesnastkowy.\n";
    std::cout<<"11.\tWyj�cie z programu.\n\n";
}

void cMenu::c_fnYourChoice()
{
    std::cout<<"\n\tPodaj numer operacji (od 1 do 11): ";

    std::string str;
    int *op= new int;
    int opr;
    op= &opr;

    std::cin>>str;
    std::istringstream iss(str);
    iss >> opr;

    switch(*op)
    {
    case 1:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� dodawanie.\n";
        std::cout<<"\nPodaj pierwsz� liczb�:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj drug� liczb�:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnAdd(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 2:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� Odejmowanie.\n";
        std::cout<<"\nPodaj liczb�, od kt�rej b�dziesz odejmowa�:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj liczb�, kt�ra b�dzie odejmowana:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnSubtract(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 3:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� Mno�enie.\n";
        std::cout<<"\nPodaj pierwsz� liczb�:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj drug� liczb�:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnMultiply(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 4:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� Dzielenie.\n\tMo�esz poda� liczby ca�kowite, ujemne i u�amki.\n\tPami�taj, �e dzielnik musi by� r�ny od '0'\n";
        std::cout<<"\nPodaj dzieln�:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj dzielnik:\t";
        variable->c_fnSecondVariable();
        if (variable->GetB()==0)
        {
            std::cout<<"\nNie dzielimy przez '0'! \n\nWybierz dowolny przycisk aby powr�ci� do Menu.";
            break;
        }

        std::cout<<"Wynik:\t"<<operation->c_fnDivide(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 5:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� Dzielenie Modulo.\n";
        std::cout<<"\n\tPodaj liczby ca�kowite.\n\tJe�li wprowadzisz u�amki, zostan� one zaokr�glone do ca�o�ci 'w d�'.\n";
        std::cout<<"\nPodaj dzieln�:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj dzielnik:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnModulo(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 6:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� Pot�gowanie.\n\tMo�esz poda� liczby ca�kowite, ujemne i u�amki.\n";
        std::cout<<"\nPodaj podstaw� pot�gi:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj wyk�adnik pot�gi:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnExponentiation(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 7:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� Silni�.\n\tMo�esz poda� liczby naturalne i '0'.\n\tJe�li wprowadzisz u�amek, zostanie on zaokr�glony do ca�o�ci 'w d�'.\n";
        variable->c_fnOneVariableC();
        if (variable->GetB()==0)
        {
            std::cout<<"\nNie liczymy silni dla liczb nienaturalnych! \n\nWybierz dowolny przycisk aby powr�ci� do Menu.";
            break;
        }
        std::cout<<"Wynik:\t"<<operation->c_fnFactorial(variable->GetC());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 8:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� liczenie Logarytmu.\n\tMo�esz poda� tylko liczby dodatnie.\n\tPami�taj, �e podstawa logarytmu musi by� inna od '1'.\n";
        std::cout<<"\nPodaj podstaw� logarytmu:\t";
        variable->c_fnFirstVariable();
        if (variable->GetA()==1)
        {
            std::cout<<"\nNie mo�na policzy� logarytmu z podstaw� r�wn� '1'! \n\nWybierz dowolny przycisk aby powr�ci� do Menu.";
            break;
        }
        std::cout<<"\nPodaj liczb�, z kt�rej b�dziesz liczy� logarytm:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnLogarithm(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 9:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� przeliczanie na System Binarny.\n";
        std::cout<<"\n\t \n \n";
        std::cout<<"\nPodaj liczb�, kt�r� chcia�by� przeliczy�:\t";
        variable->c_fnOneVariableC();

        std::cout<<"Wynik:\t"<<operation->c_fnBinary(variable->GetC());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }
    case 10:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra�e� przeliczanie na System Hexadecymalny.\n";
        std::cout<<"\n\t \n \n";
        std::cout<<"\nPodaj liczb�, kt�r� chcia�by� przeliczy�:\t";
        variable->c_fnOneVariableC();

        std::cout<<"Wynik:\t"<<operation->c_fnHexadecimal(variable->GetC());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowa�.";
        break;
    }

    case 11:
    {
        std::cout<<"Wybra�e� zako�czenie programu. \n";
        exit(0);
        // break;
    }
    default:
    {
    std::cout<<"\n B��dny wyb�r - wci�nij dowolny klawisz, aby spr�bowa� jeszcze raz!\t";
    }
    }

    getch();
}
