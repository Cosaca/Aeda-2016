#include <iostream>
#include <new>
#include <stdexcept>  
#include "numero.h"
#pragma once

using namespace std;

template <class TDATO>
class myvector
{
    private:
        
    TDATO* v_;
    int sz_;
    
    public:
        
    myvector(void);
    myvector(int sz);
    myvector(const myvector<TDATO>& v);
    ~myvector(void);
    void resize(int sz);
    int get_sz(void);
    int get_sz(void) const;
    TDATO& operator[](int pos);
    TDATO operator[](int pos) const;
    void write(void);
    ostream& imprime_numero(ostream& os);
    
    private:
    
    void build_vector(int sz);
    void clean(void);
};

template <class TDATO>
myvector<TDATO>::myvector(void):
v_(NULL),
sz_(0)
{}

template <class TDATO>
myvector<TDATO>::myvector(int sz):
sz_(sz)
{
    build_vector(sz);
}

template <class TDATO>
myvector<TDATO>::myvector(const myvector<TDATO>& v)
{
    build_vector(v.get_sz());
    for (int i = 0; i<v.get_sz(); i++)
    {
        v_[i] = v[i];
    }
}

template <class TDATO>
myvector<TDATO>::~myvector(void)
{
    clean();
}

template <class TDATO>
void myvector<TDATO>::resize(int sz)
{
    clean();
    sz_ = sz;
    build_vector(sz_);
}

template <class TDATO>
int myvector<TDATO>::get_sz(void)
{
    return sz_;
}

template <class TDATO>
int myvector<TDATO>::get_sz(void) const
{
    return sz_;
}

template <class TDATO>
TDATO& myvector<TDATO>::operator[](int pos)
{
    try
    {
        if((pos > sz_) || (pos < 0)) {throw "fuera de rango";}
        
        return v_[pos];
		
	}
	catch(const char* a)
	{
		cerr << "--> Fallo al obtener el elemento, porque la posición está fuera de rango." << endl;
		exit(1);
	}
}

template <class TDATO>
TDATO myvector<TDATO>::operator[](int pos) const
{
    try
    {
        if((pos > sz_) || (pos < 0)) {throw "fuera de rango";}
        
        return v_[pos];
	}
	catch(const char* a)
	{
		cerr << "--> Fallo al obtener el elemento, porque la posición está fuera de rango." << endl;
		exit(1);
	}
}

template <class TDATO>
void myvector<TDATO>::write(void)
{
    cout << "Tamaño: " << get_sz() << endl;
    for(int i = 0; i<10; i++)
    {
        cout << v_[i] << " ";
    }
    cout << endl;
}

template <class TDATO>        
void myvector<TDATO>::build_vector(int sz)
{
    try
    {
        v_ = new TDATO [sz];
    }
    catch (bad_alloc& ba)
    {
        cerr << ba.what() << endl;
        exit(1);
    }
    
}

template <class TDATO>
void myvector<TDATO>::clean(void)
{
    if (v_ != NULL)
    {
        delete [] v_;
        v_ = NULL;
        sz_ = 0;
    }
}

template <>
ostream& myvector<numero_t*>::imprime_numero(ostream& os)
{
    for(int i = 0; i<sz_;i++) 
    {
        v_[i]->toStream(os);
        cout << " ";
    }
	return os;
}

