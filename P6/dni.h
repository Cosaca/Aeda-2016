#include <ostream>
#pragma once

using namespace std;

class DNI
{
    private:
  
    int num;	                                                //Valor que contiene el DNI
  
    public:
    
    DNI(void);		                                            //Constructor por defecto
    DNI(int n);		                                            //Constructor
    ~DNI(void);		                                            //Destructor
  
    void set_dni(int n);	                                    //Método para editar el número
    int get_dni(void) const;                                    //Método para obtener el número
  
    operator unsigned int() const { return num;}                //Conversion de tipo DNI a unsigned int
  
    DNI& operator=(const DNI&);	                                //operador de asignación a objeto de la misma clase
    DNI& operator=(const int&);	                                //operador de asignación a int
  
    friend bool operator==(const DNI&, const DNI&);	            //Operadores de comparación
    friend bool operator==(const DNI&, const int&);
    friend bool operator!=(const DNI&, const DNI&);
    friend bool operator!=(const DNI&, const int&);
    friend bool operator>(const DNI&, const int&);
    friend bool operator>(const DNI&, const DNI&);
    friend bool operator<(const DNI&, const DNI&);
    friend bool operator>=(const DNI&, const DNI&);
    friend bool operator<=(const DNI&, const DNI&);
  
    friend int operator+(const DNI&, const DNI&);               //Operadores aritmeticos
    friend unsigned operator/(const DNI&, const DNI&);
    friend unsigned operator/(const DNI&, const unsigned&);
    friend unsigned operator%(const DNI&, const DNI&);
    friend unsigned operator%(const DNI&, const unsigned&);
  
    friend ostream& operator<<(ostream&, const DNI&);           //Sobrecarga del operador del flujo salida
};