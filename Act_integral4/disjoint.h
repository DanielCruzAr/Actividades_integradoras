/*
Competencia a evaluar SEG0702A Tecnologias de vanguardia
Disjoint Sets
Daniel Cruz Arciniega A01701370
*/
#ifndef DISJOINT_H_
#define DISJOINT_H_

#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*
Creamos la clase Dj
Como voy a implementarla utilizando un vector de strings decidi tener 2 templates, 
uno para la lista de parent que en mi proyecto la implementare como int, y otro para el vector que recibira que sera de strings.
Parent guarda los valores de las uniones que se hagan. En este arreglo el elemento i representa el padre de la posicion i.
Ejemplo: si se hace una union de 1 con 2 en un arreglo de 3 elementos, el arreglo en la posicion 1 tendra un valor de 2 de la siguiente manera
[-1][2][-1]  De esta forma podemos saber que el 2 pertenece al set del 1 
 0  1   2
*/
template <class T, class U>
class Dj {
	
	private:
		T *parent; 
		vector<U> logs;
		unsigned int size;
		
	public:
		Dj(vector<U> , unsigned int);
		~Dj();
		void Union(T, T);
		int find(T);
		int numSets();
		string toString();
};

/*
En el constructor se recibe un vector de clase U y un entero que sera el tamaño del arreglo
El arreglo de parent se llena de -1. La cantidad de -1 que haya sera la cantidad de disjoint sets
*/
template <class T, class U>
Dj<T, U>::Dj(vector<U> v, unsigned int sze)  {
	size = sze;
	logs = v;
	parent = new T[size];
	for (int i = 0; i < size; i++)
		parent[i] = -1;
}
//Destructor
template <class T, class U>
Dj<T, U>::~Dj() {
	delete [] parent;
	parent = 0;
	size = 0;
}

/*
La funcion find utiliza recursion para encontrar el set al que pertenece el valor dado
Si el arreglo parent en la posicion del valor es -1 significa que el set esta libre en esa posicion y devuelve el valor
Si no se busca el padre del valor que haya dentro de la posicion y hasta que esta sea -1 la funcion se repite
Es un algoritmo muy rapido ya que busca el elemento exacto en el arreglo, por lo cual podria decirse que en la mayoria 
de los casos es de complejidad O(log(n)) ya que en su mayoria el arreglo no se recorrera en su totalidad
*/
template <class T, class U>
int Dj<T, U>::find(T val) {
	if (parent[val] == -1)
		return val;
	return find(parent[val]);
}

/*
Union recibe 2 elementos y busca sus sets correspondientes con la funcion find() para despues colocar en el arreglo parent 
en la posicion del primer elemento la posicion del segundo elemento
Ejemplo: Si tenemos un arreglo de 4 elelemtos 
[-1][-1][-1][-1]
  0   1   2   3
Si hacemos una union de 0 con 2 (Union(0,2))
	pa va a ser igual al resultado de find(0)
		find(0) 
		parent[0] == -1 ---> true
		find(0) = 0
	pb va a ser igual al resultado de find(2)
		find(2)
		parent[2] == -1 ---> true
		find(2) = 2
	parent[0] = 2
por lo que el arreglo queda [2][-1][-1][-1]	
                             0   1   2   3
Esta funcion es de complejidad O(1) ya que solo se realiza 1 vez.
*/
template <class T, class U>
void Dj<T, U>::Union(T a, T b) {	
	int pa = find(a);
	int pb = find(b);
	parent[pa] = pb;
}

/*
numSets regresa la cantidad de disjoint sets que hay en parent
Cada -1 en parent es un set
Complejidad O(n), se recorre todo el arreglo 
*/
template <class T, class U>
int Dj<T, U>::numSets() {
	int n = 0;
	for (int i = 0; i < size; i++){
		if (parent[i] == -1)
			n++;
	}
	return n;
}

/*
A cada elemento del vector logs le corresponde un numero que va de 0 a size.
Se imprimen los indices de 0 a size con su respectivo padre.
Si el indice no tiene padre, es decir, vale -1, significa que es el elemento representativo del set
y se imprime el valor de logs en la posicion del indice i.
De lo contrario quiere decir que hay mas elementos en el set,
se imprime el valor de logs en la posicion del padre del indice i.
Complejidad O(n), se recorre todo el arreglo
NOTA: al decir que se imprime quiere decir que se guarda en el string de aux para despues imprimirse cuando
      se llame a la funcion.
*/
template <class T, class U>
string Dj<T, U>::toString() {
	stringstream aux;
	
	for (int i = 0; i < size; i++){
		aux << i << ": " << "parent = "<< parent[i] << ", "; 
		if (parent[i] == -1)
		    aux << logs[i] << "\n";
		else
			aux << logs[parent[i]] << "\n";
	}
	return aux.str();
}

#endif