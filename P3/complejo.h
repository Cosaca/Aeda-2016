#pragma once
#include "real.h"
#include <cstdlib>
#include <cmath>
#include "numero.h"

class complejo:public numero_t 
{
  private:
  
  real r;                                                         //Parte real                                                         
  real i;                                                         //Parte imaginaria
  real m;                                                         //Modulo
     
  public:
  
  complejo(void);                                                 //Constructor por defecto
  complejo(real re, real im);                                     //Constructor de asignación
  complejo(float re, float im);                                   //Constructor de asignación
  complejo(const complejo& n);                                    //Constructor de copia
  ~complejo(void);                                                //Cestructor
  
  real get_r(void) const;
  real get_i(void) const;
  real get_m(void) const;
  
  virtual const entero toEntero(void) const;                      //Metodos copias de numero
  virtual const real toReal(void) const;
  virtual const racional toRacional(void) const;
  virtual const complejo toComplejo(void) const;
  
  virtual ostream& toStream(ostream& sout) const;                 //Escribe un numero al flujo sout
  virtual istream& fromStream(istream& sin);                      //Lee un numero desde un flujo sin
  
  complejo& operator=(const complejo&);                           //Sobrecarga operadores
  complejo& operator=(const string a);                            //Operador de asignación para darle un valor desde una cadena del tipo X+Yi
  
  friend complejo operator+(const complejo&, const complejo&);    //Operadores aritmeticos
  friend complejo operator-(const complejo&, const complejo&);
  friend complejo operator*(const complejo&, const complejo&);
  friend complejo operator/(const complejo&, const complejo&);
  
  friend bool operator==(const complejo&, const complejo&);       //Operadores de comparación
  friend bool operator!=(const complejo&, const complejo&);
  friend bool operator<(const complejo&, const complejo&);
  friend bool operator>(const complejo&, const complejo&);
  friend bool operator<=(const complejo&, const complejo&);
  friend bool operator>=(const complejo&, const complejo&);
  
  friend ostream& operator<<(ostream&, const complejo&);          //Entrada-Salida
  friend istream& operator>>(istream&, const complejo&);
  
};