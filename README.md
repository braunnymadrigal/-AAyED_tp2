# TP2  AAyED UCR 2023 Manual de Usuario

Estudiantes: Keylor Palacios C25770 / Braunny Madrigal C24436

## Proyecto GIT: https://github.com/braunnymadrigal/AAyED_tp2.git

## ¿Cómo compilar y correr?
1. Abrir el archivo "algoritmos.hh" y elegir la estructura de grafo con la que se desea usar el programa, se debe comentar la otra estructura.
2. Abrir el archivo “main.cc” y elegir si se quiere usar la instancia "interfaz" o "pruebas". Basta con comentar aquello que no se desea usar y dejar sin comentar aquello que sí. Elegir entre objeto "Pruebas" u objeto "Interfaz".
3. Ir al archivo makefile y elegir si compilar con "grafoMatriz.cc" o "grafoLista.cc". Basta con comentar la linea que contenga el que no desea utilizar y dejar sin comentar la otra.
4. Abrir shell en el directorio principal del proyecto.
5. Compilar: escribir "make" en la consola.
6. Ejecutar: escribir "./programa" en la consola.

## ¿Cómo se usa?
1. Ejecuta el programa.
2. Si se decide usar el objeto interfaz. El programa va a consistir de un menú principal que le permite manipular el grafo a través de sus operadores básicos y algoritmos. La propia interfaz le indica cómo moverse por los menús.
3. Si se decide usar el objeto pruebas. El programa va a consistir de una simple salida en consola que le detalla el tiempo de ejecución, de la estructura de datos escogida anteriormente y de un tamaño en particular, en 7 algoritmos y 3 tipos de grafo. En el archivo pruebas.cc, usted puede escoger de que tamaño quiere su grafo, basta con cambiar el valor de la variable "int tamano" por el tamaño que desee.

## ¿Qué funcionalidad implementa?
1. Se implementan el modelo Grafo NO dirigo, con pesos, sin aristas paralelas y sin lazos por las estructuras de datos “Matriz de Adyacencia” y “Lista de Adyacencia”.
2. Se implementan todos los algoritmos que se detallan en el archivo pdf de documentación. Tales que los algoritmos funcionan independientemente de la estructura de datos a utilizar.
3. Se implementa una interfaz que le permite manipular el modelo grafo a su antojo mediante el uso de menús simples. 
4. Se implementa una clase pruebas que es capaz de construir grafos de forma automática y testearlos en distintos algoritmos. Es capaz de imprimir los tiempos que los grafos duran en ciertas pruebas específicas.

## ¿Que no fue implementado? 
Todos los casos fueron implementados y contemplados.

## Errores Conocidos:
Ninguno.

## Arquitectura del programa: 
1. Estructuras de datos implementadas en archivos .hh y archivos .cc. En los .hh únicamente se encuentran las firmas de los métodos y la declaración de aquello que se requiera para los .cc.
2. Algoritmos del grafo implementados en dos archivos, uno .cc y otro .hh. En el .hh únicamente se encuentran las firmas de los métodos.
3. Interfaz implementada en dos archivos, uno .cc y otro .hh. En el .hh únicamente se encuentran las firmas de los métodos. El archivo main.cc solo se encarga de crear una instancia de la interfaz y llamarla. 
4. Pruebas implementada en dos archivos, uno .cc y otro .hh. En el .hh únicamente se encuentran las firmas de los métodos. El archivo main.cc solo se encarga de crear una instancia de la pruebas y llamarla. 
5. Archivo main, implementado en un único archivo main.cc.
6. Archivo makefile que le permite compilar de forma sencilla. 

## Especificación de las funciones del programa:
1. Navegar en menús.
2. Usar operadores básicos a través de un menú (hace traducciones de etiqueta a vértice y viceversa).
3. Usar algoritmos del grafo NO dirigido, con pesos, sin aristas paralelas y sin lazos a través de un menú (hace traducciones de etiqueta a vértice y viceversa).
4. Ver la eficiencia en tiempo de una estructura de datos del modelo grafo en distintas pruebas. En cada prueba se muestra su rendimiento para distintos tipos de grafo.
