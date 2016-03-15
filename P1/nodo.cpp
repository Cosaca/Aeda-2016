#include "nodo.h"

node_t::node_t(void):
next_(NULL),
dato_()
{}

node_t::node_t(TDato dato):
next_(NULL),
dato_(dato)
{}

node_t::~node_t(void)
{
    next_ = NULL;
}

void node_t::set_next(node_t* next)
{
	next_ = next;
}

node_t* node_t::get_next(void)
{
	return next_;
}

void node_t::set_dato(TDato dato)
{
    dato_ = dato;
}

TDato node_t::get_dato(void)
{
    return dato_;
}

ostream& node_t::write(ostream& os)
{
    os << dato_ << " ";
}