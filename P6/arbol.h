#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include "nodo.h"
#pragma once

using namespace std;

template <class TDATO>
class ArbolB
{
    private:
  
    nodoB<TDATO>* raiz;
  
    public:
    
    ArbolB() : raiz(NULL) {}                  //Constructor
    ~ArbolB() { Podar(raiz); }                //Destructor
    
    void Podar(nodoB<TDATO>* &nodo);
  
    //int niveles(void);
  
    nodoB<TDATO>* Buscar(TDATO clave_dada, int& a);                           //Métodos de búsqueda
    nodoB<TDATO>* BuscarRama(nodoB<TDATO>* nodo, TDATO clave_dada, int& a);
  
    void Insertar(TDATO clave_dada);                                          //Métodos de inserción
    void InsertarRama(nodoB<TDATO>* &nodo, TDATO clave_dada);
  
    void Eliminar(TDATO clave_dada);                                          //Métodos de eliminación
    void EliminarRama(nodoB<TDATO>* &nodo, TDATO clave_dada);
  
    void sustituye(nodoB<TDATO>* &eliminado, nodoB<TDATO>* &sust);            //Método de sustitución
  
    void imprimir(void);                                                      //Método que imprime
};

template <class TDATO>
void ArbolB<TDATO>::Podar(nodoB<TDATO>* &nodo)
{
  if(nodo == NULL) return;
  Podar(nodo->izdo);                //Podar subarbol izquierdo
  Podar(nodo->dcho);                //Podar subarbol derecho
  delete nodo;                      //Eliminar nodo
  nodo = NULL;
}

//Búsqueda
template <class TDATO>
nodoB<TDATO>* ArbolB<TDATO>::Buscar(TDATO clave_dada, int& a)
{
  return BuscarRama(raiz, clave_dada, a);
}

template <class TDATO>
nodoB<TDATO>* ArbolB<TDATO>::BuscarRama(nodoB<TDATO>* nodo, TDATO clave_dada, int& a)
{
  a++;
  if(nodo == NULL)
    return NULL;
  if(clave_dada == nodo->clave)
    return nodo;
  if(clave_dada < nodo->clave)
    return BuscarRama(nodo->izdo, clave_dada, a);
  return BuscarRama(nodo->dcho, clave_dada, a);
}

//Inserción
template <class TDATO>
void ArbolB<TDATO>::Insertar(TDATO clave_dada)
{
  InsertarRama(raiz, clave_dada);
}

template <class TDATO>
void ArbolB<TDATO>::InsertarRama(nodoB<TDATO>* &nodo, TDATO clave_dada)
{
  if(nodo == NULL)
    nodo = new nodoB<TDATO>(clave_dada, clave_dada);
  else if(clave_dada < nodo->clave)
    InsertarRama(nodo->izdo, clave_dada);
  else
    InsertarRama(nodo->dcho, clave_dada);
}
  
//Eliminación
template <class TDATO>
void ArbolB<TDATO>::Eliminar(TDATO clave_dada)
{
  EliminarRama(raiz,clave_dada);
}
 
template <class TDATO>
void ArbolB<TDATO>::EliminarRama(nodoB<TDATO>* &nodo, TDATO clave_dada)
{
  if(nodo == NULL) return;
  if(clave_dada < nodo->clave)
    EliminarRama(nodo->izdo, clave_dada);
  else if(clave_dada > nodo->clave)
    EliminarRama(nodo->dcho,clave_dada);
  else 
  {                                //clave_dada == nodo->clave
  nodoB<TDATO>* Eliminado=nodo;
  if(nodo->dcho == NULL)
    nodo = nodo->izdo;
  else if(nodo->izdo == NULL)
    nodo = nodo->dcho;
  else
    sustituye(Eliminado, nodo->izdo);
     
    delete(Eliminado);
   }
}
 
//Sustitución
template <class TDATO>
void ArbolB<TDATO>::sustituye(nodoB<TDATO>* &eliminado, nodoB<TDATO>* &sust)
{
  if(sust->dcho != NULL)
    sustituye(eliminado, sust->dcho);
  else
  {
    eliminado->dato = sust->dato;
    eliminado->clave = sust->clave;
    eliminado = sust;
    sust=sust->izdo;
  }
}

/*template <class TDATO>
int ArbolB<TDATO>::niveles(void)
{
  int nv=0;
  nodoB<TDATO>* aux = raiz;
  
  while(aux->izdo != NULL)
  {
    aux = aux->izdo;
    nv++;
  }
  return nv;
}*/

template <class TDATO>
void ArbolB<TDATO>::imprimir(void)
{
  nodoB<TDATO>* aux = raiz;
  int i = 0;
  bool marca;
  int p;
  
  vector< nodoB<TDATO>* > vacio;
  
  vector< vector< nodoB<TDATO>* > > V(1);
  V[0] = vector< nodoB<TDATO>* >(1,aux);
  bool end=false;
  
  while(!end)
  {
    p = pow(2,i);
    
    V.push_back(vacio);
    
    for(int j = 0; j < p; j++)
    {
      if(V[i][j] != NULL)
      {
        V[i+1].push_back(V[i][j]->izdo);
        V[i+1].push_back(V[i][j]->dcho);
      }
      else
      {
	      V[i+1].push_back(NULL);
	      V[i+1].push_back(NULL);
      }
      
      end = true;
      for(int m = 0; m < p; m++)
      {
        if(V[i][m] != NULL)
	      end = false;
      }
    }
    i++;
  }
  
  for(int k = 0; k < V.size(); k++)
  {
    marca = false;
    for(int n = 0; n < V[k].size(); n++) if(V[k][n]!=NULL) marca=true;
    
    if(marca)
    cout << "--> Nivel " << k << ": ";
    
    for(int l = 0; l < V[k].size(); l++)
    {
      if(marca)
      if((V[k][l]!=NULL))
	      cout << "[" << V[k][l]->dato << "] ";
      else
	      cout << "[.] ";
    }
    cout << endl;
  }
}