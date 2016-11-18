#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <class TDATO>
void Insercion(vector<TDATO>& sec, bool demostracion, int& contador)                                //Metodos para realizar insercion
{
    for(int i = 1; i < sec.size(); i++)
    {
        int j = i;
        TDATO x = sec[i];
        sec[-1] = x;

        while(x < sec[j-1])
        {
            sec[j] = sec[j-1];
            j--;
            contador++;
        }
        if(demostracion)
        {
            cout << "Comparando: " << sec[j] << " " << x << endl;
        }

        sec[j] = x;

        if(demostracion)
        {
            cout << endl << "Secuencia: ";
            for(int k = 0; k < sec.size(); k++)
                cout << sec[k] << " ";
            
            cout << endl;
        }
    }
    sec[-1] = 0;
}

template <class TDATO>
void Burbuja(vector<TDATO>& sec, bool demostracion, int& contador)                               //Metodos del Bubblesort
{
    int x = 0;
    for (int i = 1; i < sec.size(); i++)
    {
        for (int j = sec.size()-1; j >= i; j--)
        {
            contador++;
            if (sec[j] < sec[j-1])
            {
                if(demostracion)
                {
                    cout << "Comparando: " << sec[j] << " " << sec[j-1] << endl;
                }
                x = sec[j-1];
                sec[j-1] = sec[j];
                sec[j] = x;

                if(demostracion)
                {
                    cout << endl << "Secuencia: ";
                    for(int k = 0; k < sec.size(); k++)
                        cout << sec[k] << " ";

                    cout << endl;
                }
            }
        }
    }
}

template <class TDATO>
void deltasort(int d, vector<TDATO>& sec, int n, bool demostracion, int& contador)                  //Metodos del ShellSort
{
    TDATO x = 0;
    int j = 0;

    for(int i = d; i < n; i++)
    {
        x = sec[i];
        j = i;
        while((j > (d - 1)) && ( x < sec[j-d]))
        {
            sec[j] = sec[j-d];
            j = (j-d);
            contador++;
        }
        if(sec[j] != x)
        {
            if(demostracion)
            {
                cout << "Comparando: " << sec[j] << " " << x << endl;
            }
            sec[j] = x;
            
            if(demostracion)
            {
	            cout << endl << "Secuencia: ";
	            for(int k=0; k < sec.size(); k++)
	                cout << sec[k] << " ";

	           cout << endl;
            }
        }
    }
}

template <class TDATO>
void ShellSort(vector<TDATO>& sec, bool demostracion, float alpha, int& contador)
{
    int del = alpha * sec.size();
    while (del >= 1)
    {
        deltasort(del, sec, sec.size(), demostracion, contador);
        del = del / 2;
    }
}

template <class TDATO>
void QuickSort(vector<TDATO>& sec, bool demostracion, int ini, int fin, int& contador)              //Metodo para el Quicksort
{
    int i = ini;
    int f = fin;
    int p = sec[(i+f)/2];

    while (i < f)
    {
        while (sec[i] < p)
        {
            i++;
            contador++;
        }

        while (sec[f] > p)
        {
            f--;
            contador++;
        }

        if (i <= f)
        {
            if(demostracion)
            {
                cout << "Comparando: " << sec[i] << " " << sec[f] << endl;
            }
            TDATO x = sec[i];
            sec[i] = sec[f];
            sec[f] = x;
            i++;
            f--;

            if(demostracion)
            {
                cout << endl << "Secuencia: ";
                for(int j2 = 0; j2 < sec.size(); j2++)
                    cout << sec[j2] << " ";

                cout << endl;
            }
        }
    }

    if (ini < f) QuickSort(sec, demostracion, ini, f, contador);
    if (i < fin) QuickSort(sec, demostracion, i, fin, contador);
}

template <class TDATO>
void mezcla(vector<TDATO>& sec, vector<TDATO> U, vector<TDATO> V, bool demostracion, int& contador)           //Metodos para el MergeSort
{
    int i = 0;
    int j = 0;

    if(demostracion)
    {
        cout << "Comparando: "<< endl;
        cout << "U: ";
        for(int m = 0; m < U.size(); m++)
            cout << U[m] << " ";
        cout << "V: ";
        for(int m = 0; m < V.size(); m++)
            cout << V[m] << " ";

        cout << endl;
    }

    for(int k = 0; k < sec.size(); k++)
    {
        contador++;
        if((i < U.size()) && (j < V.size()))
        {
            if(U[i] < V[j])
            {
	            sec[k] = U[i];
	            i++;
            }
            else
            {
	            sec[k] = V[j];
	            j++;
            }
        }
        else
        {
            if(i >= U.size())
            {
        	    sec[k] = V[j];
	            j++;
            }
            else
            {
	            if(j >= V.size())
	            {
	                sec[k] = U[i];
	                i++;
	            }
            }
        }
    }

    if(demostracion)
    {
        cout << endl << "Secuencia: ";
        for(int m = 0; m < sec.size(); m++)
            cout << sec[m] << " ";

        cout << endl;
    }
}

