#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include <fstream>

using namespace std;

template <class Key, class Value>
class Hash {
	private:
		unsigned int (*func) (const Key);
		unsigned int size;
		unsigned int count;
		
		Key *keys;
		Key val0;
		Value *values;
		
		long indexOf(const Key) const;
	
	public:
		Hash(unsigned int, Key, unsigned int (*f) (const Key));
		~Hash();
		bool full() const;
		bool put(Key, Value);
		Value get(const Key);
		void clear();
		string toString();
		void escribe();
}; 

/*
Constructor
Se guardan los parametros en los atributos privados y se crean 2 listas, 
una para llaves y otra para valores.
Para guardar las listas se usa un ciclo for que se repite 
hasta llenar la lista del tamaño recibido.
Complejidad O(n).
*/
template <class Key, class Value>
Hash<Key, Value>::Hash(unsigned int sze, Key init,unsigned int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];
	val0 = init;
	for (unsigned int i = 0; i < size; i++)
		keys[i] = init;
	values = new Value[size];
	for (int i = 0; i  < sze; i++)
        values[i] = "0";

	func = f;
	count = 0;
}

template <class Key, class Value>
Hash<Key, Value>::~Hash() {
	delete [] keys;
	keys = 0;
	delete [] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}

/*
Regresa true si la tabla esta llena
O(1)
*/
template <class Key, class Value>
bool Hash<Key, Value>::full() const{
	return (count >= size);
}

/*
Devuelve el indice en el cual se encuentra la llave
Complejidad O(n) en caso que se tenga que recorrer toda la lista
*/
template <class Key, class Value>
long Hash<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;

	start = i = func(k) % size;
	do {
		if (keys[i] == k) {
			return i;
		}
		i = (i + 1) % size;
	} while (start != i);
	return -1;
}

/*
Coloca los valores recibidos en las listas correspondientes
Complejidad O(1)
*/
template <class Key, class Value>
bool Hash<Key, Value>::put(Key k, Value v){
	unsigned int i, start;
	long pos;
	
	if (full()){
		cout << "\nTabla llena \n";
		return false;
	}
	
	pos = indexOf(k);
	if (pos != -1) {
		values[pos] = v;
		return true;
	}
	
	start = i = func(k) % size;
	do {
		if (keys[i] == val0) {
			keys[i] = k;
			values[i] = v;
			count++;
			return true;
		}
		i = (i + 1) % size;
	} while (start != i);
	return false;
}

/*
Regresa el valor de la llave recibida
Complejidad O(1)
*/
template <class Key, class Value>
Value Hash<Key, Value>::get(const Key k) {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
	return 0;
}

/*
Se borra toda la tabla
Complejidad O(n)
*/
template <class Key, class Value>
void Hash<Key, Value>::clear() {
	count = 0;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = val0;
	}
}

/*
Guarda todos los elementos de la tabla en un string
Complejidad O(n)
*/
template <class Key, class Value>
string Hash<Key, Value>::toString() {
	stringstream aux;
	
	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}

/* 
Escribe los elementos de la lista en un nuevo archivo .txt
Esta función contiene condicionales por lo que es constante
O(1)
 */
template <class Key, class Value>
void Hash<Key, Value>::escribe() {
	ofstream escribe("hash.txt");
	if(escribe.is_open()){
		escribe << "Indice | llave | valor \n";
		escribe << toString();
		escribe.close();
	}
	else{
		cout << "Unable to open file";
	}
}

#endif