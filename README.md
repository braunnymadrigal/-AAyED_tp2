# TP2  AAyED UCR 2023 Manual de Usuario

Estudiantes: Keylor Palacios C25770 / Braunny Madrigal C24436

## Proyecto GIT: https://github.com/braunnymadrigal/AAyED_tp2.git

## ¿Cómo compilar y correr?
1. Abrir el archivo "algArbol.hh" y elegir la estructura del árbol con la que se desea ejecutar las pruebas, se deben comentar las otras 3 estructuras de datos.
2. Abrir el archivo “main.cc” y elegir si se quiere los operadores y algoritmos del árbol o hacer un análisis de tiempos. Basta con comentar aquello que no se desea usar y dejar sin comentar aquello que sí. Elegir entre objeto Tiempos u objeto Interfaz.
3. Abrir shell en el directorio principal del proyecto
4. a) Para compilar puede: ejecutar el comando de la siguiente manera "g++ main.cc interfaz.cc algArbol.cc tiempos.cc  -o algoritmos"
4. b) Para compilar puede: escribir make compile en la consola
5. Ejecutar el comando ./algoritmos para correrlo

## ¿Cómo se usa?
1. Ejecuta el programa.
2. Si se decide usar el objeto interfaz. El programa va a consistir de un menú principal que le permite manipular el árbol a través de sus usar operadores básicos del árbol y algoritmos. La propia interfaz le indica cómo moverse por los menús.
3. Si se decide usar el objeto tiempos. El programa va a consistir de una simple salida en consola que le detalla todos los tiempos analizados con distintas especificaciones para la estructura de datos escogida anteriormente. En el archivo tiempos.cc, el el método encargado de testear el algoritmo “ListarHijos” que crea un archivo para la salida existe una línea de código que se encarga de cerrar el archivo utilizado pero esta línea depende del sistema operativo utilizado por lo que se debe comprobar que dicha línea esté de acuerdo a sus sistema; “freopen("/dev/tty", "w", stdout);” para linux y “freopen("CON", "w", stdout);” para windows.

## ¿Qué funcionalidad implementa?
1. Se implementan el modelo Árbol n-ario tal que si importa el orden entre los hijos de un nodo por las estructuras de datos “Lista de Listas”, “Arreglo con Señalador al Padre”, “Hijo Más Izquierdo Hermano Derecho” y “Hijo Más Izquierdo Hermano Derecho tal que el hermano derecho del hijo más derecho es el padre”.
2. Se implementa el modelo Cola por la estructura de datos “Lista Simplemente Enlazada”.
3. Se implementan todos los algoritmos que se detallan el archivo pdf de documentación. Tales que los algoritmos funcionan independientemente de la estructura de datos a utilizar.
4. Se implementa una interfaz que le permite manipular el modelo árbol a su antojo mediante el uso de menús simples. 
5. Se implementa una clase tiempos que es capaz de construir árboles de forma automática y testearlos en distintos algoritmos. Es capaz de imprimir los tiempos que los árboles duran en ciertas pruebas específicas.

## ¿Que no fue implementado? 
Todos los casos fueron implementados y contemplados.

## Errores Conocidos:
Ninguno.

## Arquitectura del programa: 
1. Estructuras de datos implementadas enteramente en archivos .hh. Decisión tomada pensando en cómo las estructuras de datos en la librería estándar de C++ están implementadas. 
2. Algoritmos del árbol implementados en dos archivos, uno .cc y otro .hh. En el .hh únicamente se encuentran las firmas de los métodos.
3. Interfaz implementada en dos archivos, uno .cc y otro .hh. En el .hh únicamente se encuentran las firmas de los métodos. El archivo main.cc solo se encarga de crear una instancia de la interfaz y llamarla. 
4. Tiempos de prueba implementada en dos archivos, uno .cc y otro .hh. En el .hh únicamente se encuentran las firmas de los métodos.
5. Archivo main, implementado en único archivo main.cc.
6. Archivo makefile que le permite compilar de forma sencilla. 

## Especificación de las funciones del programa:
1. Navegar en menús.
2. Usar operadores básicos a través de un menú (hace traducciones de etiqueta a nodo y viceversa).
3. Usar algoritmos del árbol n-ario tal que si importa el orden entre los hijos de un nodo a través de un menú (hace traducciones de etiqueta a nodo y viceversa).
4. Ver la eficiencia en tiempo de una estructura de datos del modelo árbol en distintas pruebas. En cada prueba se muestra su rendimiento para distintos tipos de árbol, dicho rendimiento es mostrado para caso promedio y peor si cabe el caso.

