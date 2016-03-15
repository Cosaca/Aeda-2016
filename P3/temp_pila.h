#include "temp_lista.h"
#include <iostream>
#pragma once

using namespace std;

template <class TDATO>		//Declaración de la plantilla

class a_stack
{
	private:

	a_list<TDATO> list_;

	public:
		
	a_stack(void);
	~a_stack(void);
    void push(TDATO dato);
	char pop(void);
    bool empty(void);
    void clean(void);
    ostream& write(ostream& os);
    
};


template <class TDATO>
a_stack<TDATO>::a_stack(void):		//Constructor
list_()
{}

template <class TDATO>
a_stack<TDATO>::~a_stack(void)		//Destructor
{
    clean();
}

template <class TDATO>
void a_stack<TDATO>::push(TDATO dato)		//Metodo que mete un elemento de la pila
{
    list_.insert_beginning(new a_node<TDATO>(dato));
}

template <class TDATO>
char a_stack<TDATO>::pop(void)		//Metodo que extrae un elemento de la pila
{
    a_node<TDATO>* node_aux = (list_.extract_beginning());
    TDATO aux = node_aux->get_dato();
    delete node_aux;
    return aux;
}

template <class TDATO>  
bool a_stack<TDATO>::empty(void)		//Metodo que comprueba si la pila esta vacia
{
    return list_.empty();
}

template <class TDATO>
void a_stack<TDATO>::clean(void)		//Metodo que limpia la pila
{
    list_.clean();
}

template <class TDATO>
ostream& a_stack<TDATO>::write(ostream& os)
{
    list_.write(os);
    return os;
}