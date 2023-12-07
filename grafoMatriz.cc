#include "grafoMatriz.hh"

Grafo::Grafo() { Iniciar(); }

Grafo::~Grafo() { Destruir(); }

void Grafo::Iniciar() { this->ultLleno = -1; }

void Grafo::Destruir() {}

void Grafo::Vaciar() { this->ultLleno = -1; }

bool Grafo::Vacio() { return this->ultLleno == -1; }

int Grafo::AgregarVert(int e) {
    ++this->ultLleno;
    this->vertices[ultLleno] = e;
    this->LimpiarFilaYColumna(ultLleno);

    return ultLleno;
}

void Grafo::BorrarVert(int v) {
    for (int i = v; i < this->ultLleno; ++i) {
        int vAux = this->vertices[i];
        this->vertices[i] = this->vertices[i + 1];
        this->vertices[i + 1] = vAux;
    }
    // correr aristas
    for (int i = v; i < this->ultLleno; ++i) {
        for (int j = 0; j <= ultLleno; ++j) {
            int eAux = this->aristas[i][j];

            this->aristas[i][j] = this->aristas[i + 1][j];
            this->aristas[i + 1][j] = eAux;
        }
    }

    for (int i = v; i < this->ultLleno; ++i) {
        for (int j = 0; j <= ultLleno; ++j) {
            int eAux = this->aristas[i][j];
            this->aristas[i][j] = this->aristas[i][j + 1];
            this->aristas[i][j + 1] = eAux;
        }
    }

    --this->ultLleno;
}

void Grafo::ModifEtiq(int v, int e) { this->vertices[v] = e; }

int Grafo::Etiq(int v) { return this->vertices[v]; }

void Grafo::AgregarArist(int v1, int v2, double p) {
    this->aristas[v1][v2] = p;
    this->aristas[v2][v1] = p;
}

void Grafo::BorrarArist(int v1, int v2) {
    this->aristas[v1][v2] = -1;
    this->aristas[v2][v1] = -1;
}

void Grafo::ModifPeso(int v1, int v2, double p) {
    this->aristas[v1][v2] = p;
    this->aristas[v2][v1] = p;
}

int Grafo::Peso(int v1, int v2) { return this->aristas[v2][v1]; }

int Grafo::PrimVert() { return 0; }

int Grafo::SigVert(int v) { return v + 1; }

int Grafo::PrimVertAdy(int v) {
    int verticeAdy = -1;
    int i = 0;

    while (i <= this->ultLleno && verticeAdy == -1) {
        if (i != v && aristas[v][i] != -1) {
            verticeAdy = i;
        }
        ++i;
    }

    return verticeAdy;
}

int Grafo::SigVertAdy(int v1, int v2) {
    int verticeAdy = -1;
    int i = v2 + 1;

    while (i <= this->ultLleno && verticeAdy == -1) {
        if (i != v1 && aristas[v1][i] != -1) {
            verticeAdy = i;
        }
        ++i;
    }

    return verticeAdy;
}

int Grafo::NumVertices() { return ultLleno + 1; }

int Grafo::EtiqAVert(int e) {
    bool seguir = true;
    int i = 0;

    while (seguir && i <= ultLleno) {
        if (vertices[i] == e) {
            seguir = false;
        }
        ++i;
    }

    return i;
}

// FuncionesAuxiliares
void Grafo::LimpiarFilaYColumna(int vertice) {
    for (int i = 0; i < this->tamMax; ++i) {
        this->aristas[vertice][i] = -1;
        this->aristas[i][vertice] = -1;
    }
}

void Grafo::Imprimir() {
    for (int i = 0; i <= this->ultLleno; ++i) {
        std::cout << vertices[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for (int i = 0; i <= this->ultLleno; ++i) {
        for (int j = 0; j <= this->ultLleno; ++j) {
            std::cout << aristas[j][i] << " ";
        }
        std::cout << std::endl;
    }
}
