#include <cstring>
#include <cstdlib>
#include <sstream>
#include "temp_pila.h"
#pragma once 

using namespace std;

template <class TDATO>
class calculator
{
    private:
    
    a_stack<TDATO> stack_;
    
    public:
    
    calculator(void);           //Constructor
    ~calculator(void);          //Destructor
    TDATO compute(istream& input);
        
    bool is_operator(basic_istream<char>::int_type caracter);
    bool is_complex(basic_istream<char>::int_type caracter);
    bool is_rational(basic_istream<char>::int_type caracter);
};

template <class TDATO>
calculator<TDATO>::calculator(void):
stack_()
{}

template <class TDATO>
calculator<TDATO>::~calculator(void)
{}

template <class TDATO>
TDATO calculator<TDATO>::compute(istream& input)
{
    TDATO aux;
    TDATO oper1;
    TDATO oper2;
    TDATO op; 
    TDATO sum;
    char operacion;
    char parentesis, comillas;
    
    while(input.peek() != '=')
    {
        if(isdigit(input.peek())){ 
            input >> op;
            stack_.push(op);
        }
        else if(((is_complex(input.peek())) && (!isdigit(input.peek()))))       //() numero complejo
        {
            input >> parentesis;
        }
        else if((is_rational(input.peek())) && (!isdigit(input.peek())))        //"" numero racional
        {
            input >> comillas;
        }
        else if(isblank(input.peek()))
        {
            input.ignore(1);
        }
        else
        {
            input >> operacion;
            switch(operacion)
            {
                case '+':
                    oper2 = stack_.pop();
                    oper1 = stack_.pop();
                    sum = oper1 + oper2;
                    stack_.push(sum);
                break;
                
                case '-':
                    if(isdigit(input.peek())) //Si hay un - seguido de un digito, es un numero negativo
                    {// Hola troll que ocurre 
                        TDATO negativo = -1;
                        input >> op;
                        op = op * negativo;
                        stack_.push(op);
                    }
                    else
                    {
                        oper2 = stack_.pop();
                        oper1 = stack_.pop();
                        stack_.push(oper1 - oper2);
                    }
                break;
                
                case '/':
                    oper2 = stack_.pop();
                    oper1 = stack_.pop();
                    stack_.push(oper1 / oper2);
                break;
                
                case '*':
                    oper2 = stack_.pop();
                    oper1 = stack_.pop();
                    stack_.push(oper1 * oper2);
                break;
            }
        }
    }
    return stack_.pop();
}

template <class TDATO>
bool calculator<TDATO>::is_operator(basic_istream<char>::int_type caracter)
{
    if((caracter == ' ') || (caracter == '(') || (caracter == ')') || (caracter == '"') )
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class TDATO>
bool calculator<TDATO>::is_complex(basic_istream<char>::int_type caracter)
{
    if((caracter == '(') || (caracter == ')'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class TDATO>
bool calculator<TDATO>::is_rational(basic_istream<char>::int_type caracter)
{
    if(caracter == '"')
    {
        return true;
    }
    else
    {
        return false;
    }
}

