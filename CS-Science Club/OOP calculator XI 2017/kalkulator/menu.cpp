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
    std::cout<<"Kalkulator obs³uguje poni¿sze typy operacji:\n";
    std::cout<<"1.\tDodawanie.\n";
    std::cout<<"2.\tOdejmowanie.\n";
    std::cout<<"3.\tMno¿enie.\n";
    std::cout<<"4.\tDzielenie.\n";
    std::cout<<"5.\tDzielenie Modulo.\n";
    std::cout<<"6.\tPotêgowanie.\n";
    std::cout<<"7.\tSilnia.\n"; //jeden argument
    std::cout<<"8.\tLogarytmowanie.\n";
    std::cout<<"9.\tZamiana na kod dwojkowy.\n";
    std::cout<<"10.\tZamiana na kod szesnastkowy.\n";
    std::cout<<"11.\tWyjœcie z programu.\n\n";
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

        std::cout<<"\n\tWybra³eœ dodawanie.\n";
        std::cout<<"\nPodaj pierwsz¹ liczbê:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj drug¹ liczbê:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnAdd(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 2:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ Odejmowanie.\n";
        std::cout<<"\nPodaj liczbê, od której bêdziesz odejmowaæ:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj liczbê, która bêdzie odejmowana:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnSubtract(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 3:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ Mno¿enie.\n";
        std::cout<<"\nPodaj pierwsz¹ liczbê:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj drug¹ liczbê:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnMultiply(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 4:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ Dzielenie.\n\tMo¿esz podaæ liczby ca³kowite, ujemne i u³amki.\n\tPamiêtaj, ¿e dzielnik musi byæ ró¿ny od '0'\n";
        std::cout<<"\nPodaj dzieln¹:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj dzielnik:\t";
        variable->c_fnSecondVariable();
        if (variable->GetB()==0)
        {
            std::cout<<"\nNie dzielimy przez '0'! \n\nWybierz dowolny przycisk aby powróciæ do Menu.";
            break;
        }

        std::cout<<"Wynik:\t"<<operation->c_fnDivide(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 5:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ Dzielenie Modulo.\n";
        std::cout<<"\n\tPodaj liczby ca³kowite.\n\tJeœli wprowadzisz u³amki, zostan¹ one zaokr¹glone do ca³oœci 'w dó³'.\n";
        std::cout<<"\nPodaj dzieln¹:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj dzielnik:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnModulo(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 6:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ Potêgowanie.\n\tMo¿esz podaæ liczby ca³kowite, ujemne i u³amki.\n";
        std::cout<<"\nPodaj podstawê potêgi:\t";
        variable->c_fnFirstVariable();
        std::cout<<"\nPodaj wyk³adnik potêgi:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnExponentiation(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 7:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ Silniê.\n\tMo¿esz podaæ liczby naturalne i '0'.\n\tJeœli wprowadzisz u³amek, zostanie on zaokr¹glony do ca³oœci 'w dó³'.\n";
        variable->c_fnOneVariableC();
        if (variable->GetB()==0)
        {
            std::cout<<"\nNie liczymy silni dla liczb nienaturalnych! \n\nWybierz dowolny przycisk aby powróciæ do Menu.";
            break;
        }
        std::cout<<"Wynik:\t"<<operation->c_fnFactorial(variable->GetC());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 8:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ liczenie Logarytmu.\n\tMo¿esz podaæ tylko liczby dodatnie.\n\tPamiêtaj, ¿e podstawa logarytmu musi byæ inna od '1'.\n";
        std::cout<<"\nPodaj podstawê logarytmu:\t";
        variable->c_fnFirstVariable();
        if (variable->GetA()==1)
        {
            std::cout<<"\nNie mo¿na policzyæ logarytmu z podstaw¹ równ¹ '1'! \n\nWybierz dowolny przycisk aby powróciæ do Menu.";
            break;
        }
        std::cout<<"\nPodaj liczbê, z której bêdziesz liczyæ logarytm:\t";
        variable->c_fnSecondVariable();
        std::cout<<"Wynik:\t"<<operation->c_fnLogarithm(variable->GetA(), variable->GetB());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 9:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ przeliczanie na System Binarny.\n";
        std::cout<<"\n\t \n \n";
        std::cout<<"\nPodaj liczbê, któr¹ chcia³byœ przeliczyæ:\t";
        variable->c_fnOneVariableC();

        std::cout<<"Wynik:\t"<<operation->c_fnBinary(variable->GetC());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }
    case 10:
    {
        cBasic *operation=new cBasic();
        cVariables *variable=new cVariables();

        std::cout<<"\n\tWybra³eœ przeliczanie na System Hexadecymalny.\n";
        std::cout<<"\n\t \n \n";
        std::cout<<"\nPodaj liczbê, któr¹ chcia³byœ przeliczyæ:\t";
        variable->c_fnOneVariableC();

        std::cout<<"Wynik:\t"<<operation->c_fnHexadecimal(variable->GetC());

        delete operation;
        delete variable;

        std::cout<<"\n\nWybierz dowolny przycisk aby kontynuowaæ.";
        break;
    }

    case 11:
    {
        std::cout<<"Wybra³eœ zakoñczenie programu. \n";
        exit(0);
        // break;
    }
    default:
    {
    std::cout<<"\n B³êdny wybór - wciœnij dowolny klawisz, aby spróbowaæ jeszcze raz!\t";
    }
    }

    getch();
}
