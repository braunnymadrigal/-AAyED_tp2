#include "interfaz.hh"

void Interfaz::pruebas() {
    // Estructuras
    Grafo *grafo = new Grafo;
    // Mensaje de Bienvenida
    this->bienvenida();

    int opcion = -1;
    while (opcion != 0) {
        std::cout << "MENU PRINCIPAL:\n\t0. Salir\n\t1. Usar operadores "
                     "basicos.\n\t2. Usar algoritmos.\n\t3. Ver manual.";
        opcion = this->getOpcion();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'); // limpiar buffer
        switch (opcion) {
        case 1:
            this->probarOps(grafo);
            break;
        case 2:
            this->probarAlg(grafo);
            break;
        case 3:
            this->mostrarManual();
            break;
        }
        system("clear");
    }
}

void Interfaz::probarOps(Grafo *&grafo) {
    int opcion = -1;
    int etiqueta1;
    int etiqueta2;
    double realAux;
    while (opcion != 0) {
        this->mostrarOperadores();
        opcion = this->getOpcion();
        Grafo::Vert vertActual;
        switch (opcion) {
        case 1:
            if (grafo != nullptr) {
                delete grafo;
                grafo = nullptr;
            }
            grafo = new Grafo;
            std::cout << "Grafo creado... :)" << std::endl
                      << "Ya podemos empezar" << std::endl;

            break;

        case 2:
            delete grafo;
            grafo = nullptr;
            std::cout
                << "Grafo eliminado... :(" << std::endl
                << "Recuerda que no puedes trabajar con un grafo destruido, te "
                   "recomendamos que crees uno :)"
                << std::endl;

            break;

        case 3:
            grafo->Vaciar();
            std::cout << "El grafo se vacio..." << std::endl;

            break;

        case 4:
            if (grafo->Vacio()) {
                std::cout << "El grafo SÍ está vacio." << std::endl;
            } else {
                std::cout << "El grafo NO está vacio." << std::endl;
            }

            break;

        case 5: // AgregarVert
            std::cout << "*Recuerda que es un grafo de tipo de elemento int*"
                      << std::endl
                      << "Escribe la etiqueta: ";
            std::cin >> etiqueta1;
            grafo->AgregarVert(etiqueta1);
            std::cout << "Vertice agregado";

            break;

        case 6: // BorrarVert
            std::cout << "*Recuerda que el vertice a borrar debe ser un "
                         "vertice aislado*"
                      << std::endl
                      << "¿Que vertice quieres borrar?: ";
            std::cin >> etiqueta1;
            grafo->BorrarVert(grafo->EtiqAVert(etiqueta1));
            std::cout << "Se borro el vertice";

            break;

        case 7: // ModifEtiq
            std::cout << "*Recuerda que la etiqueta es de tipo de elemento "
                         "int*\n¿Cúal vertice "
                         "quieres modificar?: ";
            std::cin >> etiqueta1;

            std::cout << "\n¿Cúal quieres que sea la nueva etiqueta?: ";
            std::cin >> etiqueta2;
            vertActual = grafo->EtiqAVert(etiqueta1);
            grafo->ModifEtiq(vertActual, etiqueta2);
            std::cout << "Se modifico el vertice.";

            break;

        case 8: // Etiq
            std::cout << "*Recuerda que el vertice debe estar en el "
                         "grafo*\n¿De cual vertice "
                      << "quieres saber la etiqueta?: ";
            std::cin >> etiqueta1;
            std::cout << "Etiqueta es: "
                      << grafo->Etiq(grafo->EtiqAVert(etiqueta1));

            break;

        case 9: // AgregarArist
            std::cout << "*Recuerda que ambos vertices deben estar en el "
                         "grafo*\nElige el primer vertice: ";
            std::cin >> etiqueta1;

            std::cout << "Elige el segundo vertice: ";
            std::cin >> etiqueta2;
            std::cout << "Elige el peso de la arista: ";
            std::cin >> realAux;
            grafo->AgregarArist(
                grafo->EtiqAVert(etiqueta1), grafo->EtiqAVert(etiqueta2),
                realAux);
            std::cout << "Arista agregada.";

            break;

        case 10: // BorrarArist
            std::cout
                << "*Recuerda que la arista debe existir*\nElige el primer "
                   "vertice: ";
            std::cin >> etiqueta1;
            std::cout << "Elige el segundo vertice: ";
            std::cin >> etiqueta2;
            grafo->BorrarArist(
                grafo->EtiqAVert(etiqueta1), grafo->EtiqAVert(etiqueta2));
            std::cout << "Arista borrada";

            break;

        case 11: // ModifPeso
            std::cout
                << "*Recuerda que la arista debe existir*\nElige el primer "
                   "vertice: ";
            std::cin >> etiqueta1;
            std::cout << "Elige el segundo vertice: ";
            std::cin >> etiqueta2;
            std::cout << "Elige el nuevo peso de la arista: ";
            std::cin >> realAux;
            grafo->ModifPeso(
                grafo->EtiqAVert(etiqueta1), grafo->EtiqAVert(etiqueta2),
                realAux);
            std::cout << "Peso de arista modificado";

            break;

        case 12: // Peso
            std::cout
                << "*Recuerda que la arista debe existir*\nElige el primer "
                   "vertice: ";
            std::cin >> etiqueta1;
            std::cout << "Elige el segundo vertice: ";
            std::cin >> etiqueta2;
            std::cout << "Peso de la arista: "
                      << grafo->Peso(
                             grafo->EtiqAVert(etiqueta1),
                             grafo->EtiqAVert(etiqueta2));
            ;

            break;

        case 13: // PrimVert
            std::cout << "El primer vertice del grafo es: ";
            vertActual = grafo->PrimVert();
            if (vertActual == grafo->VertNulo) {
                std::cout << "Vertice Nulo";
            } else {
                std::cout << grafo->Etiq(vertActual);
            }

            break;

        case 14: // SigVert
            std::cout << "¿De cúal vertice quieres saber su siguiente?: ";
            std::cin >> etiqueta1;

            vertActual = grafo->SigVert(grafo->EtiqAVert(etiqueta1));
            if (vertActual == grafo->VertNulo) {
                std::cout << "Vertice Nulo";
            } else {
                std::cout << grafo->Etiq(vertActual);
            }

            break;

        case 15: // PrimVertAdy
            std::cout
                << "¿De cúal vertice quieres saber su primer adyacente?: ";
            std::cin >> etiqueta1;

            vertActual = grafo->PrimVertAdy(grafo->EtiqAVert(etiqueta1));
            if (vertActual == grafo->VertNulo) {
                std::cout << "Vertice Nulo";
            } else {
                std::cout << grafo->Etiq(vertActual);
            }

            break;

        case 16: // SigVertAdy
            std::cout << "Elige el vertice del cual es adyacente: ";
            std::cin >> etiqueta1;
            std::cout << "Elige el vertice del cual es siguiente: ";
            std::cin >> etiqueta2;

            vertActual = grafo->SigVertAdy(
                grafo->EtiqAVert(etiqueta1), grafo->EtiqAVert(etiqueta2));
            if (vertActual == grafo->VertNulo) {
                std::cout << "Vertice Nulo";
            } else {
                std::cout << grafo->Etiq(vertActual);
            }

            break;

        case 17: // NumVertices
            std::cout << "Numero de vertices: " << grafo->NumVertices();

            break;

        case 18: // Imprimir
            grafo->Imprimir();

            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        system("clear");
    }
}

void Interfaz::mostrarOperadores() {
    std::cout << "OPERADORES BASICOS DEL ARBOL:\n"
              << "\t00. Salir.\n"
              << "\t01. Crear.\n"
              << "\t02. Destruir.\n"
              << "\t03. Vaciar.\n"
              << "\t04. Vacio.\n"
              << "\t05. Agregar Vertice.\n"
              << "\t06. Borrar Vertice.\n"
              << "\t07. Modificar Etiqueta.\n"
              << "\t08. Etiqueta.\n"
              << "\t09. Agregar Arista.\n"
              << "\t10. Borrar Arista.\n"
              << "\t11. Modificar Peso.\n"
              << "\t12. Peso.\n"
              << "\t13. Primer Vertice.\n"
              << "\t14. Siguiente Vertice.\n"
              << "\t15. Primer Vertice Adyacente.\n"
              << "\t16. Siguiente Vertice Adyacentes.\n"
              << "\t17. Numero de Vertices.\n"
              << "\t18. EXTRA (IMPRIMIR).\n";
}

void Interfaz::mostrarAlgoritmos() {
    std::cout << "ALGORITMOS PARA EL ARBOL:\n"
              << "\t0. Salir.\n"
              << "\t1. NumAristas.\n"
              << "\t2. EsConexo(ProfPrim).\n"
              << "\t3. Es Conexo(AnchoPrim).\n"
              << "\t4. Dijkstra.\n"
              << "\t5. Floyd.\n"
              << "\t6. Prim.\n"
              << "\t7. Kruskal.\n"
              << "\t8. HamiltonBEP.\n";
}

void Interfaz::bienvenida() {
    system("clear");
    std::cout
        << "BIENVENIDO.\nEste es el programa que permite operar la estructura "
           "de "
           "datos Grafo NO Dirigido, con pesos, sin aristas paralelas y sin "
           "lazos "
           "con: "
           "\n\tOperadores basicos de dicha estructura. \n\tAlgoritmos que "
           "operan dicha estructura. \n\nPresione enter para continuar.";
    std::cin.get();
    system("clear");
}

int Interfaz::getOpcion() {
    int opcion = -1;
    std::cout << "\n¿Que deseas hacer?:";
    std::string entrada = "";
    std::cin >> entrada;
    std::cout << std::endl;
    try {
        opcion = std::stoi(entrada);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: Entrada no válida. No es un número entero."
                  << std::endl;
    }
    return opcion;
}

void Interfaz::mostrarManual() {
    system("clear");
    std::string reglas =
        "\tOPERADORES\n\nIniciar(Grafo G)\n\tEfecto: Inicializa el grafo  G "
        "como grafo no dirigido.\n\tRequiere: Un grafo G no inicializado o "
        "destruido.\n\tModifica: El grafo G.\nDestruir(Grafo G)\n\tEfecto: "
        "Destruye el grafo G.\n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: El grafo G.\nVaciar(Grafo G)\n\tEfecto: "
        "Vacía el grafo G.\n\tRequiere: Un grafo G inicializado no "
        "vacío.\n\tModifica: El grafo G.\nVacio(Grafo G) -> bool\n\tEfecto: "
        "Pregunta si el grafo G está vacío. Devuelve un bool en verdadero si "
        "lo está, falso en caso contrario. \n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: N/A\nAgregarVert(Grafo G, etiqueta e) -> "
        "vértice\n\tEfecto: Agrega un vértice como vértice aislado en el grafo "
        "G. Devuelve el vértice que se acaba de agregar.\n\tRequiere: Un grafo "
        "G inicializado y un parámetro e tipo etiqueta.\n\tModifica: El grafo "
        "G.\nBorrarVert(Grafo G, vértice v)\n\tEfecto: Borra el vértice v "
        "aislado del grafo G.\n\tRequiere: Un grafo G inicializado no vacío y "
        "un vértice v válido en G y v aislado.\n\tModifica: El grafo "
        "G.\nModifEtiq(Grafo G, vértice v, etiqueta e)\n\tEfecto: Modifica la "
        "etiqueta del vértice v, la actualiza a ser etiqueta e.\n\tRequiere: "
        "Un grafo G inicializado no vacío, un vértice v válido en G y un "
        "parámetro e tipo etiqueta.\n\tModifica: El grafo G.\nEtiq(Grafo G, "
        "vértice v) -> etiqueta\n\tEfecto: Devuelve la etiqueta asociada al "
        "vértice v.\n\tRequiere: Un grafo G inicializado no vacío y un vértice "
        "v válido en G.\n\tModifica: N/A\nAgregarArist(Grafo G, vértice v1, "
        "vértice v2, peso p) \n\tEfecto: Agrega arista de v1 a v2 con peso "
        "p.\n\tRequiere: Un grafo G inicializado no vacio, vértices v1 y v2 "
        "válidos en G, v1 distinto a v2, que no exista arista previa de v1 a "
        "v2 y un parámetro p tipo peso. \n\tModifica: El grafo "
        "G.\nBorrarArist(Grafo G, vértice v1, vértice v2)\n\tEfecto: Borra la "
        "arista que va de v1 a v2.\n\tRequiere: Un grafo G inicializado no "
        "vacío, vértices v1 y v2 válidos en G y que arista de v1 a v2 "
        "exista.\n\tModifica: El grafo G.\nModifPeso(Grafo G, vértice v1, "
        "vértice v2, peso p)\n\tEfecto: Modifica el peso de la arista que va "
        "de v1 a v2. \n\tRequiere: Un grafo G inicializado no vacío, vértices "
        "v1 y v2 válidos en G, que exista arista de v1 a v2 y un parámetro p "
        "de tipo peso. \n\tModifica: El grafo G.\nPeso(Grafo G, vértice v1, "
        "vértice v2) -> peso\n\tEfecto: Devuelve el peso de la arista que va "
        "de v1 a v2.\n\tRequiere: Un grafo G inicializado no vacío, vértices "
        "v1 y v2 válidos en G y que exista arista de v1 a v2. \n\tModifica: "
        "N/A\nPrimVert(Grafo G) -> vertice\n\tEfecto: Devuelve el primer "
        "vértice del grafo G.\n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: N/A\nSigVert(Grafo G, vértice v) -> "
        "vértice\n\tEfecto: Devuelve el vértice siguiente de v en el grafo "
        "G.\n\tRequiere: Un grafo G inicializado no vacío y un vértice v "
        "válido en G.\n\tModifica: N/A\nPrimVertAdy(Grafo G, vértice v) -> "
        "vértice\n\tEfecto: Devuelve un vértice adyacente a v en el grafo "
        "G.\n\tRequiere:Un grafo G inicializado no vacío y un vértice v válido "
        "en G.\n\tModifica: N/A \nSigVertAdy(Grafo G, vértice v1, vértice v2) "
        "-> vértice\n\tEfecto: Devuelve un vértice adyacente a v1 pero que sea "
        "siguiente de v2 en el grafo G.\n\tRequiere: Un grafo G inicializado "
        "no vacío, un vértice v1 válido en G y un vértice v2 válido en G y "
        "adyacente a v2.\n\tModifica: N/A\nNumVertices(Grafo G) -> "
        "entero\n\tEfecto: Devuelve un entero que representa el número de "
        "vértices del grafo G.\n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: N/A\n\n\tALGORITMOS\n\nNumAristas(Grafo G) "
        "-> entero\n\tEfecto: Cuenta las aristas del grafo G. Devuelve como "
        "entero el número de ellas.\n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: N/A\nEsConexoProfPrim(Grafo G) -> "
        "bool\n\tEfecto: Averigua si el grafo G es conexo haciendo un "
        "recorrido en profundidad primero. Devuelve verdadero si lo es, falso "
        "en caso contrario.\n\tRequiere: Un grafo G inicializado.\n\tModifica: "
        "N/A\nEsConexoAnchoPrim(Grafo G) -> bool\n\tEfecto: Averigua si el "
        "grafo G es conexo haciendo un recorrido en ancho primero. Devuelve "
        "verdadero si lo es, falso en caso contrario.\n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: N/A\nDijkstra(Grafo G, vértice v1) -> "
        "Lista\n\tEfecto: Encuentra el camino más corto del vértice v1 a todos "
        "los demás. Devuelve dicho camino en forma de lista.\n\tRequiere: Un "
        "grafo G inicializado y no vacío y un vértice v1 válido en "
        "G.\n\tModifica: N/A\nFloyd(Grafo G) -> Lista\n\tEfecto: Encuentra el "
        "camino más corto entre todo par de vértices. Devuelve dicho camino en "
        "forma de lista.\n\tRequiere: Un grafo G inicializado.\n\tModifica: "
        "N/A\nPrim(Grafo G) -> Lista\n\tEfecto: Encuentra el  árbol de mínimo "
        "costo usando prim. Devuelve dicho árbol en forma de "
        "lista.\n\tRequiere: Un grafo G inicializado.\n\tModifica: "
        "N/A\nKruskal(Grafo G) -> Lista\n\tEfecto: Encuentra el  árbol de "
        "mínimo costo usando kruskal. Devuelve dicho árbol en forma de "
        "lista.\n\tRequiere: Un grafo G inicializado.\n\tModifica: "
        "N/A\nHamiltonBEP(Grafo G) -> Lista\n\tEfecto: Encuentra el circuito "
        "de Hamilton de menor costo usando búsqueda exhaustiva pura. Devuelve "
        "dicho circuito en forma de lista.\n\tRequiere: Un grafo G "
        "inicializado.\n\tModifica: N/A";
    std::cout << reglas;
    std::cin.get();
    system("clear");
}

void Interfaz::probarAlg(Grafo *&grafo) {
    Algoritmos alg;
    int opcion = -1;
    int etiqueta1;
    int etiqueta2;
    double realAux;
    while (opcion != 0) {
        this->mostrarAlgoritmos();
        opcion = this->getOpcion();
        Grafo::Vert vertActual;
        switch (opcion) {
        case 1:
            std::cout << "Numero de aristas: " << alg.NumAristas(grafo);
            break;

        case 2:
            if (alg.EsConexoProfPrim(grafo)) {
                std::cout << "SI es conexo";
            } else {
                std::cout << "NO es conexo";
            }
            break;

        case 3:
            if (alg.EsConexoAnchoPrim(grafo)) {
                std::cout << "SI es conexo";
            } else {
                std::cout << "NO es conexo";
            }
            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        system("clear");
    }
}
