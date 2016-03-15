#include "cola.h"


queue_t::queue_t(void):
list_()
{}
    
queue_t::~queue_t(void)
{
    clean();
}

void queue_t::put(TDato dato)
{
    list_.insert_beginning(new node_t(dato));
}
    
TDato queue_t::get(void)
{
    node_t* n_aux = (node_t*)(list_.extract_end());
    TDato aux = n_aux->get_dato();
    delete n_aux;
    return aux;
}
    
bool queue_t::empty(void)
{
    return list_.empty();
}

void queue_t::clean(void)
{
    list_.clean();
}

ostream& queue_t::write(ostream& os)
{
    list_.write(os);
    return os;
}
