#include <iostream>
#pragma once

using namespace std;

typedef int TDato;

class node_t 
{
    
    private:
    
    TDato dato_;
    node_t* next_;

    public:
    
    node_t(void);
    node_t(TDato dato);
    ~node_t(void);
    void set_next(node_t* next);
	node_t* get_next(void);
	void set_dato(TDato dato);
	TDato get_dato(void);
    ostream& write(ostream& os);
};