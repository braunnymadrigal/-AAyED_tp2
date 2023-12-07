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
            this->probarOps(arbol);
            break;
        case 2:
            this->probarAlg(arbol);
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
    char etiqueta1 = ' ';
    char etiqueta2 = ' ';
    int enteroAux = 0;
    while (opcion != 0) {
        this->mostrarOperadoresArbol();
        opcion = this->getOpcion();
        Arbol::Node nodoActual;
        switch (opcion) {
        case 1:
            if (arbol != nullptr) {
                delete arbol;
                arbol = nullptr;
            }
            arbol = new Arbol;
            std::cout << "Arbol creado... :)" << std::endl
                      << "Ya podemos empezar" << std::endl;

            break;

        case 2:
            delete arbol;
            arbol = nullptr;
            std::cout
                << "Arbol eliminado... :(" << std::endl
                << "Recuerda que no puedes trabajar con un arbol destruido, te "
                   "recomendamos que crees uno :)"
                << std::endl;

            break;

        case 3:
            arbol->Vaciar();
            std::cout << "El arbol se vacio..." << std::endl;

            break;

        case 4:
            if (arbol->Vacio()) {
                std::cout << "El arbol SÍ está vacio." << std::endl;
            } else {
                std::cout << "El arbol NO está vacio." << std::endl;
            }

            break;

        case 5:
            std::cout << "*Recuerda que es un arbol de tipo de elemento char*"
                      << std::endl
                      << "¿Cúal quieres que sea la raiz?: ";
            std::cin >> etiqueta1;
            arbol->PonerRaiz(etiqueta1);
            std::cout << "La nueva raiz es:" << etiqueta1;

            break;

        case 6:
            std::cout << "*Recuerda que es un arbol de tipo de elemento char y "
                         "que la "
                         "posición del nodo va desde el 1 hasta la cantidad de "
                         "hijos + 1*"
                      << std::endl
                      << "¿Cúal quieres que sea el padre?: ";
            std::cin >> etiqueta1;

            std::cout << "\n¿Cúal quieres que sea el nuevo nodo?: ";
            std::cin >> etiqueta2;

            std::cout << "\n¿En que posición quieres que este el nodo?: ";
            std::cin >> enteroAux;
            nodoActual = arbol->getNodo(etiqueta1);
            arbol->AgregarHijo(nodoActual, etiqueta2, enteroAux);
            std::cout << "Se agrego el nuevo nodo ";

            break;

        case 7:
            std::cout
                << "*Recuerda que el nodo debe ser una etiqueta*\n¿Cúal nodo "
                   "quieres borrar?: ";
            std::cin >> etiqueta1;
            nodoActual = arbol->getNodo(etiqueta1);
            arbol->BorrarHoja(nodoActual);
            std::cout << "Se borro el nodo." << etiqueta1;

            break;

        case 8:
            std::cout
                << "*Recuerda que el nodo debe estar en el arbol*\n¿Cúal nodo "
                   "quieres modificar?: ";
            std::cin >> etiqueta1;

            std::cout << "\n¿Cúal quieres que sea la nueva etiqueta?: ";
            std::cin >> etiqueta2;
            nodoActual = arbol->getNodo(etiqueta1);
            arbol->ModificarEtiqueta(nodoActual, etiqueta2);
            std::cout << "Se modifico el nodo.";

            break;

        case 9:
            if (arbol->Vacio()) {
                std::cout << "El árbol no tiene raíz, puedes agregarle una :)";
            } else {
                std::cout << "La raíz del arbol es: "
                          << arbol->Etiqueta(arbol->Raiz());
            }

            break;

        case 10:
            std::cout
                << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber el padre?: ";
            std::cin >> etiqueta1;

            std::cout << "El padre del nodo " << etiqueta1 << " es: ";
            if (arbol->Padre(arbol->getNodo(etiqueta1)) == arbol->NodoNulo) {
                std::cout << "nodo nulo";
            } else {
                std::cout << arbol->Etiqueta(
                    arbol->Padre(arbol->getNodo(etiqueta1)));
            }

            break;

        case 11:
            std::cout
                << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber el hijo más izquierdo?: ";
            std::cin >> etiqueta1;

            std::cout << "El hijo más izquierdo del nodo " << etiqueta1
                      << " es: ";
            if (arbol->HijoMasIzq(arbol->getNodo(etiqueta1)) ==
                arbol->NodoNulo) {
                std::cout << "nodo nulo";
            } else {
                std::cout << arbol->Etiqueta(
                    arbol->HijoMasIzq(arbol->getNodo(etiqueta1)));
            }

            break;

        case 12:
            std::cout
                << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber el hermano derecho?: ";
            std::cin >> etiqueta1;
            std::cout << "El hermano derecho del nodo " << etiqueta1 << " es: ";
            if (arbol->HermanoDer(arbol->getNodo(etiqueta1)) ==
                arbol->NodoNulo) {
                std::cout << "nodo nulo";
            } else {
                std::cout << arbol->Etiqueta(
                    arbol->HermanoDer(arbol->getNodo(etiqueta1)));
            }

            break;

        case 13:
            enteroAux = arbol->NumNodos();
            std::cout << "El número de nodos del árbol es: " << enteroAux;

            break;

        case 14:
            std::cout
                << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber la cantidad de hijos?: ";
            std::cin >> etiqueta1;
            enteroAux = arbol->NumHijos(arbol->getNodo(etiqueta1));
            std::cout << "El número de nodos hijos del nodo " << etiqueta1
                      << ": " << enteroAux;

            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        system("clear");
    }
}

