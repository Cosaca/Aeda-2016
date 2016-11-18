#include "dni.h"
#include "ordenacion.h"
#include <iostream>

using namespace std;

int main (void)
{
    int opcion = 0;
    do
  	{
  		cout << "--> Práctica 5: Ordenación" << endl;
	    cout << "--> 1. Modo demostracion" << endl;
	    cout << "--> 2. Modo estadistica" << endl;
	    cout << "--> 0. Salir"<< endl;
	    cout << "--> Introduzca una opción: ";
	    cin >> opcion;
        switch(opcion)
        {
            case 0:
	    	    exit(0);
	        break;
	        case 1:
                Demostraciones<DNI>();
	        break;
	        case 2:
	            Estadisticas<DNI>();
	        break;
	        default:
	      	    system("clear");
	            cout << "--> Opción incorrecta." << endl;
	        break;
	    }
	  }while(opcion != -1);
}