#pragma once

#include <iostream>

struct SubLista;

struct Vertice {
  int etiqueta;
  Vertice *abajo;
  SubLista *sublista;
};

struct SubLista {
  double peso;
  SubLista *siguiente;
  Vertice *vertice;
};

class Grafo {
public:
  // type alias
  using Vert = Vertice *;
  Vertice *VertNulo = nullptr;

public:
  Grafo();
  ~Grafo();
  void Vaciar();
  bool Vacio();
  Vertice *AgregarVert(int e);
  void BorrarVert(Vertice *v);
  void ModifEtiq(Vertice *v, int e);
  int Etiq(Vertice *v);
  void AgregarArist(Vertice *v1, Vertice *v2, double p);
  void BorrarArist(Vertice *v1, Vertice *v2);
  void ModifPeso(Vertice *v1, Vertice *v2, double p);
  double Peso(Vertice *v1, Vertice *v2);
  Vertice *PrimVert();
  Vertice *SigVert(Vertice *v);
  Vertice *PrimVertAdy(Vertice *v);
  Vertice *SigVertAdy(Vertice *v1, Vertice *v2);
  int NumVertices();
  // aux
  Vertice *EtiqAVert(int e);
  void ImprimirListas();

private:
  void Iniciar();
  void Destruir();
  void AgregarAristPriv(Vertice *v1, Vertice *v2, double p);
  void BorrarAristPriv(Vertice *v1, Vertice *v2);
  void ModifPesoPriv(Vertice *v1, Vertice *v2, double p);

private:
  Vertice *primero;
};