void Interfaz::mostrarOperadoresArbol() {
    std::cout << "OPERADORES BASICOS DEL ARBOL:\n"
              << "\t0. Salir.\n"
              << "\t1. Crear.\n"
              << "\t2. Destruir.\n"
              << "\t3. Vaciar.\n"
              << "\t4. Vacio.\n"
              << "\t5. Poner Raiz.\n"
              << "\t6. Agregar Hijo.\n"
              << "\t7. Borrar Hoja.\n"
              << "\t8. Modificar Etiqueta.\n"
              << "\t9. Raiz.\n"
              << "\t10. Padre.\n"
              << "\t11. Hijo mas Izquierdo.\n"
              << "\t12. Hermano Derecho.\n"
              << "\t13. Numero de Nodos.\n"
              << "\t14. Numero de Hijos.\n";
}

void Interfaz::mostrarAlgoritmosArbol() {
    std::cout << "ALGORITMOS PARA EL ARBOL:\n"
              << "\t0. Salir.\n"
              << "\t1. Hermano Izquierdo.\n"
              << "\t2. Etiquetas Repetidas.\n"
              << "\t3. Altura Nodo.\n"
              << "\t4. Profundidad Nodo.\n"
              << "\t5. Niveles PreOrden.\n"
              << "\t6. Niveles PorNiveles.\n"
              << "\t7. Listar Iesimo Nivel.\n"
              << "\t8. Listar PreOrden.\n"
              << "\t9. Listar PorNiveles.\n"
              << "\t10. Buscar Etiqueta.\n"
              << "\t11. Borrar SubArbol.\n"
              << "\t12. Listar Hijos de Nodo.\n";
}

