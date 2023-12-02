#pragma once

#include <iostream>

struct Vertice{
	int etiqueta;
};

class Grafo{
	private:
		Vertice vertices[20];
		int aristas[20][20];
		const int tamMax = 20; 
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
		Vertice AgregarVert(int);
		void BorrarVert(int);
		void ModifEtiq(int, int);
		int Etiq(int);
		void AgregarArist(int, int, int);
		void BorrarArist(int, int);
		void ModifPeso(int, int, int);
		int Peso(int, int);
		Vertice PrimVert();
		Vertice SigVert(int);
		Vertice PrimVertAdy(int);
		Vertice SigVertAdy(int, int);
		int NumVertices();
		
		int getVert(int e);
		
		
		void GrafoPrueba();
		void Imprimir();
	
	public:
		using Vert = int;
};