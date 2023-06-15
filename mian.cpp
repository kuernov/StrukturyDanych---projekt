#include <iostream>
//#include "BSTTree.cpp"
#include "Heap.h"
#include <time.h>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;
#include <list>
#include <ctime>
#include <random>

int main() {
	Heap tree(2);
	list<int> lista;
	random_device rd;
	mt19937 gen(rd());
	int tab2[1000];
	int size = 1000000;
	int tab[1000];
	uniform_int_distribution<int> dis(0, size - 1);
	ifstream file("liczby.txt");
	vector<int> tmp;
	int number;
	while (file >> number) {
		tmp.push_back(number);
	}

	for (size_t i = 0; i < size; i++)
	{
		tree.insert(tmp.at(i));
		//lista.push_back(tmp.at(i));
	}
	//cout << "asd" << endl;
	//auto start = high_resolution_clock::now();
	////lista.push_back(tmp.at(size-1));
	//tree.search(tmp.at(size-1));
	////find(lista.begin(), lista.end(), tmp.at(size - 1));
	////tree.remove(tmp.at(size - 1));
	////lista.remove(tmp.at(size - 1));
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<nanoseconds>(stop - start);
	//cout << "Time taken BST: "<< duration.count() << " nanoseconds" << endl;
	int numTrials = 1000; // Liczba powtórzeñ pomiarów
	long long totalDuration = 0;
	int random;
	for (int i = 0; i < numTrials; i++) {
		random = dis(gen);
		//cout << random << endl;
		auto start = high_resolution_clock::now();

		tree.search(tmp[random]);

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start).count();

		totalDuration += duration;
		//cout << duration << endl;
		tab[i] = duration;
		tab2[i] = tmp[random];
	}
	for (size_t i = 0; i < 1000; i++)
	{
		cout << tab[i] << ", " << tab2[i] << endl;
	}
	double averageDuration = static_cast<double>(totalDuration) / numTrials;
	cout << "Œredni czas wyszukiwania: " << averageDuration << " nanosekund" << endl;

	return 0;


}