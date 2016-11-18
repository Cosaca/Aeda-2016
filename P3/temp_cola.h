#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "temp_lista.h"

using namespace std;

template <class TDATO>
class a_queue 
{
    private:
    
    mylista<TDATO> l_;
        
    public:
    
    a_queue(void);
    ~a_queue(void);
    void put(TDATO dato);
    TDATO get(void);
    bool empty(void);
    void clean(void);
    ostream& write(ostream& os);
    ostream& imprime_numero(ostream& os);
};

template <class TDATO>
a_queue<TDATO>::a_queue(void):
l_()
{}

template <class TDATO>
a_queue<TDATO>::~a_queue(void)
{
    clean();
}

template <class TDATO>
void a_queue<TDATO>::put(TDATO dato)
{
    try
    {
        l_.insert_begin(new  mynodo<TDATO>(dato));
    } 
    catch(bad_alloc& ba)
    {
        cerr << ba.what() << endl;
        exit(1);
    }

}

template <class TDATO>
TDATO a_queue<TDATO>::get(void)
{
    try
    {
        if(empty()) {throw "L está vacía"; }
        mynodo<TDATO>* nodo_aux = l_.extract_end();
        TDATO aux = nodo_aux->get_dato();
        delete nodo_aux;
        return aux;
    } 
    catch(const char* a)
    {
        cerr << "--> Fallo, porque la cola está vacía" << endl;
        exit(1);
    }
    
}

template <class TDATO>
bool a_queue<TDATO>::empty(void)
{
    return l_.empty();
}

template <class TDATO>
void a_queue<TDATO>::clean(void)
{
    l_.clean();
}

template <class TDATO>
ostream& a_queue<TDATO>::write(ostream& os)
{
   l_.write(os);
    return os; 
}

template <>
ostream& a_queue<numero_t*>::imprime_numero(ostream& os)
{
    l_.imprime_numero(os);
}
