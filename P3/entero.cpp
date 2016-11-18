#include "entero.h"
#include "racional.h"
#include "complejo.h"


entero::entero(void):
numero_(0)
{}

entero::entero(int n):
numero_(n)
{}

entero::~entero(void)
{}

int entero::get_numero(void) const
{
    return numero_;
}

const entero entero::toEntero(void) const
{
    return numero_;   
}

const real entero::toReal(void) const
{
    real a(get_numero());
    return a;
}

const racional entero::toRacional(void) const
{
    racional a(get_numero(),1);
    return a;
}

const complejo entero::toComplejo(void) const
{
    real b(get_numero());
    real c(0.0);
    complejo a(b,c);
    return a;
}

entero& entero::operator=(const entero& n)
{
    numero_ = n.get_numero();
    return *this;
}

entero& entero::operator=(const int& n)
{
    numero_ = n;
    return *this; 
}

ostream& entero::toStream(ostream& sout) const
{
  sout << numero_;
  
  return sout;
}

istream& entero::fromStream(istream& sin)
{
  sin >> numero_;
  
  return sin;
}

entero operator+(const entero& a, const entero& b)
{
    return a.get_numero() + b.get_numero();
}

entero operator-(const entero& a, const entero& b)
{
    return a.get_numero() - b.get_numero();
}

entero operator*(const entero& a, const entero& b)
{
    return a.get_numero() * b.get_numero();
}

entero negar(const entero& a)
{
    entero b(-1);
    return a.get_numero() * b.get_numero();
}

entero operator/(const entero& a, const entero& b)
{
    return a.get_numero() / b.get_numero();   
    
    try 
    {
        if(!b.get_numero()) throw 1;
        return entero(a.get_numero()/b.get_numero());
    } 
    catch(int a)
    {
        cout << "-->Fallo al intentar dividir por 0" << endl;
        return 000;
    }
}

bool operator==(const entero& a, const entero& b)
{
    if(a.get_numero() == b.get_numero())
        return true;
    else
        return false;
}

bool operator!=(const entero& a, const entero& b)
{
    if(a.get_numero() != b.get_numero())
        return true;
    else
        return false;
}

bool operator<(const entero& a, const entero& b)
{
    if(a.get_numero() < b.get_numero())
        return true;
    else
        return false;
}

bool operator>(const entero& a, const entero& b)
{
    if(a.get_numero() > b.get_numero())
        return true;
    else
        return false;
}

bool operator<=(const entero& a, const entero& b)
{
    if(a.get_numero() <= b.get_numero())
        return true;
    else
        return false;
}

bool operator>=(const entero& a, const entero& b)
{
    if(a.get_numero() >= b.get_numero())
        return true;
    else
        return false;   
}

ostream& operator<<(ostream& os, const entero& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, entero& a)
{
  int n;
  is >> n;
  entero aux(n);
  a = aux;
  return is;
}

