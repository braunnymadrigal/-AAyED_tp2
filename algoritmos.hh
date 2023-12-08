#pragma once

#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#include "grafoMatriz.hh"
//#include "grafoLista.hh"

class Algoritmos {
public:
    int NumAristas(Grafo *G);
    bool EsConexoProfPrim(Grafo *G);
    bool EsConexoAnchoPrim(Grafo *G);
	void Dijkstra(Grafo *G, Grafo::Vert vSalida);
	void Floyd(Grafo* G);
	void Prim(Grafo* G);
	void Kruskal(Grafo *G);
	

private:
    void EsConexoProfPrimR(
        Grafo *G, Grafo::Vert v, std::map<Grafo::Vert, bool> &DVV,
        int &numVisitados);
		
	int BuscarPivote(double* ,bool* , int);
	int getPreImagen(const std::map<int, Grafo::Vert>& R11, Grafo::Vert pivote);
	
};
