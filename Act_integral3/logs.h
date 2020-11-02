#ifndef LOGS_H_
#define LOGS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "heap.h"

using namespace std;

const int MAX = 30; //limite de datos que tendra el arbol 

template <class T> class Heap;

class Logs{
    private:
		/*
		Se van a crear 4 objetos tipo heap
		uno por cada atributo numerico
		Fecha, Hora, Peso, Monto
		Esto quiere decir que va a haber cuatro arboles con diferente orden
		*/
		Heap<int> f;
		Heap<int> h;
		Heap<int> p;
		Heap<int> m;
		
		//Vectores de datos recuperados del archivo
		vector<string> data;
		vector<int> fecha;
		vector<int> hora;
		vector<int> peso;
		vector<int> monto;
		int size;
		
	public:
		Logs();
		bool empty() const;
		void heaps();
		vector<int> create(int);
		void datos();
		void lee(string);
		void print();
		void h_fecha();
		void h_hora();
		void h_peso();
		void h_monto();
		void pop(string);
		void print_h(string);
		void escribe(string);
		void clear();
};

/* Constructor */
Logs::Logs() : size(0), f(MAX), h(MAX), p(MAX), m(MAX) {} 

bool Logs::empty() const {
	return (size == 0);
}

/* 
Lectura de archivo
Leer el archivo de texto
Esta función  utiliza un ciclo while dentro de un condicional if que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
 */
void Logs::lee(string file){
	string line;
	
	ifstream lee(file);
	if (lee.is_open()){
		while (getline(lee, line, '\n')){
			data.push_back(line);
			size++;
		}
		
		lee.close();
		datos();
	}
	else{
		cout << "Unable to open file";
    }
}

/* 
Crea un nuevo vector con todos los datos numericos como enteros
Fecha, hora, peso, monto
Contiene un ciclo for que se repite el mismo numero de veces que el tamaño del vector en el peor de los casos
Complejidad O(n)
*/
vector<int> Logs::create(int n){
	vector<int> v;
	string line;
	int num;
	
	for (int i = 0; i<data.size(); i++){
		line = "";
		
		if (n == 17){
			line += data[i][n];
			if (data[i][n+1] != ' ')
				line += data[i][n+1];
		}
		else if (n == 12){
			line += data[i][n];
			line += data[i][n+1];
			line += data[i][n+2];
			if (data[i][n+3] != ' ')
				line += data[i][n+3];
		}
		else{
			line += data[i][n];
			line += data[i][n+1];
			line += data[i][n+3];
			line += data[i][n+4];
		}
		num = stoi(line);
		v.push_back(num);
	}
	return v;
}

void Logs::datos() {
	fecha = create(0);
	hora = create(6);	
	peso = create(17);
	monto = create(12);
}

/* 
Funcion para imrpimir los datos originales en consola
imrpime uno a uno los datos, O(n)
*/
void Logs::print(){
	cout << "Datos \n";
	for (string s : data)
		cout << s << endl;
	cout << "=============================================== \nFecha \n";
	for (int i : fecha)
		cout << i << endl;
	cout << "=============================================== \nHora \n";
	for (int i : hora)
		cout << i << endl;
	cout << "=============================================== \nMonto \n";
	for (int i : monto)
		cout << i << endl;
	cout << "=============================================== \nPeso \n";
	for (int i : peso)
		cout << i << endl;
}

/*
Funciones para crear los heaps
Se introducen uno a uno los datos del vector, O(n)
*/ 
void Logs::h_fecha(){
	if(empty()){
		cout << "No se ha cargado nigun archivo \n"; 
		return;
	}
	
	for(int i=0; i < size; i++)
		f.push(fecha[i], data[i]);
}

void Logs::h_hora(){
	if(empty()){
		cout << "No se ha cargado nigun archivo \n"; 
		return;
	}
	
	for(int i=0; i < size; i++)
		h.push(hora[i], data[i]);
}

void Logs::h_peso(){
	if(empty()){
		cout << "No se ha cargado nigun archivo \n"; 
		return;
	}
	
	for(int i=0; i < size; i++)
		p.push(peso[i], data[i]);
}

void Logs::h_monto(){
	if(empty()){
		cout << "No se ha cargado nigun archivo \n"; 
		return;
	}
	
	for(int i=0; i < size; i++)
		m.push(monto[i], data[i]);
}

/*
Funcion para eliminar el dato con el menor valor del heap
Solo se puede cumplir uno de los condicionales por lo que es constante
O(1)
*/
void Logs::pop(string type) {
	if(type == "fecha")
		f.pop();
	else if(type == "hora")
		h.pop();
	else if(type == "peso")
		p.pop();
	else if(type == "monto")
		m.pop();
	else
		cout << "Heap inexistente \n";
}

/* Impresión en consola */
void Logs::print_h(string ind){
	if (ind == "fecha")
		cout << "=============================================== \nHeap ordenado por fecha \n" << f.toString() << endl;
	else if (ind == "hora")
		cout << "=============================================== \nHeap ordenado por hora \n" << h.toString() << endl;
	else if (ind == "peso")
		cout << "=============================================== \nHeap ordenado por peso \n" << p.toString() << endl;
	else if (ind == "monto")
		cout << "=============================================== \nHeap ordenado por precio \n" << m.toString() << endl;
	else
		cout << "Heap inexistente \n";
}

/* 
Escribe los elementos de la lista en un nuevo archivo .txt
Esta función contiene condicionales por lo que es constante
O(1)
 */
void Logs::escribe(string type) {
	ofstream escribe("orden.txt");
	if(escribe.is_open()){
		escribe << "Fecha (mm/dd) | Hora (hh:mm) | Monto $ | Peso (kg) | Producto \n";
		if(type == "fecha")
			escribe << f.toString();
		else if(type == "hora")
			escribe << h.toString();
		else if(type == "peso")
			escribe << p.toString();
		else if(type == "monto")
			escribe << m.toString();
		else
			cout << "Heap inexistente \n";
		escribe.close();
	}
	else{
		cout << "Unable to open file";
	}
}


//Eliminar
void Logs::clear(){
	f.clear();
	h.clear();
	p.clear();
	m.clear();
}

#endif /* LOGS_H_ */
