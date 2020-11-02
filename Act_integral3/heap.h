#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "logs.h"

using namespace std;

template <class T>
class Heap {
private:
	T *h_data;
	string data[50];
	unsigned int size;
	unsigned int count;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);
	
public:
	Heap(unsigned int);
	~Heap();
	bool empty() const;
	bool full() const;
	void push(T, string);
	void pop();
	void clear();
	string toString() const;
	
	friend class Logs;
};

template <class T>
Heap<T>::Heap(unsigned int sze){
	size = sze;
	h_data = new T[size];
	count = 0;
}
template <class T>
Heap<T>::~Heap() {
	delete [] h_data; h_data = 0;
	size = 0; count = 0;
}
template <class T>
bool Heap<T>::empty() const {
	return (count == 0);
}
template <class T>
bool Heap<T>::full() const {
	return (count == size);
}
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = h_data[i];
	string aux2 = data[i];
	
	h_data[i] = h_data[j];
	h_data[j] = aux;
	
	data[i] = data[j];
	data[j] = aux2;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && h_data[le] < h_data[min]) {
		min = le;
	}
	if (ri <= count && h_data[ri] < h_data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

/*
Esta función agrega datos en el árbol a la izquierda o a la derecha de la raíz 
Es de complejidad O(log(n)) ya que el árbol se va dividiendo y los pasos se repiten 
solo si el dato agregado es mayor que el primer dato del árbol.
*/
template <class T>
void Heap<T>::push(T val, string val2) {
	unsigned int pos;
	pos = count;
	count++;
	
	while (pos > 0 && val < h_data[parent(pos)]) {
		h_data[pos] = h_data[parent(pos)];
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	h_data[pos] = val;
	data[pos] = val2;
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}

/*
Pop llama a la función heapify() la cual es recursiva si se cumple con la condición
En el peor de los casos se repite el mismo número de veces que los datos de la fila de prioridad, 
por lo que es de complejidad O(log(n)).
*/
template <class T>
void Heap<T>::pop(){
	T aux = h_data[0];
	h_data[0] = h_data[--count];
	heapify(0);
}

/* 
toString 
Se guardan todos los elementos del arbol en un string
Complejidad O(n)
*/

template <class T>
string Heap<T>::toString() const {
	stringstream aux;
	for (unsigned int i = 0; i < count; i++) {
		aux << data[i];
		aux << "\n";
	}
	return aux.str();
}


#endif /* HASH_H_ */
	