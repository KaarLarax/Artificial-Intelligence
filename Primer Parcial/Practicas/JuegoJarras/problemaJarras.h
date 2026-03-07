//
// Created by Carlos Lara on 8/6/2024.
//

#ifndef JUEGOJARRAS_PROBLEMAJARRAS_H
#define JUEGOJARRAS_PROBLEMAJARRAS_H


#include "nodo.h"

class problemaJarras {
private:
    nodo inicial;
    nodo meta;
public:
    problemaJarras(nodo inicial, nodo meta);
    bool existe(nodo x, list<nodo> y);
    void bfs();
    void dfs();
};


#endif //JUEGOJARRAS_PROBLEMAJARRAS_H
