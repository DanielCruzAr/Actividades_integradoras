## Competencia SEG0702A Tecnologías de Vanguardia
La estructura de disjoint sets consiste en crear diferentes sets de datos dado un arreglo de datos
Esta estructura que realiza un seguimiento de un conjunto de elementos divididos en un número de subsets.
Esta estructura de datos está commpuesta de dos algoritmos fundamentales: union y find.
Union junta dos subsets en uno solo y find en qué subset se encuentra un elemento en particular.
Algunos de los usos que se les da comunmente a los disjoint sets son detectar ciclos en otras estructuras como grafos, separar datos repetidos, etc.
Ejemplo: para detectar un ciclo dentro de un grafo si dirigir considerando en siguiente grafo:

![Graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Cycle-in-graph.png)

### Uso de disjoint sets en mi actividad integral
En mi proyecto utilicé disjoint sets para separar los productos de adulto que habían en mi archivo de texto. 
Los datos se pueden separar en arreglos o en árboles, yo use arreglos por la razón de que es más sencillo.
La explicación a detalle de cómo funcionan los disjoint sets se ecuentra en el archivo disjoint.h así como algunos ejemplos de su fucnionamiento.
## Competencia SICT0301B Casos prueba
Los casos prueba de heap.h, hash.h y disjoint.h se encuentran en el archivo pruebas.cpp para validar la competencia SICT0301B en su totalidad.
