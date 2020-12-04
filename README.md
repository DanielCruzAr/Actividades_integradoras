# Actividades Integradoras
## Estructura
Las actividades integrales son diferentes, especialmente las primeras en las que quería realizar una bitácora de la caseta de vigilancia de un fraccionamiento.
A partir de la Actividad Integral 2 decidí cambiar los datos a un registro de ventas de una empresa que vende alimento para mascota.
De la actividad integral 2 a la 6 son mejoras de la actividad integral 2, siendo la 1 la única totalmente diferente.
### Actividad Integral 1
**Comp:** SICT0302B 1.
En este proyecto tengo la intención de crear un programa que lea los registros del día de la caseta de vigilancia de un fraccionamiento.
En la bitácora se registra la hora de entrada, el nombre de la persona, la dirección a la que se dirige la persona y el motivo de la visita.
Esta entrega es solo un avance del proyecto, el cual en cada entrega irá adquiriendo más complejidad. 
Se incluyeron algoritmos de búsqueda para resolver un problema.
### Actividad Integral 2
**Comp:** SICT0302B 2
En esta entrega se cambio de los registros de la caseta de vigilancia a los registros de ventas del año de una empresa que vende alimento para perro debido a que 
me sería más fácil analizar estos datos.
Los datos se ordenaron en una lista ligada.
### Actividad Integral 3
**Comp:** SICT0302B 3
Se incluyó un árbol heap para ordenar los datos del archivo de ventas.
### Actividad Integral 4
Considerando que solo necesito 4 de 6 subcompetencias para acreditar la competencia SICT0302B decidí no implementar grafos ya que mi proyecto no los requería.
### Actividad Integral 5
**Comp:** SICT0302B 6
Se implementaron hashes.
### Actividad Integral 6
Proyecto completo. 

**Comp:** Se implementaron disjoint sets como estructura extra, la cual viene explicada a detalle en el README de la actividad y en el código para validar la competencia 
SEG0702A Tecnologías de vanguardia. 

**Comp:** Los casos prueba se introdujeron en un archivo .cpp para la competencia SICT0301B de casos prueba.
## Correcciones
### Actividad integral 4
**Corrección:** Al compilar el código marcaba el error: 

*In file included from hash.h:6:
logs.h:31:3: error: 'Hash' does not name a type
   31 |   Hash<string, int> prod;
      |   ^~~~
hash.h:17:7: error: expected ';' at end of member declaration
   17 |   Key keys;
      |       ^~~~
      |           ;
hash.h:17:12: error: expected unqualified-id before ';' token
   17 |   Key keys*;
      |            ^*

Decidí entonces subir los archivos de la entrega final ya que ahí ya compila el problema en su totalidad.
