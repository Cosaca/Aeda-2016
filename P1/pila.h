#include "lista.h"
#include <iostream>
#pragma once

using namespace std;

typedef int TDato;

class stack_t
{

	private:

	sll_t list_;

	public:
		
	stack_t(void);
	~stack_t(void);
    void push(TDato dato);
	char pop(void);
    bool empty(void);
    void clean(void);
    ostream& write(ostream& os);
    
};