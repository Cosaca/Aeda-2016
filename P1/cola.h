#include "lista.h"
#include <iostream>
#pragma once

using namespace std;

typedef int TDato;

class queue_t 
{
    
    private:
    
    sll_t list_;

    public:
    
    queue_t(void);
    ~queue_t(void);
    void put(TDato dato);
	TDato get(void);
	bool empty(void);
	void clean(void);
    ostream& write(ostream& os);

};
