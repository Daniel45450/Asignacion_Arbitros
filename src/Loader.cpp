#include "Loader.h"
#include <ctime>

Loader::Loader()
{
    //ctor
}

Loader::~Loader()
{
    //dtor
}

void Loader::cargar_puntajes(vector<vector<int>> & puntajes, int puntaje_min, int puntaje_max)
{
    char opcion;
    cout << "Cargar puntajes aleatoriamente?: (y/n)" << endl;
    cin >> opcion;
    srand(time(nullptr));
    for(int i=0; i<puntajes.size(); i++) {
        if(toupper(opcion) == 'N') {
         cout << "/nEquipo " << i+1 << ":" << endl;
        }
        for(int j=0; j< puntajes[0].size(); j++) {
            if(toupper(opcion) == 'Y') {
                puntajes[i][j] = puntaje_min + (rand() % (puntaje_max - puntaje_min + 1));
            } else
            {
                int puntaje;
                cout << "Puntaje para el arbitro " << j+1 << ": ";
                cin >> puntaje;
                while(puntaje < puntaje_min || puntaje > puntaje_max) {
                    cout << "El puntaje no esta dentro del rango permitido [" << puntaje_min<< "..."<<puntaje_max <<"] ingresalo nuevamente: ";
                    cin >> puntaje;
                }
                puntajes[i][j] = puntaje;
            }
        }
    }
}
