//
// Created by Carlos Lara on 8/6/2024.
//

#ifndef JUEGOJARRAS_NODO_H
#define JUEGOJARRAS_NODO_H

#include <bits/stdc++.h>

// Namespaces
using namespace std;

class nodo {
private:
    int j4, j3;
    list<int> movimientos;
public:
    nodo();
    nodo(int j4, int j3);
    void imprimir();
    nodo llenar4();
    nodo llenar3();
    nodo vaciar4();
    nodo vaciar3();
    nodo pasar4a3();
    nodo pasar3a4();

    friend class problemaJarras;
};
#endif //JUEGOJARRAS_NODO_H
