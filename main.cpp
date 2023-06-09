#include <iostream>
#include "Partido.h"
#include "Loader.h"
#include "imprimir_info.h"
#include <set>

using namespace std;

void asignar_arbitros(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & solucion);
void asignar_arbitros_poda(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & solucion);

void backtracking(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & asignacion_actual, vector<int> & mejor_asignacion, int & mejor_puntuacion, int & puntuacion_actual, set<int> & asignados, int & medida);
void backtracking_poda(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & asignacion_actual, vector<int> & mejor_asignacion, int & mejor_puntuacion, int & puntuacion_actual, set<int> & asignados, int & medida);

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
    vector<int> solucion;
    asignar_arbitros(cant_partidos, cant_arbitros, partidos, puntajes, solucion);
    imprimir_asignacion(solucion);
    solucion.clear();
    asignar_arbitros_poda(cant_partidos, cant_arbitros, partidos, puntajes, solucion);
    imprimir_asignacion(solucion);

    return 0;
}

void asignar_arbitros(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & solucion)
{
    set<int> asignados;
    int mejor_puntuacion=0;
    int puntuacion_actual=0;
    vector<int> asignacion_actual(cant_partidos, -1);
    vector<int> mejor_asignacion;
    int medida=0;

    backtracking(cant_partidos, cant_arbitros, partidos, puntajes, asignacion_actual, mejor_asignacion, mejor_puntuacion, puntuacion_actual, asignados, medida);
    solucion = mejor_asignacion;
    cout << "\nSin poda se ejecuto: " << medida<< " veces" << endl;
}

void asignar_arbitros_poda(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & solucion)
{
    set<int> asignados;
    int mejor_puntuacion=0;
    int puntuacion_actual=0;
    vector<int> asignacion_actual(cant_partidos, -1);
    vector<int> mejor_asignacion;
    int medida=0;

    backtracking_poda(cant_partidos, cant_arbitros, partidos, puntajes, asignacion_actual, mejor_asignacion, mejor_puntuacion, puntuacion_actual, asignados, medida);
    solucion = mejor_asignacion;
    cout << "\nCon poda se ejecuto: " << medida<< " veces" << endl;
}

void backtracking(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & asignacion_actual, vector<int> & mejor_asignacion, int & mejor_puntuacion, int & puntuacion_actual, set<int> & asignados, int & medida)
{
    medida++;
    if (asignados.size() == cant_partidos) {
        if (puntuacion_actual > mejor_puntuacion) {
            mejor_puntuacion = puntuacion_actual;
            mejor_asignacion = asignacion_actual;
        }
        return;
    }

    for (int j = 0; j < cant_arbitros; j++) {
        if (asignados.find(j) == asignados.end()) {
            asignados.insert(j);
            for (int i = 0; i < cant_partidos; i++) {
                if (asignacion_actual[i] == -1) {
                    int equipo1 = partidos[i].obtener_primer_equipo();
                    int equipo2 = partidos[i].obtener_segundo_equipo();
                    puntuacion_actual += puntajes[equipo1][j] + puntajes[equipo2][j];
                    asignacion_actual[i] = j;
                    backtracking(cant_partidos, cant_arbitros, partidos, puntajes, asignacion_actual, mejor_asignacion, mejor_puntuacion, puntuacion_actual, asignados, medida);
                    asignacion_actual[i] = -1;
                    puntuacion_actual -= (puntajes[equipo1][j] + puntajes[equipo2][j]);
                }
            }
            asignados.erase(j);
        }
    }
}


void backtracking_poda(int cant_partidos, int cant_arbitros, const vector<Partido> & partidos, const vector<vector<int>> & puntajes, vector<int> & asignacion_actual, vector<int> & mejor_asignacion, int & mejor_puntuacion, int & puntuacion_actual, set<int> & asignados, int & medida)
{
    medida++;
    if (asignados.size() == cant_partidos) {
        if (puntuacion_actual > mejor_puntuacion) {
            mejor_puntuacion = puntuacion_actual;
            mejor_asignacion = asignacion_actual;
        }
        return;
    }

    //cota: si es posible superar mi mejor puntuacion suponiendo que los demas arbitros tengan la mayor puntuacion posible
    int puntuacion_maxima_posible = (cant_partidos - asignados.size()) * 20; // podria pasar el rango por parametro en ves de poner 20 pero no quiero agregar mas cosas
    int cota = puntuacion_actual + puntuacion_maxima_posible;

    if (cota <= mejor_puntuacion) { // podo: corto asi no entra al for
        return;
    }

    for (int j = 0; j < cant_arbitros; j++) {
        if (asignados.find(j) == asignados.end()) {
            asignados.insert(j);
            for (int i = 0; i < cant_partidos; i++) {
                if (asignacion_actual[i] == -1) {
                    int equipo1 = partidos[i].obtener_primer_equipo();
                    int equipo2 = partidos[i].obtener_segundo_equipo();
                    puntuacion_actual += puntajes[equipo1][j] + puntajes[equipo2][j];
                    asignacion_actual[i] = j;
                    backtracking_poda(cant_partidos, cant_arbitros, partidos, puntajes, asignacion_actual, mejor_asignacion, mejor_puntuacion, puntuacion_actual, asignados, medida);
                    asignacion_actual[i] = -1;
                    puntuacion_actual -= (puntajes[equipo1][j] + puntajes[equipo2][j]);
                }
            }
            asignados.erase(j);
        }
    }
}


