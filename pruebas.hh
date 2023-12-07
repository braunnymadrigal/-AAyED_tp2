#include "algoritmos.hh"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <random>

class Pruebas {
public:
    void Ejecutar();
    void AumentarGrafoInConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int start, int end);
    void AumentarGrafoFullConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int start, int end);
    void AumentarGrafoSemiConexo(Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int start, int end);
};
