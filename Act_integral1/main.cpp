#include <iostream>
#include <fstream>
#include <vector>
#include "logs.h"
using namespace std;

void menu(){
	cout << "Opcion 1: ordenar por hora" << endl;
	cout << "Opcion 2: buscar por hora" << endl;
	cout << "Opcion 3: imprimir archivo en consola" << endl;
	cout << "Opcion 4: escribir en nuevo archivo de texto" << endl;
	cout << "Opcion 5: salir" << endl;
}

int main(){
	int opcion = 0;
	string n;
	Logs log("datos.txt");
	
	log.lee();
	
	while(opcion <5 && opcion >-1){
      menu();
      cin >> opcion;

      switch(opcion){
		  case 1:
			 log.ordena();
			 break;
			 
		  case 2:
			 cout << "introduce hora de registro (hh:mm): \n";
			 cin >> n;
			 cout << log.busca(n) << endl; 
			 break;
			 
		  case 3:
			 log.imprime();
			 break;
		  
		  case 4:
			 log.escribe();
			 break;
		}
	}
	return 0;
}