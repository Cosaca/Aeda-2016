#include <iostream>
#pragma once

using namespace std;

template <class TDATO>

class a_node 
{
    private:
    
    TDATO dato_;
    a_node<TDATO>* next_;

    public:
    
    a_node(void);
    a_node(TDATO dato);
    ~a_node(void);
    void set_next(a_node<TDATO>* next);
	a_node<TDATO>* get_next(void);
	void set_dato(TDATO dato);
	TDATO get_dato(void);
    ostream& write(ostream& os);
};


template <class TDATO>
a_node<TDATO>::a_node(void):     //Constructor
next_(NULL),
dato_()
{}

template <class TDATO>
a_node<TDATO>::a_node(TDATO dato):       //Constructor de copia
next_(NULL),
dato_(dato)
{}

template <class TDATO>
a_node<TDATO>::~a_node(void)     //Destructor
{
    next_ = NULL;
}

template <class TDATO>
void a_node<TDATO>::set_next(a_node<TDATO>* next)       //Metodo que nos situa en el nodo siguiente
{
	next_ = next;
}

template <class TDATO>
a_node<TDATO>* a_node<TDATO>::get_next(void)        //Metodo que nos devuelve el nodo siguiente
{
	return next_;
}

template <class TDATO>
void a_node<TDATO>::set_dato(TDATO dato)        //Metodo que inserta un elemento en el nodo
{
    dato_ = dato;
}

template <class TDATO>
TDATO a_node<TDATO>::get_dato(void)     //Metodo que nos devuelve el elemento de un nodo
{
    return dato_;
}

template <class TDATO>
ostream& a_node<TDATO>::write(ostream& os)
{
    os << dato_ << " ";
}