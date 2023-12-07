#include "pruebas.hh"

void Pruebas::Ejecutar() {
    // CAMBIAR ESTE TAMAñO
    int tamano = 1000;
    // CAMBIAR ESTE TAMAñO

    Grafo *grafo = new Grafo;
    std::vector<Grafo::Vert> *verts = new std::vector<Grafo::Vert>;
    CrearGrafoInConexo(grafo, verts, tamano);
    std::cout << std::endl << std::endl;
    std::cout << "InConexo" << std::endl;
    TestEsConexoProfPrim(grafo);
    TestEsConexoAnchoPrim(grafo);
    TestDijkstra(grafo, verts);
    TestFloyd(grafo);
    TestPrim(grafo);
    TestKruskal(grafo);
    TestHamiltonBEP(grafo);
    delete grafo;
    delete verts;
    grafo = new Grafo;
    verts = new std::vector<Grafo::Vert>;
    CrearGrafoSemiConexo(grafo, verts, tamano);
    std::cout << std::endl << std::endl;
    std::cout << "SemiConexo" << std::endl;
    TestEsConexoProfPrim(grafo);
    TestEsConexoAnchoPrim(grafo);
    TestDijkstra(grafo, verts);
    TestFloyd(grafo);
    TestPrim(grafo);
    TestKruskal(grafo);
    TestHamiltonBEP(grafo);
    delete grafo;
    delete verts;
    grafo = new Grafo;
    verts = new std::vector<Grafo::Vert>;
    CrearGrafoFullConexo(grafo, verts, tamano);
    std::cout << std::endl << std::endl;
    std::cout << "FullConexo" << std::endl;
    TestEsConexoProfPrim(grafo);
    TestEsConexoAnchoPrim(grafo);
    TestDijkstra(grafo, verts);
    TestFloyd(grafo);
    TestPrim(grafo);
    TestKruskal(grafo);
    TestHamiltonBEP(grafo);
    delete grafo;
    delete verts;

    std::cout << std::endl << std::endl;
}

void Pruebas::CrearGrafoInConexo(
    Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int n) {
    for (int i = 0; i < n; ++i) {
        vecVerts->push_back(G->AgregarVert(i));
    }
}

void Pruebas::CrearGrafoFullConexo(
    Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int n) {
    for (int i = 0; i < n; ++i) {
        vecVerts->push_back(G->AgregarVert(i));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            G->AgregarArist(
                (*vecVerts)[i], (*vecVerts)[j], (0.3 * i + 0.5 * j));
        }
    }
}

void Pruebas::CrearGrafoSemiConexo(
    Grafo *&G, std::vector<Grafo::Vert> *&vecVerts, int n) {
    for (int i = 0; i < n; ++i) {
        vecVerts->push_back(G->AgregarVert(i));
    }

    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0) {
            for (int j = i + 1; j < n; ++j) {
                G->AgregarArist(
                    (*vecVerts)[i], (*vecVerts)[j], (0.3 * i + 0.5 * j));
            }
        }
    }
}

void Pruebas::TestEsConexoProfPrim(Grafo *G) {
    Algoritmos alg;
    auto start = std::chrono::high_resolution_clock::now();
    alg.EsConexoProfPrim(G);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    int64_t durationInNanoseconds = duration.count();
    std::cout << "\tConexoProf: " << std::left << std::setw(10)
              << durationInNanoseconds << std::endl;
}

void Pruebas::TestEsConexoAnchoPrim(Grafo *G) {
    Algoritmos alg;
    auto start = std::chrono::high_resolution_clock::now();
    alg.EsConexoAnchoPrim(G);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    int64_t durationInNanoseconds = duration.count();
    std::cout << "\tConexoAncho: " << std::left << std::setw(10)
              << durationInNanoseconds << std::endl;
}

void Pruebas::TestDijkstra(Grafo *G, std::vector<Grafo::Vert> *vecVerts) {}

void Pruebas::TestFloyd(Grafo *G) {}

void Pruebas::TestPrim(Grafo *G) {}

void Pruebas::TestKruskal(Grafo *G) {}

void Pruebas::TestHamiltonBEP(Grafo *G) {}

