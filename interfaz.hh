#pragma once

#include "algGrafo.hh"

class Interfaz {
public:
    void pruebas();
    void probarOps(Grafo *&grafo);
    void probarAlg(Grafo *&grafo);
    void mostrarOperadoresGrafo();
    void mostrarAlgoritmosGrafo();
    void bienvenida();
    int getOpcion();
    void mostrarManual();
};
