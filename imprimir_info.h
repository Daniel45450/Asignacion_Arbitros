#ifndef IMPRIMIR_INFO_H_INCLUDED
#define IMPRIMIR_INFO_H_INCLUDED

#include <iostream>
#include <vector>
#include "Partido.h"

using namespace std;

ostream & operator << (ostream & salida, const Partido & partido);
void imprimir_puntajes(const vector<vector<int>> & puntajes);
void imprimir_partidos(const vector<Partido> & partidos);

void imprimir_puntajes(const vector<vector<int>> & puntajes)
{
    cout << "\nTabla de Puntajes" << endl;
    for(int i=0; i<puntajes.size(); i++) {
        cout << "\nEquipo " << i+1 << ":\n" << endl;
        for(int j=0; j< puntajes[0].size(); j++) {
            cout << "Arbitro " << j+1  << ": " << puntajes[i][j]<< endl;
        }
    }
}

void imprimir_partidos(const vector<Partido> & partidos)
{
    cout << "----- Listado de enfrentamiento -----"<< endl;
    typename vector<Partido>::const_iterator it_p = partidos.begin();
    while(it_p != partidos.end()) {
        cout << *it_p << endl;
        it_p++;
    }
}

ostream & operator << (ostream & salida, const Partido & partido)
{
    salida << "    " << partido.obtener_primer_equipo() << " vs " << partido.obtener_segundo_equipo() << "\n";
	return salida;
}

#endif // IMPRIMIR_INFO_H_INCLUDED
