/*
Daniel Cruz Arciniega
A01701370

Actividad Integral 2

Lectura de bitácora de ventas
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "list.h"

using namespace std;

void menu(){
	cout << "Opcion 1: leer archivo y almacenar datos en una lista ligada" << endl;
	cout << "Opcion 2: imprimir los datos de la lista en la consola" << endl;
	cout << "Opcion 3: buscar por fecha de compra" << endl;
	cout << "Opcion 4: escribir datos en nuevo archivo de texto" << endl;
	cout << "Opcion 5: salir" << endl;
}

/*
Función para casos prueba
Con esta función demuestro la competencia SICT0301B de casos prueba
*/
void pruebas(){
	List<string> prueba; 
	
	cout << "CASOS PRUEBA \n";
	cout << "Nombre de archivo incorrecto: "; prueba.lee("archivo_incorrecto.txt");
	cout << "Cargar archivo e imprimir elementos en la consola: \n"; prueba.lee("ventas.txt"); prueba.imprime();
	cout << "Buscar un elemento que no esta en la lista: " << prueba.find("00/00");
	cout << "Encuentra el dia 10 de junio: \n" << prueba.find("06/10") << endl;
	cout << "Encuentra el dia 11 de mayo: \n" << prueba.find("05/11") << endl;
	cout << "Encuentra el dia 21 de diciembre: \n" << prueba.find("12/21") << endl;
	cout << "Escribir datos en un nuevo archivo .txt (revisar carpeta) \n"; prueba.escribe();
	cout << "Borrar todos los elementos de la lista para que no afecten la memoria \n"; prueba.borrar();
}

int main(){
	int opcion = 0;
	string n, archivo;
	List<string> lista;
	
	menu();
	while(opcion <5 && opcion >-1){
      cout << "Introduce opcion: \n";
	  cin >> opcion;

      switch(opcion){
		  case 1:
			 cout << "Introduce el nombre del archivo: \n";
			 cin >> archivo;	
			 lista.lee(archivo);
			 break;
			 
		  case 2:
			 lista.imprime();
			 break;
			 
		  case 3:
			 cout << "introduce la fecha de la compra (mm/dd): \n";
			 cin >> n;
			 cout << lista.find(n) << endl; 
			 break;	
		  
		  case 4:
			 lista.escribe();
			 break;
		}
	}
	
	lista.borrar();
	
	pruebas();
	
	return 0;
}