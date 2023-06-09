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

void Loader::cargar_enfrentamientos(vector<Partido> & partidos, int cant_equipos)
{
    vector<bool> agregado(cant_equipos, false);
    int cant_partidos = cant_equipos/2;
    char opcion;
    cout << "\nCargar enfrentamientos de forma aleatoria? (y/n) ";
    cin >> opcion;
    int i=0;
    srand(time(nullptr));
    if(toupper(opcion) == 'Y')
    {
        while(i<cant_partidos) {
            int a = rand() % cant_equipos;
            int b = rand() % cant_equipos;
            if(!agregado[a] && !agregado[b] && a != b) {
                    agregado[a] = true;
                    agregado[b] = true;
                    Partido p(a,b);
                    partidos.push_back(p);
                    i++;
            }
        }
    }
    else {
            int a;
            int b;
            while(i<cant_partidos) {
                cout << "\nAgregar nuevo enfrentamiento\n" << endl;
                cout << "Ingresa el primer equipo: ";
                cin >> a;
                cout << "Ingresa el segundo equipo: ";
                cin >> b;
                if(!agregado[a] && !agregado[b] && a != b) {
                        Partido p(a,b);
                        partidos.push_back(p);
                        i++;
                        agregado[a] = true;
                        agregado[b] = true;
                }
                else {
                    cout << "Estos equipos ya tienen un enfrentamiento asignado, ingresa un enfrentamiento nuevo" << endl;
                }
            }
        }
}
