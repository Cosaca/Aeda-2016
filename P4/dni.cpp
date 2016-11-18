#include "dni.h"

DNI::DNI(void):
num__(0)
{}

DNI::DNI(int n):
num_(n)
{}
  
DNI::~DNI(void)
{}
  
int DNI::set_dni(int n)
{
  num_ = n;
}

int DNI::get_dni(void) const
{
  return(num_);
}

DNI& DNI::operator=(const DNI& a)
{
  num_ = a.get_dni();
}

DNI& DNI::operator=(const int& a)
{
  num_ = a;
}

ostream& operator<<(ostream& os, const DNI& a)
{
  os << a.get_dni();
  return os;
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

int operator+(const DNI& a, const DNI& b)
{
  return(a.get_dni()+b.get_dni());
}
  
int operator/(const DNI& a, const DNI& b)
{
  return(a.get_dni()/b.get_dni());
}

int operator/(const DNI& a, const int& b)
{
  return(a.get_dni()/b);
}
  
int operator%(const DNI& a, const DNI& b)
{
  return(a.get_dni()%b.get_dni());
}

int operator%(const DNI& a, const int& b)
{
  return(a.get_dni()%b);
}
