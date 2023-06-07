#ifndef IMPRIMIR_INFO_H_INCLUDED
#define IMPRIMIR_INFO_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

void imprimir_puntajes(vector<vector<int>> puntajes)
{
    cout << "\nTabla de Puntajes" << endl;
    for(int i=0; i<puntajes.size(); i++) {
        cout << "\nEquipo " << i+1 << ":\n" << endl;
        for(int j=0; j< puntajes[0].size(); j++) {
            cout << "Arbitro " << j+1  << ": " << puntajes[i][j]<< endl;
        }
    }
}

#endif // IMPRIMIR_INFO_H_INCLUDED
