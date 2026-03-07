//
// Created by Carlos Lara on 8/6/2024.
//

#include "problemaJarras.h"

problemaJarras::problemaJarras(nodo inicial, nodo meta) : inicial(inicial), meta(meta) {
    cout << "Nodo inicial ";
    inicial.imprimir();
    cout << '\n';
    cout << "Nodo meta: ";
    meta.imprimir();
    cout << '\n';

}

bool problemaJarras::existe(nodo x, list<nodo> y) {
    list<nodo>::iterator it;
    for (it = y.begin(); it != y.end(); ++it) {
        if (x.j4 == it->j4 && x.j3 == it->j3) {
            return true;
        }
    }
    return false;
}

void problemaJarras::bfs() {
    list<nodo> lista;
    list<nodo> historial;
    list<nodo>::iterator it;
    int iteracion = 1;
    bool encontrado_meta = false;
    lista.push_back(inicial);
    historial.push_back(inicial);
    while(!lista.empty() && !encontrado_meta) {
        cout << "L(" << iteracion << ") ";
        for (it = lista.begin();  it != lista.end(); it++) {
            it->imprimir();
        }
        cout << '\n';
        nodo aux = lista.front();
        if (meta.j4 == aux.j4 && meta.j3 == aux.j3) {
            encontrado_meta = true;
        } else {
            lista.pop_front();
            nodo hijo;
            hijo = aux.pasar3a4();
            if (!(existe(hijo, historial))) {
                lista.push_back(hijo);
                historial.push_back(hijo);
            }
            hijo = aux.pasar4a3();
            if (!(existe(hijo, historial))) {
                lista.push_back(hijo);
                historial.push_back(hijo);
            }
            hijo = aux.vaciar3();
            if (!(existe(hijo, historial))) {
                lista.push_back(hijo);
                historial.push_back(hijo);
            }
            hijo = aux.vaciar4();
            if (!(existe(hijo, historial))) {
                lista.push_back(hijo);
                historial.push_back(hijo);
            }
            hijo = aux.llenar3();
            if (!(existe(hijo, historial))) {
                lista.push_back(hijo);
                historial.push_back(hijo);
            }
            hijo = aux.llenar4();
            if (!(existe(hijo, historial))) {
                lista.push_back(hijo);
                historial.push_back(hijo);
            }
        }
        iteracion++;
    }
    if (encontrado_meta) {
        cout << "Meta encontrada.\n";
        nodo aux = lista.front();
        for (auto movimiento: aux.movimientos) {
            if (movimiento == 1) {
                cout << "Llenar la jarra de 4.\n";
            } else if (movimiento == 2) {
                cout << "Llenar la jarra de 3.\n";
            } else if (movimiento == 3) {
                cout << "Vaciar la jarra de 4.\n";
            } else if (movimiento == 4) {
                cout << "Vaciar la jarra de 3.\n";
            } else if (movimiento == 5) {
                cout << "Pasar de 4 a 3. \n";
            } else if (movimiento == 6) {
                cout << "Pasar de 3 a 4. \n";
            }
        }
    } else {
        cout << "No se encontro la meta\n";
    }
}

void problemaJarras::dfs() {
    list<nodo> lista;
    list<nodo> historial;
    list<nodo>::iterator it;
    int iteracion = 1;
    bool encontrado_meta = false;
    lista.push_front(inicial);
    historial.push_front(inicial);
    while(!lista.empty() && !encontrado_meta) {
        cout << "L(" << iteracion << ") ";
        for (it = lista.begin();  it != lista.end(); it++) {
            it->imprimir();
        }
        cout << '\n';
        nodo aux = lista.front();
        if (meta.j4 == aux.j4 && meta.j3 == aux.j3) {
            encontrado_meta = true;
        } else {
            lista.pop_front();
            nodo hijo;
            hijo = aux.pasar3a4();
            if (!(existe(hijo, historial))) {
                lista.push_front(hijo);
                historial.push_front(hijo);
            }
            hijo = aux.pasar4a3();
            if (!(existe(hijo, historial))) {
                lista.push_front(hijo);
                historial.push_front(hijo);
            }
            hijo = aux.vaciar3();
            if (!(existe(hijo, historial))) {
                lista.push_front(hijo);
                historial.push_front(hijo);
            }
            hijo = aux.vaciar4();
            if (!(existe(hijo, historial))) {
                lista.push_front(hijo);
                historial.push_front(hijo);
            }
            hijo = aux.llenar3();
            if (!(existe(hijo, historial))) {
                lista.push_front(hijo);
                historial.push_front(hijo);
            }
            hijo = aux.llenar4();
            if (!(existe(hijo, historial))) {
                lista.push_front(hijo);
                historial.push_front(hijo);
            }


        }
        iteracion++;
    }
    if (encontrado_meta) {
        cout << "Meta encontrada.\n";
        nodo aux = lista.front();
        for (auto movimiento: aux.movimientos) {
            if (movimiento == 1) {
                cout << "Llenar la jarra de 4.\n";
            } else if (movimiento == 2) {
                cout << "Llenar la jarra de 3.\n";
            } else if (movimiento == 3) {
                cout << "Vaciar la jarra de 4.\n";
            } else if (movimiento == 4) {
                cout << "Vaciar la jarra de 3.\n";
            } else if (movimiento == 5) {
                cout << "Pasar de 4 a 3. \n";
            } else if (movimiento == 6) {
                cout << "Pasar de 3 a 4. \n";
            }
        }
    } else {
        cout << "No se encontro la meta\n";
    }
}
