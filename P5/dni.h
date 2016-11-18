#include <iostream>
#pragma once

using namespace std;

class DNI
{
    private:
    
    int num;                                            //Valor que contiene el dni
    
    public:
    
    DNI(void);                                          //Constructor por defecto
    DNI(int n);                                         //Constructor
    ~DNI(void);                                         //Destructor
    
    int set_dni(int n);                                 //Asigna valor a dni
    int get_dni(void) const;                            //Retorna valor de dni
    
    operator unsigned int() const {return num;}         //Conversion de tipo DNI a unsigned int
        
    DNI& operator=(const DNI&);
    DNI& operator=(const int&);
    
    friend bool operator==(const DNI&, const DNI&);     //Operadores de comparacion
    friend bool operator==(const DNI&, const int&);
    friend bool operator!=(const DNI&, const DNI&);
    friend bool operator!=(const DNI&, const int&);
    friend bool operator>(const DNI&, const int&); 
        
    friend int operator+(const DNI&, const DNI&);       //Operadores aritmeticos
    friend int operator/(const DNI&, const DNI&);
    friend int operator/(const DNI&, const int&);
    friend int operator%(const DNI&, const DNI&); 
    friend int operator%(const DNI&, const int&);
    
    friend ostream& operator<<(ostream& os, const DNI& a);      //Sobrecarga de operador del flujo salida
};