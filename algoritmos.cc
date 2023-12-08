#include "algoritmos.hh"

// Estructuras Aux
// ABRIR

class ConjuntoDeConjuntos {
public:
    void Iniciar() {
        conjuntos.clear(); // Crear como vacía
    }

    void AgregarSubConjUnitario(int I, Grafo::Vert v) {
        if (I >= conjuntos.size()) {
            conjuntos.resize(
                I + 1); // Ajustar el tamaño del vector si es necesario
        }
        conjuntos[I].push_back(v); // Agregar v al subconjunto en la posición I
    }

    int BuscarElem(Grafo::Vert v) {
        for (int i = 0; i < conjuntos.size(); ++i) {
            for (const auto &subconjunto : conjuntos[i]) {
                if (subconjunto == v) {
                    return i; // Devolver el número del subconjunto que contiene
                              // v
                }
            }
        }
        return -1; // Si no se encuentra v en ningún subconjunto
    }

    void Unir(int I1, int I2) {
        if (I1 >= 0 && I1 < conjuntos.size() && I2 >= 0 &&
            I2 < conjuntos.size()) {
            // Unir los conjuntos I1 e I2
            conjuntos[I1].insert(
                conjuntos[I1].end(), conjuntos[I2].begin(), conjuntos[I2].end());
            conjuntos[I2].clear(); // Limpiar el conjunto I2 después de la unión
        }
    }

private:
    std::vector<std::vector<Grafo::Vert>> conjuntos;
};

struct Arista {
    Grafo::Vert Comp1;
    Grafo::Vert Comp2;
    int Peso;

    //Arista(Grafo::Vert c1, Grafo::Vert c2, int peso): Comp1(c1), Comp2(c2), Peso(peso) {}

    bool operator<(const Arista &otra) const { return Peso < otra.Peso; }

    bool operator==(const Arista &otra) const {
        return Comp1 == otra.Comp1 && Comp2 == otra.Comp2 && Peso == otra.Peso;
    }
};

