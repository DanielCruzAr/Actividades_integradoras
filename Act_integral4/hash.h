#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include "logs.h"

using namespace std;

template <class Key, class Value>
class Hash {
	private:
		int (*func) (const Key);
		int size;
		int count;
		
		Key keys*;
		Key val0;
		Value *values;
		
		long indexOf(const Key) const;
	
	public:
		Hash(int, Key, int (*f) (const Key));
}; 

template <class Key, class Value>
HashTable<Key, Value>::HashTable(int sze, Key init, int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];
	val0 = init;
	for (unsigned int i = 0; i < size; i++)
		keys[i] = init;
	values = new Value[size];
	for (int i = 0; i  < sze; i++)
        values[i] = 0;

	func = f;
	count = 0;
}

#endif