void Interfaz::bienvenida() {
    system("clear");
    std::cout
        << "BIENVENIDO.\nEste es programa que permite operar la estructura de "
           "datos Arbol n-ario tal que sí importa el orden entre los hijos "
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
        "MANUAL DE OPERADORES:\nCOLA\nIniciar(Cola C)\n\tEfecto: Inicializa la "
        "cola C como una cola vacía.\n\tRequiere: Una cola C no inicializada o "
        "destruida.\n\tModifica: La cola C.\nDestruir (Cola C)\n\tEfecto: "
        "Destruye la cola C dejándola inutilizable.\n\tRequiere: Una cola C "
        "inicializada.\n\tModifica: La cola C.\nVaciar (Cola C)\n\tEfecto: "
        "Limpia la cola C, dejándola con 0 elementos.\n\tRequiere: Una cola C "
        "inicializada.\n\tModifica: La cola C.\nVacia (Cola C) -> "
        "booleano\n\tEfecto: Comprueba si la cola esta vacía. Devuelve "
        "verdadero "
        "si lo está, falso en caso contrario.\n\tRequiere: Una cola C "
        "inicializada.\n\tModifica: N/A.\nEncolar (Elemento e, Cola "
        "C)\n\tEfecto: Agrega el elemento e al final de la cola "
        "C.\n\tRequiere: "
        "Una cola C inicializada y un elemento e válido.\n\tModifica: La cola "
        "C.\nDesencolar (Cola) -> elemento\n\tEfecto: Borra y devuelve el "
        "elemento que está al frente de la cola.\n\tRequiere: Una cola C "
        "inicializada y no vacía.\n\tModifica: La cola C.\nFrente (Cola c) -> "
        "elemento\n\tEfecto: Devuelve el elemento que está al frente de la "
        "cola.\n\tRequiere: Una cola C inicializada y no vacía.\n\tModifica: "
        "N/A.\n\nARBOL\nIniciar (Arbol A)\n\tEfecto: Inicializa el árbol como "
        "un "
        "árbol vacío.\n\tRequiere: Un árbol A no inicializado o "
        "destruido.\n\tModifica: El árbol A.\nDestruir (Arbol A)\n\tEfecto: "
        "Destruye el árbol A dejándolo inutilizable.\n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: EL árbol A.\nVaciar (Arbol A)\n\tEfecto: "
        "Limpia el árbol A, dejándolo con 0 nodos.\n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: El árbol A.\nVacio (Arbol A) -> "
        "booleano\n\tEfecto: Comprueba si el árbol esta vacío. Devuelve "
        "verdadero si lo está, falso en caso contrario.\n\tRequiere: Un árbol "
        "A "
        "inicializado.\n\tModifica: N/A.\n PonerRaíz (Etiqueta e, Arbol "
        "A)\n\tEfecto: Pone en el árbol A, un nodo raíz que contiene la "
        "etiqueta "
        "e, de esta forma le quita el estatus de vacío al árbol.\n\tRequiere: "
        "Un "
        "árbol A inicializado y vacío y una etiqueta.\n\tModifica: El árbol "
        "A.\nAgregarHijo (Nodo n, Etiqueta e, int i, Arbol A) -> "
        "nodo\n\tEfecto: "
        "Pone en el árbol A, un nodo que contiene la etiqueta e como hijo del "
        "nodo n en la posición i dentro de sus hijos y devuelve el nuevo nodo "
        "agregado.\n\tRequiere: Un árbol A inicializado, no vacío, un nodo n "
        "distinto a nodoNulo, una etiqueta e y una posición i menor o igual "
        "que "
        "el número de hijos del nodo n más 1, pero con i mayor que "
        "0.\n\tModifica: El árbol A.\nBorrarHoja (Nodo n, Arbol A)\n\tEfecto: "
        "Elimina el nodo n.\n\tRequiere: Un árbol A inicializado, no vacío y "
        "un "
        "nodo n sea un nodo hoja.\n\tModifica: El árbol A.\nModificarEtiqueta "
        "(Nodo n, Etiqueta e, Árbol A)\n\tEfecto: Modifica la etiqueta que "
        "contiene el nodo n, por la etiqueta e.\n\tRequiere: Un árbol A "
        "inicializado, no vacío, un nodo n distinto a nodoNulo y una etiqueta "
        "e.\n\tModifica: El árbol A, específicamente el nodo n.\nRaiz (Arbol "
        "A) "
        "-> nodo\n\tEfecto: Devuelve el nodo raíz del árbol y si está vacío "
        "devuelve nodoNulo.\n\tRequiere: Un árbol A inicializado.\n\tModifica: "
        "N/A.\nPadre (Nodo n, Árbol A) -> nodo\n\tEfecto: Devuelve el nodo "
        "padre "
        "del nodo n y si no tiene padre devuelve nodoNulo.\n\tRequiere: Un "
        "árbol "
        "A inicializado, no vacío y un nodo distinto a nodoNulo.\n\tModifica: "
        "N/A.\nHijoMasIzq (Nodo n, Árbol A) -> nodo\n\tEfecto: Devuelve el "
        "hijo "
        "más izquierdo del nodo n y si no tiene hijos devuelve "
        "nodoNulo.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo "
        "distinto a nodo nulo.\n\tModifica: N/A.\nHermanoDer (Nodo n, Árbol A) "
        "-> "
        "nodo\n\tEfecto: Devuelve el hermano derecho del nodo n y si no tiene "
        "hermano derecho devuelve nodoNulo.\n\tRequiere: Un árbol A "
        "inicializado, no vacío y un nodo distinto a nodo nulo.\n\tModifica: "
        "N/A.\nEtiqueta (Nodo n, Árbol A) -> etiqueta\n\tEfecto: Devuelve la "
        "etiqueta en relación 1 a 1 con el nodo n.\n\tRequiere: Un árbol A "
        "inicializado, no vacío y un nodo distinto a nodoNulo.\n\tModifica: "
        "N/A.\nNumNodos(Árbol A) -> int\n\tEfecto: Devuelve como un entero la "
        "cantidad de nodos que contiene el árbol A.\n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: N/A.\nNumHijos (Nodo n, Árbol A) -> "
        "int\n\tEfecto: Devuelve como un entero la cantidad de nodos hijos que "
        "tiene el nodo n.\n\tRequiere: Un árbol A inicializado, no vacío y un "
        "nodo distinto a nodo nulo.\n\tModifica: N/A.\n\n\n\nMANUAL DE "
        "ALGORITMOS:\n\nHermanoIzq(Arbol A, Nodo n) -> Nodo\n\tEfecto: "
        "Devuelve "
        "el "
        "hermano izquierdo del nodo n. Si no tiene hermano devuelve nodo nulo. "
        "\n\tRequiere: Un árbol A inicializado no vacío y un nodo n válido en "
        "A.\n\tModifica: N/A\nEtiqRepetidas(Arbol A) -> bool\n\tEfecto: "
        "Averigua "
        "si el árbol tiene etiquetas repetidas. Devuelve verdadero si las "
        "tiene, "
        "falso en caso contrario. \n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: N/A \nAlturaNodoPreOrden(Arbol A, Nodo n) "
        "-> "
        "int \n\tEfecto: Devuelve la altura del nodo n en el arbol A haciendo "
        "un "
        "recorrido en preorden. Dicha altura es devuelta como un entero. "
        "\n\tRequiere: Un árbol A inicializado no vacío y un nodo n válido en "
        "A. "
        "\n\tModifica: N/A \nProfundidadNodo(Arbol A, Nodo n) -> int "
        "\n\tEfecto: "
        "Devuelve la profundidad del nodo n en el arbol A. Dicha profundidad "
        "es "
        "devuelta como un entero. \n\tRequiere: Un árbol A inicializado no "
        "vacío "
        "y "
        "un nodo n válido en A. \n\tModifica: N/A \nCantNivelesPreOrden(Arbol "
        "A) "
        "-> int \n\tEfecto: Devuelve la cantidad de niveles del árbol haciendo "
        "un "
        "recorrido en preorden. Dicha cantidad es devuelta como un entero. "
        "\n\tRequiere: Un árbol A inicializado.\n\tModifica: "
        "N/A\nCantNivelesPorNiveles(Arbol A) -> int\n\tEfecto: Devuelve la "
        "cantidad de niveles del árbol haciendo un recorrido por niveles. "
        "Dicha "
        "cantidad es devuelta como un entero.\n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: N/A \nListarIesimoNivel(Arbol A, int "
        "i)\n\tEfecto: Lista o imprime las "
        "etiquetas del árbol A en el nivel i.\n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: N/A \nListarPreOrden(Arbol A)\n\tEfecto: "
        "Lista o "
        "imprime las etiquetas del árbol A haciendo un recorrido en "
        "preorden.\n\tRequiere: Un árbol A inicializado.\n\tModifica: N/A "
        "\nListarPorNiveles(Arbol A)\n\tEfecto: Lista o imprime las etiquetas "
        "del "
        "árbol A haciendo un recorrido por niveles.\n\tRequiere: Un árbol A "
        "inicializado.\n\tModifica: N/A \nBuscarEtiq(Arbol A, Etiqueta e) -> "
        "Nodo\n\tEfecto: Busca la etiqueta e en el arbol A y devuelve el nodo "
        "asociado con la misma. Si no hay nodo asociado con dicha etiqueta "
        "devuelve nodo nulo.\n\tRequiere: Un árbol inicializado.\n\tModifica: "
        "N/A "
        "\nBorrarSubArbol(Arbol A, Nodo n)\n\tEfecto: Borra el subárbol que se "
        "genera a partir del nodo n, toma dicho nodo n como raíz del subárbol "
        "a "
        "borrar.\n\tRequiere: Un árbol inicializado no vacío y un nodo n "
        "válido "
        "en "
        "A.\n\tModifica: El árbol A.\nListarHijos(Arbol A, Nodo n)\n\tEfecto: "
        "Lista "
        "o imprime todos los hijos del nodo n en el árbol A.\n\tRequiere: Un "
        "árbol "
        "inicializado no vacío y un nodo n válido en A. \n\tModifica: N/A \n";
    std::cout << reglas;
    std::cin.get();
    system("clear");
}