class PartialOrderTree {
private:
    std::vector<Arista> heap; // Cambiado el tipo del vector

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(const Arista &value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    Arista getMin() const {
        if (!heap.empty()) {
            return heap[0];
        }
        throw std::out_of_range("The tree is empty.");
    }

    void removeMin() {
        if (!heap.empty()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        } else {
            throw std::out_of_range("The tree is empty.");
        }
    }

    bool contains(const Arista &value) const {
        return std::find_if(
                   heap.begin(), heap.end(), [&value](const Arista &a) {
                       return a == value;
                   }) != heap.end();
    }
};

// Estructuras Aux
//  CERRAR


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

// Dijkstra
void Algoritmos::Dijkstra(Grafo *G, Grafo::Vert vSalida) {
    if (!G->Vacio()) {
        // Variables
        std::map<int, Grafo::Vert> R11; // Relacion 1:1
        double costos[G->NumVertices() - 1];
        Grafo::Vert vertices[G->NumVertices() - 1]; // Vertices anteriores
        bool pivotes[G->NumVertices() - 1];         // Para saber quienes han sido
                                                    // pivotes

        // Inicializacion
        for (int i = 0; i < sizeof(costos) / sizeof(costos[0]); ++i) {
            costos[i] = std::numeric_limits<int>::max();
            vertices[i] = G->VertNulo;
        }
        // Pone los pesos que hay desde el vertice de salida hacia los demas
        int i = 0;
        Grafo::Vert v = G->PrimVert();
        while (v != G->VertNulo) {
            if (v != vSalida) {
                R11.emplace(i, v);
                if (G->ExisteArista(vSalida, v)) {
                    costos[i] = G->Peso(vSalida, v);
                }
                vertices[i] = vSalida;
                pivotes[i] = false;
                ++i;
            }
            v = G->SigVert(v);
        }

        // Ciclo Principal
        // Itera atraves de todos n-1 vertices tomando pivotes y considerando si
        // se tiene un menor costo usando el pivote como intermedio
        int indicePivote;
        Grafo::Vert pivote = G->VertNulo;
        for (i = 0; i < G->NumVertices() - 1; ++i) {
            indicePivote = BuscarPivote(costos, pivotes, G->NumVertices());
            pivote = R11[indicePivote];
            pivotes[indicePivote] = true;
            for (int j = 0; j < G->NumVertices() - 1; ++j) {
                if (!pivotes[j]) {
                    v = R11[j];
                    if (G->ExisteArista(pivote, v)) {
                        if (G->Peso(pivote, v) + costos[indicePivote] <
                            costos[j]) {
                            costos[j] =
                                G->Peso(pivote, v) + costos[indicePivote];
                            vertices[j] = pivote;
                        }
                    }
                }
            }
        }
        // Resultados finales
        std::cout << "\tRESULTADO" << std::endl;
        for (int i = 0; i < G->NumVertices() - 1; ++i) {
            std::cout << "|" << G->Etiq(R11[i]) << "|";
        }
        std::cout << "-> Vertices" << std::endl;

        for (int i = 0; i < G->NumVertices() - 1; ++i) {
            std::cout << "|" << costos[i] << "|";
        }
        std::cout << "-> Costos" << std::endl;

        for (int i = 0; i < G->NumVertices() - 1; ++i) {
            std::cout << "|" << G->Etiq(vertices[i]) << "|";
        }
        std::cout << "-> Vertices Anteriores" << std::endl;
    }
}

void Algoritmos::Floyd(Grafo *G) {
    if (!G->Vacio()) {
        // Variables
        std::map<int, Grafo::Vert> R11; // Relacion 1:1
        double costos[G->NumVertices()][G->NumVertices()];
        int vertices[G->NumVertices()][G->NumVertices()]; // Vertices
                                                          // intermedios

        int i = 0;
        Grafo::Vert v = G->PrimVert();
        // Inicializacion, pone todos los valores necesarios para que el calculo
        // sea correcto en caso de no haber arista
        while (v != G->VertNulo) {
            R11.emplace(i, v);
            v = G->SigVert(v);
            i++;
        }
        for (int i = 0; i < G->NumVertices(); ++i) {
            for (int j = 0; j < G->NumVertices(); ++j) {
                if (i == j) {
                    costos[i][j] = 0;
                } else {
                    costos[i][j] = std::numeric_limits<int>::max();
                }
                vertices[i][j] = -1;
            }
        }

        // Agrega los pesos de que existen entre todo par de vertices de
        // adyacentes
        Grafo::Vert va = G->VertNulo;
        v = G->PrimVert();
        int preImagenV;
        int preImagenVA;
        while (v != G->VertNulo) {
            va = G->PrimVertAdy(v);
            preImagenV = getPreImagen(R11, v);
            while (va != G->VertNulo) {
                preImagenVA = getPreImagen(R11, va);
                costos[preImagenV][preImagenVA] = G->Peso(v, va);
                va = G->SigVertAdy(v, va);
            }
            v = G->SigVert(v);
        }

        // Ciclo Principal
        int n = G->NumVertices();

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && k != j &&
                        k != i) { // Verifica que no sea una diagonal, ni que se
                                  // intente usar el pivote para llegar a el
                                  // mismo.
                        if (costos[i][k] + costos[k][j] < costos[i][j] ||
                            costos[i][j] == -1) {
                            if (costos[i][k] != -1 && costos[k][j] != -1) {
                                costos[i][j] = costos[i][k] + costos[k][j];
                                vertices[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
        // resultados
        std::cout << "\tRESUlTADOS" << std::endl;
        std::cout << "\tCostos" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << "|" << costos[i][j] << "|";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "\tVertices" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << "|" << vertices[i][j] << "|"; //LINEA CAMBIADA
            }
            std::cout << std::endl;
        }
    }
}

void Algoritmos::Prim(Grafo *G) {
    if (G->Vacio()) {
        // Variables
        std::map<int, Grafo::Vert> R11;
        double costos[G->NumVertices() - 1];
        Grafo::Vert vertices[G->NumVertices() - 1];
        bool pivotes[G->NumVertices() - 1];

        // Inicializacion
        for (int i = 0; i < sizeof(costos) / sizeof(costos[0]); i++) {
            costos[i] = -1;
            vertices[i] = G->VertNulo;
        }

        Grafo::Vert vSalida = G->PrimVert();
        R11.emplace(0, vSalida);

        int i = 1;
        Grafo::Vert v = G->SigVert(vSalida);
        // Pone el peso que existe entre el vertice inicial y todos los demas
        while (v != G->VertNulo) {
            R11.emplace(i, v);
            if (G->ExisteArista(v, vSalida)) {
                costos[i] = G->Peso(vSalida, v);
            } else {
                costos[i] = -1;
            }
            vertices[i] = vSalida;
            v = G->SigVert(v);
            ++i;
        }

        // Ciclo principal
        int indicePivote = -1;
        Grafo::Vert pivote = G->VertNulo;
        for (i = 1; i < G->NumVertices(); ++i) {
            indicePivote = BuscarPivote(costos, pivotes, G->NumVertices());
            pivote = R11[indicePivote];
            pivotes[indicePivote] = true;
            for (int j = 1; j < G->NumVertices(); ++j) {
                if (!pivotes[j]) {
                    v = R11[j];
                    if (G->ExisteArista(v, pivote)) {
                        if (G->Peso(v, pivote) < costos[j] || costos[j] == -1) {
                            costos[j] = G->Peso(pivote, v);
                            vertices[j] = pivote;
                        }
                    }
                }
            }
        }

        std::cout << "\tRESULTADOS" << std::endl;
        for (int i = 0; i < G->NumVertices(); ++i) { // CAMBIO i de 1 a 0
            std::cout << "|" << costos[i] << "|";
        }
        std::cout << "-> Costos" << std::endl;
        for (int i = 0; i < G->NumVertices(); ++i) {
            std::cout << "|" << G->Etiq(vertices[i]) << "|";
        }
        std::cout << "-> Vertices" << std::endl;
    }
}

// Kruskal
void Algoritmos::Kruskal(Grafo *G) {
	if(NumAristas(G) > 0) {
		std::vector<Arista> L;
		PartialOrderTree APO;
		ConjuntoDeConjuntos CC;
		CC.Iniciar();
		Grafo::Vert v = G->PrimVert();
		int i = 1;
		while (v != G->VertNulo) {
		    CC.AgregarSubConjUnitario(i, v);
		    ++i;
		    Grafo::Vert va = G->PrimVertAdy(v);
		    Arista aristAux;
		    aristAux.Comp1 = v;

		    while (va != G->VertNulo) {

		        aristAux.Comp2 = va;
		        aristAux.Peso = G->Peso(v,va);

		        if (!APO.contains(aristAux)) {
		            APO.insert(aristAux);
		        }
		        va = G->SigVertAdy(v, va);
		    }
		    v = G->SigVert(v);
		}
		int n = G->NumVertices();
		int TotAristEsc = 0;
		while (TotAristEsc < n - 1) {
		    Arista minValue = APO.getMin();
		    APO.removeMin();

		    int Ident1 = CC.BuscarElem(minValue.Comp1);
		    int Ident2 = CC.BuscarElem(minValue.Comp2);
		    if (Ident1 != Ident2) {
		        L.push_back(minValue);
		        ++TotAristEsc;
		        CC.Unir(Ident1, Ident2);
		    }
		}

		for (const auto &element : L) {
		    std::cout << G->Etiq(element.Comp1) << "," << G->Etiq(element.Comp2)
		              << "," << G->Peso(element.Comp1, element.Comp2) << "\t";
		}
		std::cout << std::endl;
	}
}


void Algoritmos::HamiltonBEP(Grafo *G) {
	for (int i = 0; i < std::size(SolMejor); ++i) {
		SolAct[i] = G->VertNulo;
		SolMejor[i] = G->VertNulo;
	}

	if(!G->Vacio()) {
		MenorCosto = std::numeric_limits<double>::infinity();
		CostoAct = 0;
		SolAct[0] = G->PrimVert();
		Dicc[G->PrimVert()] = true;
		HamiltonBEPR(G, 2);
	}
	
	std::cout << "Menor Costo: " << MenorCosto << std::endl;
}

void Algoritmos::HamiltonBEPR(Grafo *G, int i) {
	Grafo::Vert va = G->PrimVertAdy(SolAct[i-2]);
	while (va != G->VertNulo) {
		if (Dicc.find(va) == Dicc.end()) {
			SolAct[i-1] = va;
			Dicc[va] = true;
			CostoAct += G->Peso(SolAct[i-2], va);
			
			if (i == G->NumVertices()) {
				if ( G->ExisteArista(va,SolAct[0]) ) {
					if (CostoAct + G->Peso(va,SolAct[0]) < MenorCosto) {
						MenorCosto = CostoAct + G->Peso(va,SolAct[0]);
						//SolMejor = SolAct;
						std::copy(std::begin(SolAct), std::end(SolAct), std::begin(SolMejor));
					}
				}
			}
			else {
				HamiltonBEPR(G, i+1);
			}
			//Dicc[va] = false;
			Dicc.erase(va);
			CostoAct -= G->Peso(SolAct[i-2],va);
		}
		va = G->SigVertAdy(SolAct[i-2],va);
	}
}


// privados
void Algoritmos::EsConexoProfPrimR(
    Grafo *G,
    Grafo::Vert v,
    std::map<Grafo::Vert, bool> &DVV,
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

// Elige el siguiente pivote, lo hace buscando entre los vertices que no han
// sido pivotes el que tenga menor costo
int Algoritmos::BuscarPivote(double *costos, bool *pivotes, int tamanyo) {
    double costo = 0;
    int indiceDelPivote = 0;
    bool sinCosto = true;
    for (int i = 0; i < tamanyo - 1; ++i) {
        if (!pivotes[i]) {
            if (sinCosto) {
                costo = costos[i];
                indiceDelPivote = i;
                sinCosto = false;
            } else if (costos[i] < costo) {
                costo = costos[i];
                indiceDelPivote = i;
            }
        }
    }
    return indiceDelPivote;
}

// Retorna la preImagen asignada al pivote en la relacion 1:1 que haya sido
// planteada previamente
int Algoritmos::getPreImagen(
    const std::map<int, Grafo::Vert> &R11,
    Grafo::Vert pivote) {
    auto preImagen =
        std::find_if(R11.begin(), R11.end(), [=](const auto &pair) {
            return pair.second == pivote;
        });

    return (preImagen != R11.end()) ? preImagen->first : -1;
}
