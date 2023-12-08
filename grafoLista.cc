#include "grafoLista.hh"

Grafo::Grafo() { Iniciar(); }

Grafo::~Grafo() { Destruir(); }

void Grafo::Vaciar() { Destruir(); }

bool Grafo::Vacio() { return primero == nullptr; }

Vertice *Grafo::AgregarVert(int e) {
    Vertice *v = new Vertice;
    v->etiqueta = e;
    v->abajo = primero;
    v->sublista = nullptr;
    primero = v;

    return v;
}

void Grafo::BorrarVert(Vertice *v) {
    if (primero == v) {
        Vertice *primAux = primero;
        primero = primero->abajo;
        delete primAux;
    } else {
        Vertice *anterior = primero;
        Vertice *actual = primero->abajo;
        while (actual != v) {
            anterior = actual;
            actual = actual->abajo;
        }
        anterior->abajo = actual->abajo;
        delete actual;
    }
}

void Grafo::ModifEtiq(Vertice *v, int e) { v->etiqueta = e; }

int Grafo::Etiq(Vertice *v) { return v->etiqueta; }

void Grafo::AgregarArist(Vertice *v1, Vertice *v2, double p) {
    AgregarAristPriv(v1, v2, p);
    AgregarAristPriv(v2, v1, p);
}

void Grafo::BorrarArist(Vertice *v1, Vertice *v2) {
    BorrarAristPriv(v1, v2);
    BorrarAristPriv(v2, v1);
}

void Grafo::ModifPeso(Vertice *v1, Vertice *v2, double p) {
    ModifPesoPriv(v1, v2, p);
    ModifPesoPriv(v2, v1, p);
}

double Grafo::Peso(Vertice *v1, Vertice *v2) {
    SubLista *iterador = v1->sublista;
    while (iterador->vertice != v2) {
        iterador = iterador->siguiente;
    }
    return iterador->peso;
}

Vertice *Grafo::PrimVert() { return primero; }

Vertice *Grafo::SigVert(Vertice *v) { return v->abajo; }

Vertice *Grafo::PrimVertAdy(Vertice *v) {
    Vertice *vertDevolver = nullptr;
    if (v->sublista != nullptr) {
        vertDevolver = v->sublista->vertice;
    }
    return vertDevolver;
}

Vertice *Grafo::SigVertAdy(Vertice *v1, Vertice *v2) {
    Vertice *vertADevolver = nullptr;
    SubLista *iterador = v1->sublista;
    while (iterador != nullptr) {
        if (iterador->vertice == v2) {
            iterador = iterador->siguiente;
            if (iterador != nullptr) {
                vertADevolver = iterador->vertice;
            }
            iterador = nullptr;
        } else {
            iterador = iterador->siguiente;
        }
    }
    return vertADevolver;
}

int Grafo::NumVertices() {
    int numero = 0;
    Vertice *iterador = primero;
    while (iterador != nullptr) {
        ++numero;
        iterador = iterador->abajo;
    }
    return numero;
}

// aux
Vertice *Grafo::EtiqAVert(int e) {
    Vertice *iterador = primero;
    bool devuelto = false;
    while (iterador != nullptr && !devuelto) {
        if (iterador->etiqueta == e) {
            devuelto = true;
        } else {
            iterador = iterador->abajo;
        }
    }
    return iterador;
}

void Grafo::Imprimir() {
    Vertice *iteradorVert = primero;
    while (iteradorVert != nullptr) {
        std::cout << iteradorVert->etiqueta << ":";
        SubLista *iteradorSub = iteradorVert->sublista;
        while (iteradorSub != nullptr) {
            std::cout << "\t" << (iteradorSub->vertice)->etiqueta << ","
                      << iteradorSub->peso;
            iteradorSub = iteradorSub->siguiente;
        }
        std::cout << std::endl;
        iteradorVert = iteradorVert->abajo;
    }
}

void Grafo::Iniciar() { primero = nullptr; }

void Grafo::Destruir() {
    while (primero != nullptr) {
        Vertice *primAux = primero;
        SubLista *subL = primAux->sublista;
        while (subL != nullptr) {
            SubLista *subLAux = subL;
            subL = subL->siguiente;
            delete subLAux;
        }
        primero = primero->abajo;
        delete primAux;
    }
    primero = nullptr;
}

void Grafo::AgregarAristPriv(Vertice *v1, Vertice *v2, double p) {
    SubLista *subL = new SubLista;
    subL->peso = p;
    subL->siguiente = v1->sublista;
    subL->vertice = v2;
    v1->sublista = subL;
}

void Grafo::BorrarAristPriv(Vertice *v1, Vertice *v2) {
    if ((v1->sublista)->vertice == v2) {
        SubLista *aux = v1->sublista;
        v1->sublista = (v1->sublista)->siguiente;
        delete aux;
    } else {
        SubLista *anterior = v1->sublista;
        SubLista *actual = anterior->siguiente;
        while (actual->vertice != v2) {
            anterior = actual;
            actual = actual->siguiente;
        }
        anterior->siguiente = actual->siguiente;
        delete actual;
    }
}

void Grafo::ModifPesoPriv(Vertice *v1, Vertice *v2, double p) {
    SubLista *iterador = v1->sublista;
    while (iterador->vertice != v2) {
        iterador = iterador->siguiente;
    }
    iterador->peso = p;
}

bool Grafo::ExisteArista(Vertice v1, Verticev2) {
    bool existe = false;
    SubLista *iterador = v1->sublista;
    while (iterador != nullptr && iterador->vertice != v2) {
        iterador = iterador->siguiente;
    }
    if(iterador != nullptr) {
        existe = true;
    }
    return existe;
}