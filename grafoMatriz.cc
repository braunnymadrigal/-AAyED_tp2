#include "grafoMatriz.hh"

Grafo::Grafo() {
	Iniciar();
}

Grafo::~Grafo() {
	Destruir();
}

void Grafo::Iniciar() {
	this->ultLleno = -1;
}

void Grafo::Destruir() {
	
}

void Grafo::Vaciar() {
	this->ultLleno = -1;
}

bool Grafo::Vacio() {
	return this->ultLleno == -1;
}

Vertice Grafo::AgregarVert(int e) {
	++this->ultLleno;
	this->vertices[ultLleno].etiqueta = e;
	
	this->LimpiarFilaYColumna(ultLleno);
	
	return vertices[ultLleno];
}

void Grafo::BorrarVert(int v) {
	for(int i = v; i < this->ultLleno; ++i){
		Vertice vAux = this->vertices[i];
		this->vertices[i] = this->vertices[i+1];
		this->vertices[i+1] = vAux;
	}
	//correr aristas
	for(int i = v; i < this->ultLleno; ++i){
		for(int j = 0; j <= ultLleno; ++j){
			int eAux = this->aristas[i][j];
			
			this->aristas[i][j] = this->aristas[i+1][j];
			this->aristas[i+1][j] = eAux;
		}
	}
	
	for(int i = v; i < this->ultLleno; ++i){
		for(int j = 0; j <= ultLleno; ++j){
			int eAux = this->aristas[i][j];
			this->aristas[i][j] = this->aristas[i][j+1];
			this->aristas[i][j+1] = eAux;
		}
	}
	
	--this->ultLleno;
}

void Grafo::ModifEtiq(int v, int e) {
	this->vertices[v].etiqueta = e;
}

int Grafo::Etiq(int v) {
	return this->vertices[v].etiqueta;
}

void Grafo::AgregarArist(int v1, int v2, int p) {
	this->aristas[v1][v2] = p;
	this->aristas[v2][v1] = p;
}

void Grafo::BorrarArist(int v1, int v2) {
	this->aristas[v1][v2] = -1;
	this->aristas[v2][v1] = -1;
}

void Grafo::ModifPeso(int v1, int v2, int p) {
	this->aristas[v1][v2] = p;
	this->aristas[v2][v1] = p;
}

int Grafo::Peso(int v1, int v2) {
	return this->aristas[v2][v1];
}

Vertice Grafo::PrimVert() {
	return this->vertices[0];
}

Vertice Grafo::SigVert(int v) {
	return this->vertices[v+1];
}

Vertice Grafo::PrimVertAdy(int v) {
	int verticeAdy = -1; 
	int i = 0;
	
	while(i <= this -> ultLleno && verticeAdy == -1) {
		if(i != v && aristas[v][i] != -1){
			verticeAdy = i;
		}
		++i;
	}
	
	return vertices[verticeAdy];
}

Vertice Grafo::SigVertAdy(int v1, int v2) {
	int verticeAdy = -1; 
	int i = v2+1;
	
	while(i <= this -> ultLleno && verticeAdy == -1) {
		if(i != v1 && aristas[v1][i] != -1){
			verticeAdy = i;
		}
		++i;
	}
	
	return vertices[verticeAdy];
}

int Grafo::NumVertices() {
	return ultLleno + 1;
}

int Grafo::getVert(int e) {
	bool seguir = true;
	int i = 0;
	
	while(seguir && i <= ultLleno) {
		if(vertices[i].etiqueta == e){
			seguir = false;
		}
		++i;
	}
	
	return i;
}

//FuncionesAuxiliares
void Grafo::LimpiarFilaYColumna(int vertice) {
	for(int i = 0; i < this->tamMax; ++i) {
		this->aristas[vertice][i] = -1;
		this->aristas[i][vertice] = -1;
	}
}









void Grafo::Imprimir() {
	for(int i = 0; i <= this->ultLleno; ++i) {
		std::cout << vertices[i].etiqueta << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for(int i = 0; i <= this->ultLleno; ++i){
		for(int j = 0; j <= this->ultLleno; ++j){
			std::cout << aristas[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Grafo::GrafoPrueba() {
	this->ultLleno = 3;
	
	vertices[0].etiqueta = 1;
	vertices[1].etiqueta = 2;
	vertices[2].etiqueta = 3;
	vertices[3].etiqueta = 4;
	
	aristas[0][0] = 0;
	aristas[0][1] = 1;
	aristas[0][2] = 2;
	aristas[0][3] = 3;
	aristas[1][0] = 4;
	aristas[1][1] = 5;
	aristas[1][2] = 6;
	aristas[1][3] = 7;
	aristas[2][0] = 8;
	aristas[2][1] = 9;
	aristas[2][2] = 10;
	aristas[2][3] = 11;
	aristas[3][0] = 12;
	aristas[3][1] = 13;
	aristas[3][2] = 14;
	aristas[3][3] = 15;
}