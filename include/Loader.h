#ifndef LOADER_H
#define LOADER_H

#include <iostream>
#include <vector>

using namespace std;

// clase encargada de cargar los datos del problema
class Loader
{
    public:
        Loader();
        virtual ~Loader();
        void cargar_puntajes(vector<vector<int>> & puntajes, int puntaje_min, int puntaje_max);


    protected:

    private:
};

#endif // LOADER_H
