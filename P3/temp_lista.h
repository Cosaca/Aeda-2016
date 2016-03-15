#include "temp_nodo.h"
#include <iostream>
#pragma once

using namespace std;

template <class TDATO>      //Declaracion de la plantilla

class a_list 
{
    private:
        
    a_node<TDATO>* beginning_;
    a_node<TDATO>* end_;

    public:
        
    a_list(void);
    ~a_list(void);
    void insert_beginning(a_node<TDATO>* n);
    a_node<TDATO>* extract_beginning(void);
    void insert_end(a_node<TDATO>* n);
    a_node<TDATO>* extract_end(void);
    bool empty(void);	
    void clean(void);
	ostream& write(ostream& os);
};


template <class TDATO>
a_list<TDATO>::a_list(void):     //Constructor
beginning_(NULL),
end_(NULL)
{}

template <class TDATO>
a_list<TDATO>::~a_list(void)         //Destructor
{
    clean();
}

template <class TDATO>
bool a_list<TDATO>::empty(void)       //Metodo que comprueba si esta vacia
{
    return (beginning_ == NULL);
}

template <class TDATO>
void a_list<TDATO>::insert_beginning(a_node<TDATO>* n)     //Metodo que inserta elementos por el principio
{
    if(empty())
    {
        beginning_ = n;
        end_ = n;
    }
    else
    {
        n->set_next(beginning_);
        beginning_ = n;
    }
}

template <class TDATO>
a_node<TDATO>* a_list<TDATO>::extract_beginning(void)      //Metodo que extrae elementos por el principio
{
    if(beginning_ == end_)
    {
        a_node<TDATO>* aux;
        aux = beginning_;
        end_ == NULL;
        beginning_ == NULL;
        return aux;
    }
    else
    {
        a_node<TDATO>* aux = beginning_;
        beginning_ = beginning_->get_next();
        return aux;
    }
}

template <class TDATO>
void a_list<TDATO>::insert_end(a_node<TDATO>* n)      //Metodo que inserta por el final
{
    if(empty())
    {
        beginning_ = n;
        end_ = n;
    }
    else
    {
        end_->set_next(n);
        end_ = n;
    }
}

template <class TDATO>
a_node<TDATO>* a_list<TDATO>::extract_end(void)       //Metodo que extrae por el final
{
    if(beginning_ == end_)
    {
        a_node<TDATO>* aux = beginning_;
        beginning_ == NULL;
        end_ == NULL;
        return aux;
    }
    else
    {
        a_node<TDATO>* aux = beginning_;
        
        while(aux->get_next() != end_)
           aux = aux->get_next(); 
        
        end_ = aux;
        aux = aux->get_next();
        end_->set_next(NULL);
        return aux;
    }
}

template <class TDATO>
ostream& a_list<TDATO>::write(ostream& os)        //Metodo que imprime
{
    a_node<TDATO>* aux = beginning_;
    
    while (aux != NULL) {
        aux->write(os);
        aux = aux->get_next();
    }
}

template <class TDATO>
void a_list<TDATO>::clean(void)     //Metodo que limpia la lista
{
    while (beginning_ != NULL) {
        a_node<TDATO>* aux = beginning_;
        beginning_ = beginning_->get_next();
        delete aux;
    } 
}