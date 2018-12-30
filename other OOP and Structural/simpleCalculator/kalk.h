#include <iostream>

using namespace std;

class kalkulator
{
    public:

    float mnoz(float x, float y);

    float add (float x, float y);

    float odej(float x, float y);

    float dziel (float x, float y);

    //tablica2w(){};
    //~tablica2w();
};

class dzialania: public kalkulator
{

public:
    int a;
    float x,y;
    int wybor_opcji();
    kalkulator test;
    void dane(); //czyli zeby przypisac watroœci do x i y, to nie wchodzê tu ¿adnymi x i y;
    int menu();
};

class tablica1w : public kalkulator
{
public:
    void tab1w(float x, float y);
};

class tablica2w : public kalkulator
{
public:
    void tab2w(float x, float y);
};
