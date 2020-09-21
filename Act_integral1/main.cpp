#include <iostream>
#include <fstream>
#include <vector>
#include "logs.h"
using namespace std;

int main(){
	Logs log("datos.txt");
	
	log.lee();
	//log.ordena();
	//log.busca(string n);
	log.imprime();
	log.escribe();
	return 0;
}