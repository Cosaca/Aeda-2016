#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "temp_lista.h"

using namespace std;

template <class TDATO>
class mypila
{
    private:
    
    mylista<TDATO> l_;

    public:
    
    mypila(void);
    ~mypila(void);
	void push(TDATO dato);
	char pop(void);
	bool empty(void);
	void clean(void);
	ostream& write(ostream& os);
    ostream& imprime_numero(ostream& os);
};

template <class TDATO>
mypila<TDATO>::mypila(void):
l_()
{}

template <class TDATO>
mypila<TDATO>::~mypila(void)
{
    clean();  
}

template <class TDATO>
void mypila<TDATO>::push(TDATO dato)
{
    try
    {
        l_.insert_begin(new mynodo<TDATO>(dato));
    } 
    catch(bad_alloc& ba)
    {
        cerr << ba.what() << endl;
        exit(1);
    }

}

template <class TDATO>
char mypila<TDATO>::pop(void)
{
    try
    {
        if(empty()) {throw "Lista está vacía"; }
        mynodo<TDATO>* nodo_aux = l_.extract_begin();
        TDATO aux = nodo_aux->get_dato();
        delete nodo_aux;
        return aux;
    } 
    catch(const char* a)
    {
        cerr << "--> Fallo, porque la pila está vacía" << endl;
        exit(1);
    }
}

template <class TDATO>
bool mypila<TDATO>::empty(void)
{
    return l_.empty();
}

template <class TDATO>
void mypila<TDATO>::clean(void)
{
    l_.clean();
}

template <class TDATO>
ostream& mypila<TDATO>::write(ostream& os)
{
    l_.write(os);
    return os;   
}
template <>
ostream& mypila<numero_t*>::imprime_numero(ostream& os)
{
    mynodo<numero_t*>* aux;
    while(!l_.empty())
    {
        aux = l_.extract_end();
        aux->get_dato()->toStream(cout);
        cout << " ";
    }
}
