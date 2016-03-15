#include <iostream>
#include "vector.h"


vector_t::vector_t(void):     
v_(NULL),
sz_(0)
{}

vector_t::vector_t(int sz):     
v_(NULL),
sz_(sz)
{
    v_ = new TDato [sz_];
}

vector_t::vector_t(const vector_t& v):
v_(NULL),
sz_(v.get_sz())
{
    build_vector(v.get_sz());
    for (int i = 0; i<v.get_sz(); i++)
    {
        v_[i] = v[i];
    }
}

vector_t::~vector_t(void)      
{
    destroy_vector();
}

void vector_t::resize(int sz)       
{
    destroy_vector();
    sz_ = sz;
    build_vector(sz);
}

int vector_t::get_sz(void)      
{
    return sz_;
}

int vector_t::get_sz(void) const     
{
    return sz_;
}

TDato& vector_t::operator[](int pos)
{
    return v_[pos];
}

TDato vector_t::operator[](int pos) const
{
    return v_[pos];
}

void vector_t::build_vector(int sz)
{
    v_ = new TDato [sz];
}

void vector_t::destroy_vector(void)
{
    if (v_ != NULL){
        delete [] v_;
        v_ = NULL;
    }
}

void vector_t::write(void)
{
    cout << "--> Tamaño: " << get_sz() << endl;
    for(int i = 0; i<10; i++)
    {
        cout << v_[i] << " ";
    }
    cout << endl;
}
