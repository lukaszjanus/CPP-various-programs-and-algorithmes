#include "cFire.h"

#include <vector>


cFire::cFire()
{
    m_x.push_back(0);
    m_y.push_back(0);
}

cFire::~cFire(){};

/*==============metody=====================*/

char cFire::fnGetAmmo()
{
    return m_Ammo;
}

void cFire::setVect(int x, int y)
{
    m_x.push_back(x);
    m_y.push_back(y);
}

int cFire::getX( int nr)
{
    return m_x[nr];
}

int cFire::getY( int nr)
{
    return m_y[nr];
}

int cFire::getSize()
{
    return m_x.size();
}

void cFire::fnErase(int nr)
{
    vector <int>::iterator a;
    a=m_x.begin()+nr;
    m_x.erase(a);

    vector <int>::iterator b;
    b=m_y.begin()+nr;
    m_y.erase(b);
}

void cFire::swapVect(int x, int y, int nr)
{
    m_x[nr]=x;
    m_y[nr]=y;
}
