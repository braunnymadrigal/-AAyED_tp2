#include "pruebas.hh"

void Pruebas::Ejecutar() {
/*
   Grafo *grafo = new Grafo;
   std::vector<Grafo::Vert> *verts = new std::vector<Grafo::Vert>;
   int start = 0;
   int end = 10;
   for(int i = 0; i < 4; ++i) {
   		AumentarGrafoInConexo(grafo, verts, start, end);
   		start = end;
   		end *= 10;
   }*/
}


void Pruebas::AumentarGrafoInConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int start, int end) {
	while(start < end) {
		vecVerts->push_back(G->AgregarVert(start));
		++start;
	}
}

void Pruebas::AumentarGrafoFullConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int start, int end) {
	int startFijo = start;
	while(start < end) {
		vecVerts->push_back(G->AgregarVert(start));
		++start;
	}
	start = startFijo;
}
