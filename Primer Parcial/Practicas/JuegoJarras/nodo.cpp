// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

#include "nodo.h"

nodo::nodo() : j4(0), j3(0) {}

nodo::nodo(int j4, int j3) : j4(j4), j3(j3) {}

nodo nodo::llenar4() {
    nodo x(4, this->j3);
    x.movimientos = this->movimientos;
    x.movimientos.push_back(1);
    return x;
}

nodo nodo::llenar3() {
    nodo x(this->j4, 3);
    x.movimientos = this->movimientos;
    x.movimientos.push_back(2);
    return x;
}

nodo nodo::vaciar4() {
    nodo x(0, this->j3);
    x.movimientos = this->movimientos;
    x.movimientos.push_back(3);
    return x;
}

nodo nodo::vaciar3() {
    nodo x(this->j4, 0);
    x.movimientos = this->movimientos;
    x.movimientos.push_back(4);
    return x;
}

nodo nodo::pasar4a3() {
    nodo x(this->j4, this->j3);
    while(x.j4 > 0 && x.j3 < 3) {
        x.j4--;
        x.j3++;
    }
    x.movimientos = this->movimientos;
    x.movimientos.push_back(5);
    return x;
}

nodo nodo::pasar3a4() {
    nodo x(this->j4, this->j3);
    while(x.j3 > 0 && x.j4 < 4) {
        x.j3--;
        x.j4++;
    }
    x.movimientos = this->movimientos;
    x.movimientos.push_back(6);
    return x;
}

void nodo::imprimir() {
    cout << '(' << j4 << ',' << j3 << ')';
}