void Interfaz::probarAlg(Arbol *&arbol) {
    Algoritmos algs;
    int opcion = -1;
    char etiqueta1 = ' ';
    int enteroAux = 0;
    while (opcion != 0) {
        this->mostrarAlgoritmosArbol();
        opcion = this->getOpcion();
        Arbol::Node nodoActual;
        switch (opcion) {
        case 1:
            std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De "
                         "cúal nodo quieres saber su hermano izquierdo?: ";
            std::cin >> etiqueta1;
            nodoActual = algs.HermanoIzq(arbol, arbol->getNodo(etiqueta1));
            std::cout << "El hermano izquierdo del nodo " << etiqueta1
                      << " es: ";
            if (nodoActual != arbol->NodoNulo) {
                std::cout << arbol->Etiqueta(nodoActual);
            } else {
                std::cout << "nodo nulo";
            }
            break;

        case 2:
            if (algs.EtiqRepetidas(arbol)) {
                std::cout << "El arbol tiene etiquetas repetidas" << std::endl;
            } else {
                std::cout << "El arbol NO tiene etiquetas repetidas"
                          << std::endl;
            }
            break;

        case 3:
            std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De "
                         "cúal nodo quieres saber su altura?: ";
            std::cin >> etiqueta1;
            std::cout << "La altura del nodo " << etiqueta1 << " es: "
                      << algs.AlturaNodoPreOrden(
                             arbol, arbol->getNodo(etiqueta1));
            break;

        case 4:
            std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De "
                         "cúal nodo quieres saber su profundidad?: ";
            std::cin >> etiqueta1;
            std::cout << "La profundidad del nodo " << etiqueta1 << " es: "
                      << algs.ProfundidadNodo(arbol, arbol->getNodo(etiqueta1));
            break;

        case 5:
            std::cout << "La cantidad de niveles del arbol por PREORDEN es: "
                      << algs.CantNivelesPreOrden(arbol);
            break;

        case 6:
            std::cout << "La cantidad de niveles del arbol por PORNIVELES es: "
                      << algs.CantNivelesPorNiveles(arbol);
            break;

        case 7:
            std::cout
                << "Digita el nivel del arbol que deseas que sea listado: ";
            std::cin >> enteroAux;
            algs.ListarIesimoNivel(arbol, enteroAux);
            break;

        case 8:
            algs.ListarPreOrden(arbol);
            break;

        case 9:
            algs.ListarPorNiveles(arbol);
            break;

        case 10:
            std::cout << "Digite la etiqueta que quiere buscar: ";
            std::cin >> etiqueta1;
            std::cout
                << "El nodo asociado es (direccion de memoria si su Estructura "
                   "esta en memoria dinamica o un entero en caso contrario)"
                << algs.BuscarEtiq(arbol, etiqueta1);
            break;

        case 11:
            std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿Cual "
                         "nodo quieres tomar como raiz para iniciar el borrado "
                         "del subarbol?: ";
            std::cin >> etiqueta1;
            algs.BorrarSubArbol(arbol, arbol->getNodo(etiqueta1));
            std::cout << "SUBARBOL BORRADO";
            break;

        case 12:
            std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De "
                         "cual nodo quieres listar sus hijos?: ";
            std::cin >> etiqueta1;
            algs.ListarHijos(arbol, arbol->getNodo(etiqueta1));
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        system("clear");
    }
}