template <class TDATO>
void MergeSort(vector<TDATO>& sec, bool demostracion, int& contador)
{
    if(sec.size() > 1)
    {
        vector<TDATO> U(sec.begin(),(sec.begin()+sec.size()/2));
        vector<TDATO> V((sec.begin()+sec.size()/2), sec.end());

        MergeSort(U, demostracion, contador);
        MergeSort(V, demostracion, contador);
        mezcla(sec, U, V, demostracion, contador);
    }
}

template <class TDATO>
void Estadisticas(void)                                                             //Funciónes de Estadística y Desmotración
{
    cout << "--> Modo estadística" << endl;
    int p = 0;
    int n = 0;
    srand(time(NULL));
    cout << "--> Introduzca el tamaño de la secuencia a ordenar: ";
    cin >> n;
    cout << "--> Introduzca el número de pruebas que se ejecutarán sobre cada método: ";
    cin >> p;
    cout << endl;

    vector< vector<TDATO> > Estadistica(p, vector<TDATO> (n,0));

    for(int j = 0; j < p; j++)
    {
        for(int k = 0; k < n; k++)
            Estadistica[j][k] = rand() % 30000000+50000000;
    }
    vector<TDATO> aux;

    vector<int> no(5,0);
    vector<int> max(5,0);
    vector<int> min(5,999999999);
    vector< vector<double> > cont(5,vector<double> (p,0.0));
    vector<double> med(5,0);

    for(int i = 0; i < p; i++)
    {
        aux = Estadistica[i];

        Insercion(aux,false,no[0]);
        aux = Estadistica[i];

        Burbuja(aux,false, no[1]);
        aux = Estadistica[i];

        ShellSort(aux,false,1.0,no[2]);
        aux = Estadistica[i];

        QuickSort(aux,false,0,Estadistica[i].size()-1,no[3]);
        aux = Estadistica[i];

        MergeSort(aux,false,no[4]);
        aux = Estadistica[i];

        for(int j = 0; j < 5; j++)
        {
            if(no[j] < min[j])
                min[j] = no[j];

            if(no[j] > max[j])
                max[j] = no[j];

            cont[j][i] = no[j];
            no[j] = 0;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < p; j++)
        {
            med[i]+= cont[i][j];
        }
        med[i] = (med[i]/p);
    }

    cout << setw(40) << "Número de comparaciones" << endl;
    cout << " " <<  setw(24) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
    cout << "Inserción" << setw(15) << min[0]; cout << setw(15) << med[0]; cout << setw(15) << max[0] << endl;
    cout << "BubbleSort" << setw(14) << min[1]; cout << setw(15) << med[1]; cout << setw(15) << max[1] << endl;
    cout << "ShellSort" << setw(15) << min[2]; cout << setw(15) << med[2]; cout << setw(15) << max[2] << endl;
    cout << "QuickSort" << setw(15) << min[3]; cout << setw(15) << med[3]; cout << setw(15) << max[3] << endl;
    cout << "MergeSort" << setw(15) << min[4]; cout << setw(15) << med[4]; cout << setw(15) << max[4] << endl;
    cout << endl;
}

template <class TDATO>
void Demostraciones(void)
{
    cout << "--> Modo demostracion" << endl;
    int op = -1;
    int n = 0;
    srand(time(NULL));
    cout << "--> Introduzca el tamaño de la secuencia a ordenar: ";
    cin >> n;

    vector<TDATO> Demostracion(n,0);
    for(int i = 0; i < n ; i++)
    {
        Demostracion[i] = rand() % 30000000+50000000;
    }

    cout << "--> Tipos de Algoritmos: " << endl;
    cout << "--> 0. Inserción" << endl;
    cout << "--> 1. BubbleSort" << endl;
    cout << "--> 2. ShellSort" << endl;
    cout << "--> 3. QuickSort" << endl;
    cout << "--> 4. MergeSort" << endl;
    cout << "--> Elija una opción (0-4): ";
    cin >> op;
    cout << endl;

    cout << "Secuencia desordenada: ";
    for(int k = 0; k < Demostracion.size(); k++)
        cout << Demostracion[k] << " ";

    cout << endl;

    int dummy = 0;
    switch(op)
    {
        case 0:
            Insercion(Demostracion,true,dummy);
        break;
        case 1:
            Burbuja(Demostracion,true,dummy);
        break;
        case 2:
            ShellSort(Demostracion,true,0.5,dummy);
        break;
        case 3:
            QuickSort(Demostracion,true,0,Demostracion.size()-1,dummy);
        break;
        case 4:
            MergeSort(Demostracion,true,dummy);
        break;
    }

    cout << "Secuencia ordenada: ";
    for(int i = 0; i < Demostracion.size(); i++)
        cout << Demostracion[i] << " ";

    cout << endl << endl;
}