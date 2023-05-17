#include <iostream>
//#include "BSTTree.cpp"
#include "BSTTree.h"

using namespace std;

int main() {
	BSTTree tree;
	tree.insert(10);
	tree.inorder();
	tree.insert(5);
	tree.inorder();
	tree.insert(15);
	tree.inorder();
	tree.insert(14);
	tree.inorder();
	tree.insert(1);
	tree.insert(20);
	tree.remove(14);
	tree.insert(16);
	tree.inorder();
	tree.preorder();
	cout << endl;
	tree.postorder();
	
}