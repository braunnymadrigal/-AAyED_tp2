#pragma once

#include <iostream>
#include <limits>
#include <map>
#include <utility>
#include <vector>
#include <queue>

//#include "grafoMatriz.hh"
#include "grafoLista.hh"

class Algoritmos {
public:
    int NumAristas(Grafo *G);
    bool EsConexoProfPrim(Grafo *G);
	bool EsConexoAnchoPrim(Grafo *G);
private:
    void EsConexoProfPrimR(
        Grafo *G, Grafo::Vert v, std::map<Grafo::Vert, bool> &DVV,
        int &numVisitados);
};
