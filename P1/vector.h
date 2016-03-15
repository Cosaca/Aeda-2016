#include <iostream>
#pragma once

using namespace std;

typedef int TDato;

class vector_t
{

    private:

    TDato* v_;
    int sz_;

    public:

    vector_t(void);
    vector_t(int sz);
    vector_t(const vector_t& v);
    ~vector_t(void);
    void resize(int sz);
    int get_sz(void);
    int get_sz(void) const;
    TDato& operator[](int pos);
    TDato operator[](int pos) const;
    void write(void);
    
    private:
    
    void build_vector(int sz);
    void destroy_vector(void);
};