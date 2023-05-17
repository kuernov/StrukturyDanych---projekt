#include <iostream>
#include "BSTTree.h"

using namespace std;



BSTTree::BSTTree()
{
	root = nullptr;
}

void BSTTree::insert(int value)
{
	root = insert(root, value);
}

void BSTTree::remove(int value)
{
	root = remove(root, value);
}

BSTTree::Node* BSTTree::search(int value)
{
	return search(root, value);
}

void BSTTree::inorder()
{
	inorder(root);
	cout << endl;
}

void BSTTree::preorder()
{
	preorder(root);
}

void BSTTree::postorder()
{
	postorder(root);
}

BSTTree::Node* BSTTree::search(Node* root, int value)
{
	if (value == root->value || isNull(root))
		return root;
	else if (value > root->value) 
		search(root->right, value);
	else
		search(root->left, value);
}

BSTTree::Node* BSTTree::insert(Node* root, int value)
{
	if (isNull(root)) {
		Node* node = new Node(value);
		root = node;
	}
	else if (value > root->value)
		root->right = insert(root->right, value); //finding place to insert by recursion
	else if(value<root->value)
		root->left = insert(root->left, value);  
	return root;
}

BSTTree::Node* BSTTree::remove(Node* root, int value)
{
	Node* temp;
	if (isNull(root)) //empty tree
		return root;
	else if (root->value > value) {
		root->left = remove(root->left, value); //go to left subtree
	}
	else if (root->value < value) {
		root->right = remove(root->right, value); //go to right subtree
	}
	else {														//value is equal root->value
		if (root->left == nullptr && root->right == nullptr)    //node to be deleted is leaf
			return nullptr;
		else if (root->left == nullptr) {						//node has one child
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {						//node has one child
			temp = root->left;
			delete root;
			return temp;
		}
		else {													//node has to two children
			temp = findMin(root->right);					//find smallest node in right subtree
			root->value = temp->value;							//change value of the root
			root->right = remove(root->right, temp->value);		//delete smallest node in right subtree
		}
	}
	return root;

}
BSTTree::Node* BSTTree::findMin(Node* root) {
	if (root->left == nullptr)
		return root;
	else
		return findMin(root->left);
}

void BSTTree::inorder(Node* root) //from left tree to right (from lowest to highest)
{
	if (root == nullptr)
		return;
	inorder(root->left);
	cout << root->value << "  ";
	inorder(root->right);
}

void BSTTree::preorder(Node* root) //starting from root, left then right 
{
	if (root == nullptr)
		return;
	cout << root->value << "  ";
	preorder(root->left);
	preorder(root->right);
}

void BSTTree::postorder(Node* root) 
{
	if (root == nullptr)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->value << "  ";
}

bool BSTTree::isNull(Node* root)
{
	return root == nullptr;
}

