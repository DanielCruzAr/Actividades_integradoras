#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "heap.h"
#include "hash.h"
#include "disjoint.h"

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
	//Test heap
	cout << "CASOS PRUEBA DE HEAP\n";
	
	Heap<int> heap(9);
	string heap_ans1 = "Daniel\nCruz\nArciniega\nA01701370\n";
	string heap_ans2 = "Arciniega\nCruz\nDaniel\n";
	
	heap.push(2, "Arciniega");
	heap.push(4, "A01701370");
	heap.push(0, "Daniel");
	heap.push(3, "Cruz");
	
	cout << " 1 " <<	( (!heap_ans1.compare(heap.toString().c_str())) ? "success\n" : "fail\n");
	
	heap.pop();
	
	cout << " 2 " <<	( (!heap_ans2.compare(heap.toString().c_str())) ? "success\n" : "fail\n");
	
	//Test hash
	cout << "CASOS PRUEBA DE HASH\n";
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
	
	//Test disjoint sets
	cout << "CASOS PRUEBA DE DISJOINT SETS\n";
	vector<int> v = {111,115,120,125,130,135,140,145};
	Dj<int, int> set(v, 8);
	
	string dj_ans = "0: parent = 2, 120\n1: parent = 2, 120\n2: parent = -1, 120\n3: parent = 2, 120\n4: parent = -1, 130\n5: parent = -1, 135\n6: parent = -1, 140\n7: parent = -1, 145\n";
	
	set.Union(0,2);
	set.Union(1,2);
	set.Union(3,1);
	
	cout << " 1 " <<	( (!dj_ans.compare(set.toString().c_str())) ? "success\n" : "fail\n");
	cout << " 2 " <<	((5 == set.numSets()) ? "success\n" : "fail\n");
	
	return 0;
}