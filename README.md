# Actividades Integradoras
## Actividad integradora 1
### Descripción
En este proyecto tengo la intención de crear un programa que lea los registros del día de la caseta de vigilancia de un fraccionamiento.
En la bitácora se registra la hora de entrada, el nombre de la persona, la dirección a la que se dirige la persona y el motivo de la visita.
Esta entrega es solo un avance del proyecto, el cual en cada entrega irá adquiriendo más complejidad. 
### Análisis de complejidad
La función lee() tiene un ciclo while, lo que hace que se repita el mismo número de lineas que tenga el archivo de texto, lo que hace que sea O(n) en el peor de los casos.
La función ordena() utiliza el método bubble de ordenamiento, por lo cual su complejidad es de O(n^2) en el peor de los casos porque contiene un ciclo anidado.
La función escribe() tiene un ciclo for que se repite las mismas veces que los elementos que hay en el vector en el que se almacenaron los datos, esto quiere decir que su complejidad es de O(n) en el peor de los casos.
