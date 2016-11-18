#pragma once
#include <iostream>
#include "real.h"
#include "numero.h"

class racional;
class complejo;

using namespace std;

class entero: public numero_t
{
    private:
    
    int numero_;                                                        //Numero entero
     
    public:
  
    entero(void);                                                       //Constructor por defecto
    entero(int n);                                                      //Constructor de asignacion
    ~entero(void);
    int get_numero(void) const;
          
    entero& operator=(const entero&);
    entero& operator=(const int& n);
        
    virtual const entero toEntero(void) const;                          //Metodos copias de numero
    virtual const real toReal(void) const;
    virtual const racional toRacional(void) const;
    virtual const complejo toComplejo(void) const;
    
    virtual ostream& toStream(ostream& sout) const;                     //Escribe un numero al flujo sout
    virtual istream& fromStream(istream& sin);                          //Escribe un numero al flujo sin
          
    friend entero operator+(const entero&, const entero&);              //Operadores aritméticos
    friend entero operator-(const entero&, const entero&);
    friend entero operator*(const entero&, const entero&);
    friend entero operator/(const entero&, const entero&);
    friend entero negar(const entero&);
    
    friend bool operator==(const entero&, const entero&);               //Operadores de comparación
    friend bool operator!=(const entero&, const entero&);
    friend bool operator<(const entero&, const entero&);
    friend bool operator>(const entero&, const entero&);
    friend bool operator<=(const entero&, const entero&);
    friend bool operator>=(const entero&, const entero&);
          
    friend ostream& operator<<(ostream&, const entero&);                //Entrada-salida
    friend istream& operator>>(istream&,entero&);
};