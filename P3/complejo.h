#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#pragma once

#define EPSILON 0.01

using namespace std;

class complejo 
{
  private:
  
  double r_;
  double i_;
  double mod_;
  
  public:
  
  complejo(void);                                     //Constructor por defecto
  complejo(double re, double im);                     //Constructor de asignación
  complejo(const complejo& n);                        //Constructor de copia
  complejo(double n);

  ~complejo(void);                                    //Destructor
  
  double get_r(void) const;
  double get_i(void) const;
  double get_mod(void) const;
  
  complejo& operator=(const complejo&);   //Sobrecarga de operadores
  complejo& operator=(int n);             //Método para poder multiplicar por -1;
  complejo& operator=(const string a);    //Operador de asignación para darle un valor desde una cadena del tipo X+Yi
  
  friend complejo operator+(const complejo&, const complejo&);    //Operadores aritméticos
  friend complejo operator-(const complejo&, const complejo&);
  friend complejo operator*(const complejo&, const complejo&);
  friend complejo operator/(const complejo&, const complejo&);
  
  friend bool operator==(const complejo&, const complejo&);         //Operadores de comparación
  friend bool operator!=(const complejo&, const complejo&);
  friend bool operator<(const complejo&, const complejo&);
  friend bool operator>(const complejo&, const complejo&);
  friend bool operator<=(const complejo&, const complejo&);
  friend bool operator>=(const complejo&, const complejo&);
  
  friend ostream& operator<<(ostream&, const complejo&);          //Entrada-Salida
  friend istream& operator>>(istream&,  complejo&);
};