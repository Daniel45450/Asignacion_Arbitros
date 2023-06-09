#ifndef LOADER_H
#define LOADER_H

#include <iostream>
#include <vector>
#include "Partido.h"

using namespace std;

// clase encargada de cargar los datos del problema
class Loader
{
    public:
        Loader();
        virtual ~Loader();
        void cargar_puntajes(vector<vector<int>> & puntajes, int puntaje_min, int puntaje_max);
        void cargar_enfrentamientos(vector<Partido> & partidos, int cant_equipos);


    protected:

    private:
};

#endif // LOADER_H
