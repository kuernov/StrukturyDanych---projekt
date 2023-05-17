#pragma once
class BSTTree {
private:
	struct Node {
		Node* right;
		Node* left;
		int value;
		Node(int x) : value(x), left(nullptr), right(nullptr) {}
		//Node() : value(NULL), left(nullptr), right(nullptr) {}
	};
	Node* root;
	Node* insert(Node* root, int value);
	Node* remove(Node* root, int value);
	Node* search(Node* root, int value);
	bool isNull(Node* root);
	Node* findMin(Node* root);
	void inorder(Node* root);
	void preorder(Node* root);
	void postorder(Node* root);

public:
	BSTTree();
	void insert(int value);
	void remove(int value);
	Node* search(int value);
	void inorder();
	void preorder();
	void postorder();
};
