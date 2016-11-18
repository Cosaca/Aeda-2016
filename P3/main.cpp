#include <iostream>
#include <stdlib.h>

#include "temp_vector.h"
#include "temp_lista.h"
#include "temp_pila.h"
#include "temp_cola.h"

#include "numero.h"
#include "entero.h"
#include "racional.h"
#include "real.h"
#include "complejo.h"

using namespace std;

int main (void)
{
    myvector<numero_t*> A(4);
   	mylista<numero_t*> 	L;
   	mypila<numero_t*> 	pila; 
	a_queue<numero_t*> 	cola;
   	
   	A[0] = new entero(1);
	L.insert_begin(new mynodo<numero_t*>(new entero(1)));
	pila.push(new entero(1));
	cola.put(new entero(1));

	A[1] = new racional(1,5);
	L.insert_begin(new mynodo<numero_t*>(new racional(1,5)));
	pila.push(new racional(1,5));
	cola.put(new racional(1,5));


	A[2] = new real(5.0);
	L.insert_begin(new mynodo<numero_t*>(new real(5.0)));
	pila.push(new real(5.0));
	cola.put(new real(5.0));
		
	A[3] = new complejo(3.2,2.76);
	L.insert_begin(new mynodo<numero_t*>(new complejo(3.2,2.76)));
	pila.push(new complejo(3.2,2.76));
	cola.put(new complejo(3.2,2.76));
   	
   	numero_t* n4 = new entero(1);
   	numero_t* n1 = new racional(4,2);
   	numero_t* n2 = new real(8.3);
   	numero_t* n3 = new complejo(3.3,2);
   	
   	system ("clear");
	cout << "--> Práctica 3: Polimorfismo y excepciones" << endl;
   	cout << "--> Comprobando el procedimiento toEntero" << endl;
   	cout << n4->toEntero() << endl;
   	cout << n1->toEntero() << endl;
   	cout << n2->toEntero() << endl;
   	cout << n3->toEntero() << endl;
   	
   	cout << "--> Comprobando el procedimiento toReal" << endl;
   	cout << n4->toReal() << endl;
   	cout << n1->toReal() << endl;
   	cout << n2->toReal() << endl;
   	cout << n3->toReal() << endl;
   	
   	cout << "--> Comprobando el procedimiento toRacional" << endl;
   	cout << n4->toRacional() << endl;
   	cout << n1->toRacional() << endl;
   	cout << n2->toRacional() << endl;
   	cout << n3->toRacional() << endl;
   	
   	cout << "--> Comprobando el procedimiento toComplejo" << endl;
   	cout << n4->toComplejo() << endl;
   	cout << n1->toComplejo() << endl;
   	cout << n2->toComplejo() << endl;
   	cout << n3->toComplejo() << endl;
   	

	cout << "--> Vector de números" << endl;
	A.imprime_numero(cout);
	cout << endl;
	
	cout << "--> Lista de números" << endl;
	L.imprime_numero(cout);
	cout << endl;
	
	cout << "--> Pila de números" << endl;
	pila.imprime_numero(cout);
	cout << endl;
	
	cout << "--> Cola de números" << endl;
	cola.imprime_numero(cout);
	cout << endl;
}