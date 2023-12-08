#include "interfaz.hh"
#include "pruebas.hh"

int main() {
    
    Interfaz interfaz = Interfaz();
    interfaz.pruebas();
    return 0;
    
	/*
    Pruebas pruebas;
    pruebas.Ejecutar();
    return 0;*/

    /*
    Grafo *grafo = new Grafo;
    std::vector<Grafo::Vert> *verts = new std::vector<Grafo::Vert>;
    int start = 0;
    int end = 10;
    Pruebas pruebas;
    pruebas.CrearGrafoSemiConexo(grafo, verts, 1000);

    grafo->Imprimir();
    for(int i = 0; i < verts->size(); ++i) {
        std::cout << grafo->Etiq((*verts)[i]) << " ";
    }
    std::cout << std::endl;
    delete grafo;

    return 0;
    */
}
