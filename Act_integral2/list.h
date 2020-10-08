#ifndef List_H_
#define List_H_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

template <class T> class List;

//Clase link para enlazar la lista
template <class T> 
class Link{
	private:
	Link(T);
	Link(T, Link<T>*);
	
	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}


//Clase list para leer y almacenar el archivo en una lista ligada
template <class T> 
class List{
	public:
		List();
		List(const List<T>&);
		
		bool empty() const;
		void lee(string);
		void add(T);
		//void ordena();
		string find(T);
		void imprime();
		void escribe();
		
		void borrar();
		
	private:
		//Atributos de la lista
		Link<T> *head;
		int size;
		
		//Función para crear un vector de strings con las fechas
		vector<T> new_vec();
		
		/* Funciones para el ordenamiento
		void swap(Link<T>*);
		void swap_vec(vector<int>&,int,int);
		*/
};

//Constructor
template <class T>
List<T>::List() : head(0), size(0) {}

//Función para saber si la lista está vacía. Complejidad O(1)
template <class T>
bool List<T>::empty() const{
	return (head == 0);
}

/*
Leer el archivo de texto
Esta función  utiliza un ciclo while dentro de un condicional if que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
*/
template <class T>
void List<T>::lee(string file){
	string line;
	
	ifstream lee(file);
	if (lee.is_open()){
		while (getline(lee, line, '\n')){
			add(line);
		}
	}
	else{
		cout << "Nombre de archivo invalido \n";
	}	
}

/*
Agregar valores a la lista
Esta función  utiliza un ciclo while que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
*/
template <class T>
void List<T>::add(T line){
	Link<T> *newLink, *p;
	
	newLink = new Link<T>(line);
	
	if(empty()){
		newLink->next = head;
		head = newLink;
		size++;
		return;
	}
	
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	
	newLink->next = 0;
	p->next = newLink;
	size++;
}

/* Funciones de ORDENAMIENTO que serán implementadas en un futuro

//Cambia los elementos de lugar
template <class T>
void List<T>::swap(Link<T> i, Link<T> j){
	Link<T> *aux = p;	
	
	if (p == head){
		aux = p;
		head = p->next;
		p->next = aux;
		return;
	}
	
	aux = p;
	p = p->next;
	p->next = aux;

}

template <class T>
void List<T>::swap_vec(vector<int> &v,int i,int j){
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//Ordena la lista por fecha
template <class T>
void List<T>::ordena(){
	vector<int> v;
	new_vec(v);
	Link<T> *p;
	p = head;
	
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < size; j++) {
			if (v[j] > v[j + 1]) {
				swap(p, p->next);
				swap_vec(v, j, j+1);
			}
		}
	}
}
*/

/* 
Busca un atributo en la lista y devuelve el valor del elemento en la lista como string
El atributo será la fecha de entrega 
Con esta función demuestro la competencia SICT0302B de algoritmos de búsqueda
La función new_vec() utiliza un ciclo while por lo que es de complejidad O(n).
La función de find() utiliza un ciclo while que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
*/
template <class T>
string List<T>::find(T val){
	if (empty()){
		return "No se ha cargado ningun archivo";
	}
	
	vector<string> data = new_vec();
	
	int pos = 0;
	Link<T> *p;
	
	p = head;
	while(p != 0){
		if (data[pos] == val){
			cout << "Fecha (mm/dd) | Hora (hh:mm) | Peso (kg) | Producto | Monto $ \n";
			return p->value;
		}
		p = p->next;
		pos++;
	}
	
	return "No se ha encontrado el elemento \n";
}

//Crea un nuevo vector con las fechas como enteros (mm/dd)
template <class T>
vector<T> List<T>::new_vec(){
	Link<T> *x = head;
	vector<string> v;
	string line, data;
	
	while(x != 0){
		line = "";
		data = x->value;
		
		line += data[0];
		line += data[1];
		line += data[2];
		line += data[3];
		line += data[4];
		
		v.push_back(line);
		
		x = x->next;
	}
	
	return v;
}

/*
Imprime los elementos de la lista en la consola
Esta función  utiliza un ciclo while que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
*/
template <class T>
void List<T>::imprime(){
	Link<T> *p;
	p = head;
	
	cout << "Fecha (mm/dd) | Hora (hh:mm) | Peso (kg) | Producto | Monto $ \n";
	while(p != 0 ){
		cout << p->value << endl;
		p = p->next;
	}
}

/*
Escribe los elementos de la lista en un nuevo archivo .txt
Esta función  utiliza un ciclo while dentro de un condicional if que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
*/
template <class T>
void List<T>::escribe(){
	Link<T> *q;
	q = head;
	
	if(empty()){
		cout << "No se ha cargado ningún archivo \n";
		return;
	}
	
	ofstream escribe("orden.txt");
	if(escribe.is_open()){
		escribe << "Fecha (mm/dd) | Hora (hh:mm) | Peso (kg) | Producto | Monto $ \n";
		while(q != 0){
			escribe << q->value;
			q = q->next;
		}
		escribe.close();
	}
	else{
		cout << "Unable to open file";
	}
}

template <class T>
void List<T>::borrar(){
	Link<T> *p;
	p = head;
	
	while(p != 0 ){
		delete p;
		p = p->next;
	}
}

#endif /* List_H_ */ 