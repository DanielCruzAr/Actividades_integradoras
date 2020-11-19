/*
Daniel Cruz Arciniega
A01701370

Actividad Integral 3

Lectura de bitácora de ventas
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "logs.h"

using namespace std;

void menu(){
	cout << "Opcion 1: leer archivo y almacenar datos en un vector" << endl;
	cout << "Opcion 2: ordenar datos en un heap por fecha" << endl;
	cout << "Opcion 3: ordenar datos en un heap por hora" << endl;
	cout << "Opcion 4: ordenar datos en un heap por peso" << endl;
	cout << "Opcion 5: ordenar datos en un heap por precio" << endl;
	cout << "Opcion 6: pop" << endl;
	cout << "Opcion 7: imprimir datos originales en consola" << endl;
	cout << "Opcion 8: borrar todos los heaps" << endl;
	cout << "Opcion 9: escribir un nuevo archivo ordenado" << endl;
	cout << "Opcion 10: salir" << endl;
}

int main(){
	Logs log;
	int opcion = 0;
	string file, tipo; 
	
	menu();
	while(opcion <10 && opcion >-1){
      cout << "Introduce opcion: \n";
	  cin >> opcion;

      switch(opcion){
		  case 1:
			 cout << "Introduce el nombre del archivo: \n";
			 cin >> file;	
			 log.lee(file);
			 log.h_fecha();
			 log.h_hora();
			 log.h_peso();
			 log.h_monto();
			 break;
			 
		  case 2:
			 tipo = "fecha";
			 log.print_h(tipo);
			 break;
		  
		  case 3:
		     tipo = "hora";
			 log.print_h(tipo);
			 break;
			 
		  case 4:
		     tipo = "peso";
			 log.print_h(tipo);
			 break;
			 
		  case 5:
		     tipo = "monto";
			 log.print_h(tipo);
			 break;
			 
		  case 6:
		     cout << "Introduce el árbol al que se le retirará el menor valor (fecha, hora, peso o monto): ";
			 cin >> tipo;
			 log.pop(tipo);
			 break;
			 
		  case 7:
		     log.print();
			 break;
			 
		  case 8:
		     log.clear();
			 break;
			 
		  case 9:
			 cout << "Escribe el orden en el que se desea escribir el archivo (fecha, hora, peso o monto): ";
			 cin >> tipo;
		     log.escribe(tipo);
			 break;
		}
	}
	
	return 0;
}