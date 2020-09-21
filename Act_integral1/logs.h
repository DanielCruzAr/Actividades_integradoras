#ifndef LOGS_H_
#define LOGS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Logs{
    private:
		string file;
		vector<string> data;
		
		//funciones
		//void swap(int,int);
		//void new_vec(vector<int>&);
	public:
		Logs(string);
		
		void lee();
		void imprime();
		//void ordena();
		void busca(string);
		void escribe();
};

Logs::Logs(string f){
	file = f;
}

//Lectura de archivo

void Logs::lee(){
	string line;
	
	ifstream lee(file);
	if (lee.is_open()){
		while (getline(lee, line, '\n')){
			data.push_back(line);
		}
		
		lee.close();
	}
	else{
		cout << "Unable to open file";
    }
}

//Impresion en consola

void Logs::imprime(){
    cout << data[0] << endl;
	cout << "Hora | Nombre | Direccion | Motivo visita \n";
	for (string str : data){
		cout << str << "\n";
	}
}


//Ordenamiento
/*
void Logs::swap(int i, int j){
	string aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

void Logs::new_vec(vector<int> &v){
	string line;
	int num;
	
	for (int i = 1; i<data.size() ; i++){
		line = "";
		for(int j = 0; j <= 2; j++){
			line = line + data[i][j];
		}
		cout << line << endl;
		//num = stoi(line);
		//v.push_back(num);
	}
}

void Logs::ordena(){
	vector<int> int_vec;
	new_vec(int_vec);
	
	for (int i = int_vec.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (int_vec[j] > int_vec[j + 1]) {
				swap(j, j + 1);
			}
		}
	}
}
*/
//Busqueda

void Logs::busca(string n){}

//Escritura de archivo

void Logs::escribe(){
	lee();

	ofstream escribe("orden.txt");
	if(escribe.is_open()){
		for(string i : data){
			escribe << i;
			}
		escribe.close();
	}
	else{
		cout << "Unable to open file";
	}
}
#endif /* LOGS_H_ */
