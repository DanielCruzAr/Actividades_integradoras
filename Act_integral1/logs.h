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
		int error; //esta variable fue creada porque hay un error en el archivo en el primer renglon
		
		//funciones
		//Ordenamiento
		void swap(int,int);
		void swap_int(vector<int>&,int,int);
		void new_vec(vector<int>&);
		//Busqueda
		void track_error(); //funcion para rastrear el error
		void str_vec(vector<string>&);
	public:
		Logs(string);
		
		void lee();
		void imprime();
		void ordena();
		string busca(string);
		void escribe();
};

Logs::Logs(string f){
	file = f;
	error = 0;
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
	cout << "Hora | Nombre | Direccion | Motivo visita \n";
	for (string str : data){
		cout << str << "\n";
	}
}


//Ordenamiento

void Logs::swap(int i, int j){
	string aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

void Logs::swap_int(vector<int> &v, int i, int j){
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void Logs::new_vec(vector<int> &v){
	string line;
	int num;
	
	
	for (int i = 0; i<data.size() - 1; i++){
		line = "";
		if(i == error){
			line += data[i][2];
			line += data[i][4];
			line += data[i][8];
			line += data[i][10];
		}
		else{
			line += data[i][1];
			line += data[i][3];
			line += data[i][7];
			line += data[i][9];
		}
	     
		num = stoi(line);
		v.push_back(num);
	}
}

void Logs::ordena(){
	vector<int> int_vec;
	new_vec(int_vec);
	
	for (int i = int_vec.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (int_vec[j] > int_vec[j + 1]) {
				swap(j, j + 1);
				swap_int(int_vec, j, j+1);
			}
		}
	}
	
}

//Busqueda

void Logs::track_error(){
	string track;
	for(int i=0; i < data.size() - 1; i++){
		track = data[i][2];
		if (track == "1"){
			error = i;
		}
	}
}

void Logs::str_vec(vector<string> &strv){
	string hr;
	
	for (int i = 0; i<data.size() - 1; i++){
		hr = "";
		if(i == error){
			hr += data[i][2];
			hr += data[i][4];
			hr += data[i][6];
			hr += data[i][8];
			hr += data[i][10];
		}
		else{
			hr += data[i][1];
			hr += data[i][3];
			hr += data[i][5];
			hr += data[i][7];
			hr += data[i][9];
		}
		
		strv.push_back(hr);
	}
}

string Logs::busca(string n){
	vector<string> strv;
	track_error();
	str_vec(strv);
	
	for (int i = 0; i < strv.size() - 1; i++){
		if (strv[i] == n){
			return data[i];
		}
	}
	return "No hay registros a esa hora \n";
}

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
