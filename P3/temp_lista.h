#pragma once
#include "temp_nodo.h"
#include <iostream>
#include <cstdio>

using namespace std;

template <class TDATO>
class mylista
{
	private:
    
    mynodo<TDATO>* head_;
    mynodo<TDATO>* tail_;

  	public:
    
    mylista(void);
    ~mylista(void);
    bool empty(void);
    void clean(void);
    void write(ostream& os);
    void insert_begin(mynodo<TDATO>* aux);
    void insert_end(mynodo<TDATO>* aux);
    mynodo<TDATO>* extract_begin(void);
    mynodo<TDATO>* extract_end(void);
    ostream& imprime_numero(ostream& os);
};

template <class TDATO>
mylista<TDATO>::mylista(void):
head_(NULL),
tail_(NULL)
{}

template <class TDATO>
mylista<TDATO>::~mylista(void)
{
	clean();
}
    
template <class TDATO>
bool mylista<TDATO>::empty(void)
{
    if(head_ == NULL)
        return true;
    else
        return false;
}
    
template <class TDATO>
void mylista<TDATO>::clean(void)
{
    while (head_ != NULL) 
	{
       	mynodo<TDATO>* aux = head_;
        head_ = head_->get_next();
        delete aux;
    }
}
    
template <class TDATO>
void mylista<TDATO>::write(ostream& os)
{
    mynodo<TDATO>* aux = head_;
    while(aux != NULL)
    {
        aux->write(os);
        aux= aux->get_next();
    }
}
    
template <class TDATO>
void mylista<TDATO>::insert_begin(mynodo<TDATO>* aux)
{
    if(empty())
	{
        head_ = aux;
        tail_ = aux;
	}
	else 
	{ 
		try
    	{
			aux->set_next(head_);
		 	head_=aux;
    	} 
      	catch(std::bad_alloc& ba)
    	{
      		std::cerr << ba.what() << std::endl;
      		exit(1);
    	}
	}
}

template <class TDATO>
void mylista<TDATO>::insert_end(mynodo<TDATO>* aux)
{
	if(empty())
	{
	    head_= aux;
	    tail_=aux;
	}
	else 
	{
		try
    	{
			tail_->set_next(aux);
	    	tail_=aux;
    	} 
      	catch(std::bad_alloc& ba)
    	{
      		std::cerr << ba.what() << std::endl;
      		exit(1);
    	}
	}
}

template <class TDATO>
mynodo<TDATO>* mylista<TDATO>::extract_begin(void)
{
    try
    {
        if(empty()) {throw "vacío";}
        
        if(head_ == tail_)
		{
			mynodo<TDATO>* aux=head_;
			head_=NULL;
			tail_=NULL;
			return aux;
		}
		else
		{
			mynodo<TDATO>* aux = head_;
			head_=head_->get_next();
			return aux;
		}
		
	}
	catch(const char* a)
	{
		cerr << "--> Fallo al obtener el elemento, porque la lista está vacía." << endl;
		exit(1);
	}
    
}

template <class TDATO>
mynodo<TDATO>* mylista<TDATO>::extract_end(void)
{
	try
	{
		if(empty()) {throw "vacío";}
	
	    if(head_==tail_)
		{
			mynodo<TDATO>* aux=head_;
			head_=NULL;
			tail_=NULL;
			return aux;
		}
		else
		{
			mynodo<TDATO>* aux=head_;
			while(aux->get_next() != tail_)
				aux=aux->get_next();
		    
		    tail_= aux;
		    aux=aux->get_next();
		    tail_->set_next(NULL);
		    return aux;
		}
	}
	catch(const char* a)
	{
		cerr << "--> Fallo al obtener el elemento, porque la lista está vacía." << endl;
		exit(1);
	}
}

template <>
ostream& mylista<numero_t*>::imprime_numero(ostream& os)
{
	mynodo<numero_t*>* aux = head_;
  
  	while(aux != NULL) 
  	{
  		aux->get_dato()->toStream(os);
    	cout<< " ";
    	aux= aux->get_next();
  	}
  
}
