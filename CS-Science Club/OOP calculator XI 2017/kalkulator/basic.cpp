#include "basic.h"
/*-----------------*/

#include <cmath>
#include <string>


/*----konstruktory, destruktor-----*/

cBasic::cBasic() {}
cBasic::~cBasic() {}

/*----SetGet wynik--------*/

void cBasic::SetScore(double dScore)    {m_dScore=dScore;}
double cBasic::GetScore()   {return m_dScore;}

void cBasic::SetUllScore(unsigned long long dScore) {m_ullScore=dScore;}
unsigned long long cBasic::GetUllScore()    {return m_ullScore;}

/*----Operacje--------*/

double cBasic::c_fnAdd(double a, double b){    SetScore(a+b); return GetScore();}
double cBasic::c_fnSubtract(double a, double b) {SetScore(a-b); return GetScore();}
double cBasic::c_fnMultiply(double a, double b) {SetScore(a*b); return GetScore();}
double cBasic::c_fnDivide(double a, double b)
{
    //if (b==0) return 0;
    SetScore(a/b);
    return GetScore();
}

double cBasic::c_fnModulo(double a, double b)
{
    SetScore(static_cast<int>(a)%static_cast<int>(b));
    return GetScore();
}

double cBasic::c_fnExponentiation(double a, double b)
{
    SetScore(pow(a,b));
    return GetScore();
}

unsigned long long cBasic::c_fnFactorial(unsigned long long a)
{
    if (a==0) return 1;
    unsigned long long i;
    for(i=a-1;i>=1;i--) a*=i;
    SetUllScore(a);
    return GetUllScore();
}

double cBasic::c_fnLogarithm(double a, double b)
{
    SetScore(log(b)/log(a));
    return GetScore();
}

std::string cBasic::c_fnBinary(unsigned long long a)
{
    std::string temp="";
    std::string sBinary="";

    do{
    if (a%2==0)
        {
        temp+="0";
        a/=2;
        }
    else
        {
            temp+="1";
            a/=2;
        }
    }    while (a!=0);

    for (int i=temp.size();i>=0;i--)
    {
        sBinary+=temp[i];
    }

    return sBinary;
}

std::string cBasic::c_fnHexadecimal(unsigned long long a)
{
    //char hex[255];
    //itoa(a, hex, 16);

    std::string temp="";
    std::string sHex="";
    const char alphabet[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    int *ia = new int;
    int pa;
    ia=&pa;

    do{
    if (a%16==0)
        {
        pa=0;
        a/=16;
        }
    else if (a%16==1)
        {
        pa=1;
        a/=16;
        }
    else if (a%16==2)
        {
        pa=2;
        a/=16;
        }
    else if (a%16==3)
        {
        pa=3;
        a/=16;
        }
    else if (a%16==4)
        {
        pa=4;
        a/=16;
        }
    else if (a%16==5)
        {
        pa=5;
        a/=16;
        }
    else if (a%16==6)
        {
        pa=6;
        a/=16;
        }
    else if (a%16==7)
        {
        pa=7;
        a/=16;
        }
    else if (a%16==8)
        {
        pa=8;
        a/=16;
        }
    else if (a%16==9)
        {
        pa=9;
        a/=16;
        }
    else if (a%16==10)
        {
        pa=10;
        a/=16;
        }
    else if (a%16==11)
        {
        pa=11;
        a/=16;
        }
    else if (a%16==12)
        {
        pa=12;
        a/=16;
        }
    else if (a%16==13)
        {
        pa=13;
        a/=16;
        }
    else if (a%16==14)
        {
        pa=14;
        a/=16;
        }
    else if (a%16==15)
        {
        pa=15;
        a/=16;
        }
    temp+=alphabet[*ia];

    }    while (a!=0);

    for (int i=temp.size();i>=0;i--)
    {
        sHex+=temp[i];
    }

    return sHex;
}
