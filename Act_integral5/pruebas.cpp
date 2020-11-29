#include <iostream>
#include <cstring>
#include <string>
#include "hash.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int borrar(string s){
	return myHash(s) % 9;
}

int main() {
	Hash<string, string> test(9, string("empty"), myHash);
	
	string test_ans = "[ 0, zoologico, ponganme]\n[ 1, coche, ya]\n[ 2, avion, la]\n[ 3, vino, competencia]\n[ 4, gato, de]\n[ 5, dragon, casos]\n[ 6, barco, prueba]\n[ 7, salud, porfa]\n[ 8, medicina, gracias]\n";
    string test_ans2 = "porfa";
	string test_ans3 = "prueba";
	string test_ans4 = "casos";
	
	test.put("barco", "prueba");
	test.put("coche", "ya");
	test.put("avion", "la");
	test.put("zoologico", "ponganme");
	test.put("gato", "de");
	test.put("salud", "porfa");
	test.put("vino", "competencia");
	test.put("dragon", "casos");
	test.put("medicina", "gracias");
	
	test_ans = "[ 0, zoologico, ponganme]\n[ 1, coche, ya]\n[ 2, avion, la]\n[ 3, vino, competencia]\n[ 4, gato, de]\n[ 5, dragon, casos]\n[ 6, barco, prueba]\n[ 7, salud, porfa]\n[ 8, medicina, gracias]\n";
	
	cout << " 1 " <<	( (!test_ans.compare(test.toString().c_str())) ? "success\n" : "fail\n");
	cout << " 2 " <<	( (!test_ans2.compare(test.get("salud").c_str())) ? "success\n" : "fail\n");
	cout << " 3 " <<	( (!test_ans3.compare(test.get("barco").c_str())) ? "success\n" : "fail\n");
	cout << " 4 " <<	( (!test_ans4.compare(test.get("dragon").c_str())) ? "success\n" : "fail\n");

	return 0;
}

/*
ponganme
ya 
la 
competencia
de
casos
prueba
porfa
gracias
*/