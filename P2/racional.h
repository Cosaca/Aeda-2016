#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#pragma once

using namespace std;

class rational 
{
    private:
  
    int numerador_;
    int denominador_;
    int mcd_;
     
    public:
  
    rational(void);                               //Constructor por defecto
    rational(int num, int den);                   //Constructor de asignación
    rational(const rational& n);                  //Constructor de copia
    rational(double n);
    ~rational(void);                              //Destructor
  
    int get_numerador(void) const;
    int get_denominador(void) const;
    int m_d(void) const;                          //Máximo común divisor
  
    rational& operator=(const rational&);         //Sobrecarga en los operadores
    rational& operator=(const string cad);
    
    friend rational operator+(const rational&, const rational&);  //Operadores aritméticos
    friend rational operator-(const rational&, const rational&);
    friend rational operator*(const rational&, const rational&);
    friend rational operator/(const rational&, const rational&);
  
    friend bool operator==(const rational&, const rational&);       //Operadores de comparación
    friend bool operator!=(const rational&, const rational&);
    friend bool operator<(const rational&, const rational&);
    friend bool operator>(const rational&, const rational&);
    friend bool operator<=(const rational&, const rational&);
    friend bool operator>=(const rational&, const rational&);

    friend ostream& operator<<(ostream&, const rational&);        //Entrada-Salida
    friend istream& operator>>(istream&,  rational&);
  
};