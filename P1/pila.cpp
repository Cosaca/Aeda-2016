#include "pila.h"

stack_t::stack_t(void):
list_()
{}
    
stack_t::~stack_t(void)
{
    clean();
}

void stack_t::push(TDato dato)
{
    list_.insert_beginning(new node_t(dato));
}
    
char stack_t::pop(void)
{
    node_t* node_aux = (node_t*)(list_.extract_beginning());
    TDato aux = node_aux->get_dato();
    delete node_aux;
    return aux;
}
    
bool stack_t::empty(void)
{
    return list_.empty();
}

void stack_t::clean(void)
{
    list_.clean();
}

ostream& stack_t::write(ostream& os)
{
    list_.write(os);
    return os;
}