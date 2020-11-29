/*
Daniel Cruz Arciniega
A01701370

Actividad Integral
Entregas finales

Lectura de bitácora de ventas
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "logs.h"
#include "hash.h"

using namespace std;

/*
Funciones para Hash

Crea un nuevo vector con los nombres de los productos como strings
Contiene un ciclo for anidado que se repite el doble de veces que los elementos del vector
en el peor de los casos. Complejidad O(n^2)
*/
vector<string> producto(vector<string> dta,int n){
	vector<string> str;
	string line;
	
	for (int i = 0; i<dta.size(); i++){
		line = "";
		for (int j = 0; j<dta[i].length()-n-1; j++)
			line += dta[i][n+j];
		str.push_back(line);
	}
	return str;
}

/*
Crea un vector con los ID's de producto como strings
Complejidad O(n) ya que se recorre todo le vector data
*/
vector<string> id(vector<string> dta, int n){
	vector<string> vid;
	string line;
	
	for (int i = 0; i<dta.size(); i++){
		line = "";
		
		line += dta[i][n];
		line += dta[i][n+1];
		line += dta[i][n+2];
		line += dta[i][n+3];
		line += dta[i][n+4];
		line += dta[i][n+5];
		
		vid.push_back(line);
	}
	return vid;
}

/*
Devuelve la palabra recibida en su codigo ascii en forma de int
Complejidad O(n) ya que se recorre una por una cada letra de la palabra recibida
*/
unsigned int myHash(const string s){
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

//introduce todos los ID's y productos en una tabla Hash. O(n).
void create_hash(vector<string> vk, vector<string> vv, int size, Hash<string, string> &hash) {
	for (int i = 0; i<size; i++)
		hash.put(vk[i], vv[i]);
}

/* 
Lectura de archivo
Leer el archivo de texto
Esta función  utiliza un ciclo while dentro de un condicional if que se repite el mismo número de elementos que 
contenga la lista en el peor de los casos, por lo cual es O(n).
 */
int lee(string file, vector<string> &data){
	string line;
	int size;
	
	ifstream lee(file);
	if (lee.is_open()){
		while (getline(lee, line, '\n')){
			data.push_back(line);
			size++;
		}
		
		lee.close();
	}
	else{
		cout << "Unable to open file";
    }
	return size;
}

void menu(){
	cout << "Opcion 1: imprimir heap por fecha" << endl;
	cout << "Opcion 2: imprimir heap por hora" << endl;
	cout << "Opcion 3: imprimir heap por peso" << endl;
	cout << "Opcion 4: imprimir heap por precio" << endl;
	cout << "Opcion 5: pop" << endl;
	cout << "Opcion 6: imprimir datos originales en consola" << endl;
	cout << "Opcion 7: imprimir hash del producto" << endl;
	cout << "Opcion 8: bucar valor en el hash" << endl;
	cout << "Opcion 9: escribir un nuevo archivo ordenado" << endl;
	cout << "Opcion 10: salir" << endl;
}

int main(){
	int opcion = 0;
	string file, tipo, pd;
	vector<string> data;
	
	cout << "Introduzca el nombre del archivo de donde se extraeran los datos: ";
	cin >> file;
	
	int sze = lee(file, data);
	
	Logs log(data, sze);
	Hash<string, string> hash(sze, string("empty"), myHash);
	
	//Se crean los heaps
	log.h_fecha();
	log.h_hora();
	log.h_peso();
	log.h_monto();
	
	//Se crea el hash
	create_hash(id(data, 20), producto(data, 27), sze, hash);
	
	cout <<"Los datos se han cargado satisfactoreamente. \nLos datos numericos han sido ordenados en heaps y los productos fueron ordenados en una tabla hash\n";
	
	menu();
	while(opcion <10 && opcion >-1){
      cout << "Introduce opcion: \n";
	  cin >> opcion;
		
      switch(opcion){
		  case 1:
			 tipo = "fecha";
			 log.print_h(tipo);
			 break;
		  
		  case 2:
		     tipo = "hora";
			 log.print_h(tipo);
			 break;
			 
		  case 3:
			 tipo = "peso";
			 log.print_h(tipo);
			 break;
			 
		  case 4:
			 tipo = "monto";
			 log.print_h(tipo);
			 break;
		  
		  case 5:
		     cout << "Introduce el árbol al que se le retirará el menor valor (fecha, hora, peso o monto): ";
			 cin >> tipo;
			 log.pop(tipo);
			 break;
			 
		  case 6:
		     log.print();
			 break;
		  
		  case 7:
			 cout << hash.toString();
			 break;
			 
		  case 8:
		     cout << "introduce el ID del producto que desea buscar: ";
			 cin >> pd;
			 cout << pd << ": " << hash.get(pd) << endl;
			 break;
		  
		  case 9:
			 cout << "Escribe el orden en el que se desea escribir el archivo (fecha, hora, peso o monto): ";
			 cin >> tipo;
		     log.escribe(tipo);
			 hash.escribe();
			 cout << "Se han guardado los datos del heap y del hash en 2 archivos de texto. \nRevisar carpeta.\n";
			 break;
		}
	}
	
	log.clear();
	hash.clear();
	
	return 0;
}