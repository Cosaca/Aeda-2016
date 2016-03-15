#include "lista.h"

using namespace std;

sll_t::sll_t(void):     //Constructor
beginning_(NULL),
end_(NULL)
{}

sll_t::~sll_t(void)         //Destructor
{
    clean();
}
 
bool sll_t::empty(void)       //Comprueba si esta vacia
{
    return (beginning_ == NULL);
}

void sll_t::insert_beginning(node_t* n)     //Inserta elementos por el principio
{
    if(empty())
    {
        beginning_ = n;
        end_ = n;
    }
    else
    {
        n->set_next(beginning_);
        beginning_ = n;
    }
}

node_t* sll_t::extract_beginning(void)      //Extrae elementos por el principio
{
    if(beginning_ == end_)
    {
        node_t* aux;
        aux = beginning_;
        end_ == NULL;
        beginning_ == NULL;
        return aux;
    }
    else
    {
        node_t* aux = beginning_;
        beginning_ = beginning_->get_next();
        return aux;
    }
}

void sll_t::insert_end(node_t* n)      //Inserta por el final
{
    if(empty())
    {
        beginning_ = n;
        end_ = n;
    }
    else
    {
        end_->set_next(n);
        end_ = n;
    }
}

node_t* sll_t::extract_end(void)       //Extrae por el final
{
    if(beginning_ == end_)
    {
        node_t* aux = beginning_;
        beginning_ == NULL;
        end_ == NULL;
        return aux;
    }
    else
    {
        node_t* aux = beginning_;
        
        while(aux->get_next() != end_)
           aux = aux->get_next(); 
        
        end_ = aux;
        aux = aux->get_next();
        end_->set_next(NULL);
        return aux;
    }
}

ostream& sll_t::write(ostream& os)        //Imprime
{
    node_t* aux = beginning_;
    
    while (aux != NULL) {
        aux->write(os);
        aux = aux->get_next();
    }
}

void sll_t::clean(void)     //Limpia la lista
{
    while (beginning_ != NULL) {
        node_t* aux = beginning_;
        beginning_ = beginning_->get_next();
        delete aux;
    } 
}