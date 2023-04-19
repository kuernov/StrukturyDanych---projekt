#include <iostream>

using namespace std;

struct Node {
	int* right, left;
	int value;
};

class BSTTree {
private:
	Node node;
	Node* root;
public:
	BSTTree(int value);
	void insert(int value);
	void remove(int value);
	Node search(int value);
	bool isEmpty();

};

BSTTree::BSTTree(int value)
{
}

void BSTTree::insert(int value)
{
}

void BSTTree::remove(int value)
{
}

Node BSTTree::search(int value)
{
	return Node();
}

bool BSTTree::isEmpty()
{
	return root == nullptr;
}
