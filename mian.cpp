#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    Heap heap;

	heap.insert(10);
	heap.inorder();
	heap.insert(5);
	heap.inorder();
	heap.insert(15);
	heap.inorder();
	heap.insert(14);
	heap.inorder();
	heap.insert(1);
	heap.inorder();
	heap.insert(20);
	heap.inorder();
	heap.insert(16);
	heap.inorder();
	heap.remove(5);
	heap.preorder();
	cout << endl;
	heap.postorder();

    return 0;
}


