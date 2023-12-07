#include "algoritmos.hh"

int Algoritmos::NumAristas(Grafo *G) {
    int numAristas = 0;
    Grafo::Vert v = G->PrimVert();
    while (v != G->VertNulo) {
        Grafo::Vert va = G->PrimVertAdy(v);
        while (va != G->VertNulo) {
            ++numAristas;
            va = G->SigVertAdy(v, va);
        }
        v = G->SigVert(v);
    }
    return numAristas / 2;
}

bool Algoritmos::EsConexoProfPrim(Grafo *G) {
    int numVisitados = 0;
    std::map<Grafo::Vert, bool> DVV;
    if (!G->Vacio()) {
        Grafo::Vert v = G->PrimVert();
        EsConexoProfPrimR(G, v, DVV, numVisitados);
    }
    return numVisitados == G->NumVertices();
}

bool Algoritmos::EsConexoAnchoPrim(Grafo *G) {
    int numVisitados = 0;
    if (!G->Vacio()) {
        std::map<Grafo::Vert, bool> DVV;
        std::queue<Grafo::Vert> cola;
        Grafo::Vert v = G->PrimVert();
        cola.push(v);
        DVV[v] = true;

        while (!cola.empty()) {
            v = cola.front();
            cola.pop();
            ++numVisitados;
            Grafo::Vert va = G->PrimVertAdy(v);
            while (va != G->VertNulo) {
                if (DVV.find(va) == DVV.end()) {
                    cola.push(va);
                    DVV[va] = true;
                }
                va = G->SigVertAdy(v, va);
            }
        }
    }
    return numVisitados == G->NumVertices();
}

// privados

void Algoritmos::EsConexoProfPrimR(
    Grafo *G, Grafo::Vert v, std::map<Grafo::Vert, bool> &DVV,
    int &numVisitados) {
    DVV[v] = true;
    ++numVisitados;
    Grafo::Vert va = G->PrimVertAdy(v);
    while (va != G->VertNulo) {
        if (DVV.find(va) == DVV.end()) {
            EsConexoProfPrimR(G, va, DVV, numVisitados);
        }
        va = G->SigVertAdy(v, va);
    }
}
