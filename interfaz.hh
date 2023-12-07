#pragma once

#include "algoritmos.hh"

class Interfaz {
public:
    void pruebas();
    void probarOps(Grafo *&grafo);
    void probarAlg(Grafo *&grafo);
    void mostrarOperadores();
    void mostrarAlgoritmos();
    void bienvenida();
    int getOpcion();
    void mostrarManual();
};
