#include "algoritmos.hh"

class Pruebas {
public:
    void Ejecutar();
    void CrearGrafoInConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int n);
    void CrearGrafoFullConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int n);
    void CrearGrafoSemiConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int n);
    void TestEsConexoProfPrim(Grafo *G);
    void TestEsConexoAnchoPrim(Grafo *G);
    void TestDijkstra(Grafo *G, std::vector<Grafo::Vert> *vecVerts);
    void TestFloyd(Grafo *G);
    void TestPrim(Grafo *G);
    void TestKruskal(Grafo *G);
    void TestHamiltonBEP(Grafo *G);
};
