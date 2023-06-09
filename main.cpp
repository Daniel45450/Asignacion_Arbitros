#include <iostream>
#include "Partido.h"
#include "Loader.h"
#include "imprimir_info.h"

using namespace std;

int main()
{
    int cant_partidos;
    int cant_equipos;
    int cant_arbitros;
    Loader loader;
    cout << "Ingresa la cantidad de equipos: ";
    cin >> cant_equipos;
    cant_partidos = cant_equipos/2;
    cout << "Ingresa la cantidad de arbitros: ";
    cin >> cant_arbitros;
    while(cant_arbitros <= cant_partidos) {
        cout << "Deben haber una cantidad mayor de " << cant_partidos << " de arbitros, ingresalos nuevamente" << endl;
        cout << "Ingresa la cantidad de arbitros: ";
        cin >> cant_arbitros;
    }
    vector<vector<int>> puntajes(cant_equipos, vector<int>(cant_arbitros, 0)); // Matriz usando stl
    loader.cargar_puntajes(puntajes, 0 , 10);
    imprimir_puntajes(puntajes);
    vector<Partido> partidos;
    loader.cargar_enfrentamientos(partidos, cant_equipos);
    imprimir_partidos(partidos);
    //asignar_arbitros();
    return 0;
}
