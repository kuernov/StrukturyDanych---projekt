#include <iostream>
//#include "BSTTree.cpp"
#include "BSTTree.h"
#include <time.h>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;
#include <list>

int main() {
	BSTTree tree;
	list<int> lista;

	int size =1000000;


	int* array = new int[size];
	ifstream file("liczby.txt");
	vector<int> tmp;
	int number;
	int i = 0;
	while (file >> number) {
		tmp.push_back(number);
	}

	for (size_t i = 0; i < size; i++)
	{
		tree.insert(tmp.at(i));
		//lista.push_back(tmp.at(i));
	}
	cout << "asd" << endl;
	auto start = high_resolution_clock::now();
	//lista.push_back(tmp.at(size-1));
	tree.search(tmp.at(size-1));
	//find(lista.begin(), lista.end(), tmp.at(size - 1));
	//tree.remove(tmp.at(size - 1));
	//lista.remove(tmp.at(size - 1));
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << "Time taken BST: "<< duration.count() << " nanoseconds" << endl;

	return 0;

	
}