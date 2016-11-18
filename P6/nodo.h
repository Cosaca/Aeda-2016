#pragma once

template <class TDATO>
class nodoB
{
    public:

    TDATO dato;
    TDATO clave;
    nodoB *izdo;
    nodoB *dcho;
    
    nodoB(TDATO dat, TDATO cl, nodoB *izq = NULL, nodoB *der = NULL):
    dato(dat), 
    clave(cl), 
    izdo(izq), 
    dcho(der)
    {}
};