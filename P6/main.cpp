#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "arbol.h"
#include "dni.h"

using namespace std;

int main(void)
{
    ArbolB<DNI> Tree;
    
    srand(time(NULL));
    unsigned menu1, menu2, Nodes, Test;
    bool salir = false;                                         //Para seguir imprimiendo el menu
    DNI datos;
    int dato;
    
    system("clear");
    cout << endl;
    cout << "--> Práctica 6: Árbol Binario de Búsqueda"<< endl;
    cout << endl << "--> 0. Modo demostración" << endl;
    cout << "--> 1. Modo estadística" << endl;
    cout << endl << "--> Selecciona un modo: ";
    cin >> menu1;
    cout << endl;
    
    if(menu1 == 0)
    {
        while(!salir)
        {
            cout << "---- Modo Demostración ----" << endl;
            cout << "--> 1. Insertar clave" << endl;
            cout << "--> 2. Eliminar clave" << endl;
            cout << "--> 0. Salir" << endl;
            cout << endl;
            cout << "--> Selecciona opción: ";
            cin >> menu2;
            
            switch(menu2)
            {
                case 0:
                    salir = true;
                break;
                
                case 1:
                    cout << endl;
                    cout << "--> Insertar: ";
                    cin >> dato;
                    datos = dato;
                    Tree.Insertar(datos);
                    Tree.imprimir();
                break;
                
                case 2:
                    cout << endl;
                    cout << "--> Eliminar: ";
                    cin >> dato;
                    datos = dato;
                    Tree.Eliminar(datos);
                    Tree.imprimir();
                break;
                
                default:
                    cout << "--> Opción inválida. Terminando ejecución.";
                    exit(1);
            }
        }
    }
    if(menu1 == 1)
    {
        cout << "---- Modo Estadística ---- " << endl;
        cout << endl;
        cout << "--> Indique el número de nodos que tiene el árbol: ";
        cin >> Nodes;
        cout << endl;
        cout << "--> Indique el número de pruebas: ";
        cin >> Test;
        cout << endl;
        
        vector<DNI> Pruebas(2*Nodes, 0);                    //El banco de pruebas contiene el doble de elementos que nodos tiene el arbol
        
        for(int i = 0; i< 2*Nodes; i++) 
        {
            Pruebas[i] = rand() % 30000000+50000000;
        }
        
        for(int j = 0; j < Nodes; j++)
        {
            Tree.Insertar(Pruebas[j]);                      //Insertamos la primera mitad del banco de pruebas
        }
        
        vector<int> comparaciones(2,0);                     //Guardara el numero de comparaciones
        vector<int> max(2,0);                               //Almacena el numero maximo de comparaciones que se regitre
        vector<int> min(2,999999999);                       //Almacena el numero minimo de comparaciones que se registre
        vector< vector<double> > cont(2, vector<double> (Test, 0.0)); //Almacena los valores de todas las pruebas y lo usaremos para hacer la media
        vector<double> media(2,0);
        
        for(int k = 0; k < Test; k++)
        {
            Tree.Buscar(Pruebas[rand()%(Nodes+1)], comparaciones[0]);                       //1a mitad del banco de pruebas previamente insertada
            
            Tree.Buscar(Pruebas[Nodes + rand()%(2*Nodes+1-Nodes)], comparaciones[1]);       //2a mitad del banco sin insertar
            
            
            for(int l = 0; l < 2; l++)
            {
                if(comparaciones[l] < min[l])
                    min[l] = comparaciones[l];
                    
                if(comparaciones[l] > max[l])
                    max[l] = comparaciones[l];
                    
                cont[l][k] = comparaciones[l];
                comparaciones[l] = 0;
            }
        }
        
        for(int w = 0; w < 2; w++)
        {
            for(int z= 0; z < Test; z++)
            {
                media[w] += cont[w][z];
            }
            
            media[w] = (media[w]/Test);
        }
        
        cout << setw(40) << "Número de comparaciones" << endl;
        cout << " " <<  setw(24) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
        cout << "Búsqueda " << setw(15) << min[0]; cout << setw(15) << media[0]; cout << setw(15) << max[0] << endl;
        cout << "Inserción" << setw(15) << min[1]; cout << setw(15) << media[1]; cout << setw(15) << max[1] << endl;
    }
}