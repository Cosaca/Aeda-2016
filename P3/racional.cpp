#include "racional.h"

rational::rational(void):
numerador_(),
denominador_()
{}

rational::rational(double n):
numerador_(n),
denominador_(1)
{}

rational::rational(int dio, int dir):
numerador_(dio),
denominador_(dir),
mcd_(m_d())
{
    numerador_ = numerador_/mcd_;
    denominador_ = denominador_/mcd_;
}

rational::rational(const rational& n) 
{
    *this = n;
}

rational::~rational(void){}

int rational::get_numerador(void) const
{
    return numerador_;
}

int rational::get_denominador(void) const
{  
    return denominador_;
}

rational& rational::operator=(const rational& a)
{
    numerador_ = a.get_numerador();
    denominador_ = a.get_denominador();
    mcd_=a.m_d();
    
    return *this;
}

rational& rational::operator=(const string a)
{
    size_t found = a.find("/");
    
    string b,c;
    b.resize(found);
    c.resize((a.size() - found)-1);
    
    for(unsigned int i = 0; i < found; i++) 
    {
        b[i] = a[i];
    }
    
    for(unsigned int j=0;j<c.size();j++) 
    {
        c[j] = a[j+1+found];
    }
    
    numerador_ = atoi(b.c_str());
    denominador_ = atoi(c.c_str());
    mcd_ = m_d();
    numerador_ = numerador_/mcd_;
    denominador_ = denominador_/mcd_;
}

int rational::m_d(void) const //calculo del maximo comun divisor
{
  int resto, numerador_aux, resto_aux;
  
  resto = numerador_ % denominador_;
  numerador_aux = denominador_;
  
  while(resto != 0)
  {
      resto_aux = resto;
      resto = numerador_aux % resto;
      numerador_aux = resto_aux;
  }
  return numerador_aux;
}

rational operator+(const rational& a, const rational& b)
{  
    return rational(a.get_numerador()*b.get_denominador() + b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

rational operator-(const rational& a, const rational& b)
{ 
    return rational(a.get_numerador()*b.get_denominador() - b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

rational operator*(const rational& a, const rational& b)
{ 
    return rational(a.get_numerador()*b.get_numerador(),a.get_denominador()*b.get_denominador());
}

rational operator/(const rational& a, const rational& b)
{
    return rational(a.get_numerador()*b.get_denominador(),a.get_denominador()*b.get_numerador());
}

bool operator==(const rational& a, const rational& b)
{
    if((a.get_numerador()==b.get_numerador())&&(a.get_denominador()==b.get_denominador())) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

bool operator!=(const rational& a, const rational& b)
{
    return(a==b ? false:true);
}

bool operator<(const rational& a, const rational& b)
{
    if(a.get_numerador()==b.get_denominador())
    {
        return(a.get_denominador()<b.get_denominador() ? false:true);
    } 
    else 
    {
        if((a.get_numerador()*b.get_denominador())<(b.get_numerador()*a.get_denominador())) 
        {
            return true;
        } 
        else 
        {
	        return false;
        }
    }
}

bool operator>(const rational& a, const rational& b)
{
    if(a!=b) 
    {
        return(a<b ? false:true);
    }  
    else 
    {
    return false;
    }
}

bool operator<=(const rational& a, const rational& b)
{
    return(a>b ? false:true);
}

bool operator>=(const rational& a, const rational& b)
{
    return(a<b ? false:true);
}

ostream& operator<<(ostream& os, const rational& a)
{
    os << a.get_numerador() << "/" << a.get_denominador();
    return os;
}

istream& operator>>(istream& is, rational& a)
{
    string n;
    is >> n;
    a = n;
    return is;
}