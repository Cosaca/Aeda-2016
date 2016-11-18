#pragma once
#include <iostream>
#include <cstdio>
#include <new>
#include <stdexcept>  

using namespace std;

template <class TDATO>
class mynodo
{
    private:
    
    TDATO dato_; 
    mynodo<TDATO>* next_;
        
    public:
    
    mynodo(void);
    mynodo(TDATO dato);
    ~mynodo(void);
    mynodo<TDATO>* get_next(void);
    TDATO get_dato(void);
    void set_next(mynodo<TDATO>* next);
    void set_dato(TDATO dato);
    ostream& write(ostream& os);
};

template <class TDATO>
mynodo<TDATO>::mynodo(void):
dato_(),
next_(NULL)
{}

template <class TDATO>
mynodo<TDATO>::mynodo(TDATO dato):
dato_(dato),
next_(NULL)
{}

template <class TDATO>
mynodo<TDATO>::~mynodo(void)
{}


template <class TDATO>
mynodo<TDATO>* mynodo<TDATO>::get_next(void)
{
    return next_;
}

template <class TDATO>
TDATO mynodo<TDATO>::get_dato(void)
{
    return dato_;
}

template <class TDATO>
void mynodo<TDATO>::set_next(mynodo<TDATO>* next)
{
    next_ = next;
}

template <class TDATO>
void mynodo<TDATO>::set_dato(TDATO dato)
{
    dato_ = dato;
}

template <class TDATO>
ostream& mynodo<TDATO>::write(ostream& os)
{
    os << dato_ << " ";
}