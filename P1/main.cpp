#include "vector.h"
#include "lista.h"
#include "pila.h"
#include "cola.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main (void)
{
	vector_t A(10);
	sll_t lista;
	stack_t pila; 
	queue_t cola;
	
    int opcion = -1;
   	do
  	{
  		cout << "--> Práctica 1: Implementación de estructuras de datos" << endl;
	    cout << "1. Vector" << endl;
	    cout << "2. Lista" << endl;
	    cout << "3. Pila" << endl;
	    cout << "4. Cola" << endl;
	    cout << "0. Salir"<< endl;
	    cout << "--> Introduzca una opción: ";
	    cin >> opcion;
	
	    switch(opcion)
	    {
	      case 0:
	      exit(0);
	      break;
	      
	      case 1:
	      system("clear");
		  cout << "--> Información sobre el vector: " << endl;
		   
		    for(int i = 0; i < 10; i++)
		    {
		        A[i] = i;
		    }
			
		    A.write();
		    
	      break;
	      
	      case 2:
	      system("clear");
		  cout << "--> Información sobre la lista: " << endl;
		    
		  if(lista.empty())
		  {
		      cout << "--> La lista está vacía" << endl;
		  }
		    
		  cout << "--> Rellenando lista" << endl;
		  for(int i = 0; i < 10; i++)
		  {
		      lista.insert_beginning(new node_t(i));
		  }
		  if(!lista.empty())
		  cout << "--> La lista está llena" << endl;
		  
		  lista.write(std::cout);
		  lista.clean();
		  
		  cout << endl;
		  break;
	      
	      case 3:
			system("clear");
			cout << "--> Insertando elementos en la Pila" << endl; 
			for(int i = 0; i < 10; i++)
			{ 
				pila.push(i);
			}
			cout << "--> Extrayendo de la pila " << endl;
			
			pila.write(std::cout);
			pila.clean();
			cout << endl;
	      break;
	      
	      case 4:
	        system("clear");
			cout << "--> Insertando elementos en la cola" << endl;
			for(int i = 0; i < 10; i++)
			{ 
				cola.put(i);
			}
			cout << "--> Extrayendo elementos de la cola" << endl;
			while(!cola.empty()) 
				cout << cola.get() << " ";	
			
			cout << endl;
			cola.clean();
	      break;
	      
	      default:
	      	system("clear");
	        cout << "Opción no válida." <<endl;
	      break;
	    }
	  }while(opcion != 0);
}