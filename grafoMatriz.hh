#pragma once

#include <iostream>

class Grafo {
private:
    int vertices[1000];
    double aristas[1000][1000];
    const int tamMax = 1000;
    int ultLleno;

private:
    void Iniciar();
    void Destruir();
    void LimpiarFilaYColumna(int);

public:
    Grafo();
    ~Grafo();
    void Vaciar();
    bool Vacio();
    int AgregarVert(int);
    void BorrarVert(int);
    void ModifEtiq(int, int);
    int Etiq(int);
    void AgregarArist(int, int, double);
    void BorrarArist(int, int);
    void ModifPeso(int, int, double);
    int Peso(int, int);
    int PrimVert();
    int SigVert(int);
    int PrimVertAdy(int);
    int SigVertAdy(int, int);
    int NumVertices();

    // aux
    bool ExisteArista(int, int);
    int EtiqAVert(int e);
    void Imprimir();

public:
    using Vert = int;
    int VertNulo = -1;
};
