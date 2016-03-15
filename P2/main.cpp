#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>
#include "temp_calc.h"
#include "complejo.h"
#include "racional.h"

using namespace std;

int main(void)
{
    system("clear");
    cout << "--> Practica 2: Calculadora de expresiones en notación postfija"<< endl;
    cout << endl;
    cout << "--> Introduzca la expresion (en formato RPN): ";
    string str;
    
    getline(cin, str);
    
    istringstream input(str);
    
    size_t have_dot = str.find('.'); //"size_t" es un tipo de dato que corresponde a la longitud maxima de la cadena en bytes (numero de caracteres).
    
    //Haya punto o no en la expresión, se evalua la expresión
    //"npos" nos indica que llega hasta el final de la cadena (valor por defecto -1), si found es -1 es que no hay punto en la expresión, por tanto no hay float
    if ((((str[0] == '-') && isdigit(str[1])) || isdigit(str[0])) && ((have_dot == string::npos) || (have_dot != string::npos)))
    {
        double result;
        calculator<double> my_calc;
        result = my_calc.compute(input);
        cout << "--> El resultado de la expresion es: " << result << endl;
    }
    else if(str[0] == '(')
    {
        complejo result;
        calculator<complejo> my_calc;
        result = my_calc.compute(input);
        cout << "--> El resultado de la expresion es: " << result << endl;
    }
    else if( str[0] == '"')
    {
        rational result;
        calculator<rational> my_calc;
        result = my_calc.compute(input);
        cout << "--> El resultado de la expresion es: " << result << endl;
    }
    cout << endl;
}