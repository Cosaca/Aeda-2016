#include "dni.h"

DNI::DNI(void):
num(0)
{}

DNI::DNI(int n):
num(n)
{}
  
DNI::~DNI(void)
{}
  
void DNI::set_dni(int n)
{
  num = n;
}
  
int DNI::get_dni(void) const
{
  return(num);
}

DNI& DNI::operator=(const DNI& a)
{
  num = a.get_dni();
}

DNI& DNI::operator=(const int& a)
{
  num = a;
}

bool operator==(const DNI& a, const DNI& b)
{
  return (a.get_dni()==b.get_dni()?true:false);
}

bool operator==(const DNI& a, const int& b)
{
  return (a.get_dni()==b?true:false);
}

bool operator!=(const DNI& a, const DNI& b)
{
  return (a==b?false:true);
}

bool operator!=(const DNI& a, const int& b)
{
  return (a.get_dni()==b?false:true);
}

bool operator>(const DNI& a, const int& b)
{
  return (a.get_dni()>b?true:false);
}

bool operator>(const DNI& a, const DNI& b)
{
  return (a.get_dni()>b.get_dni()?true:false);
}

bool operator<(const DNI& a, const DNI& b)
{
  if(a==b)
    return false;
  else if(a>b)
    return false;
  else
    return true;
}

bool operator>=(const DNI& a, const DNI& b)
{
  return(a<b?false:true);
}

bool operator<=(const DNI& a, const DNI& b)
{
  return(a>b?false:true);
}

ostream& operator<<(ostream& os, const DNI& a)
{
  os << a.get_dni();
  return os;
}

int operator+(const DNI& a, const DNI& b)
{
  return(a.get_dni()+b.get_dni());
}
  
unsigned operator/(const DNI& a, const DNI& b)
{
  return(a.get_dni()/b.get_dni());
}

unsigned operator/(const DNI& a, const unsigned& b)
{
  return(a.get_dni()/b);
}
  
unsigned operator%(const DNI& a, const DNI& b)
{
  return(a.get_dni()%b.get_dni());
}

unsigned operator%(const DNI& a, const unsigned& b)
{
  return(a.get_dni()%b);
}








