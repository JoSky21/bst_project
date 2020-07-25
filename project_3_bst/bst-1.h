#pragma once

/*
	Author: Jonathan Harjono
	NetID: jh4482
	Compiler used: Visual Studio 2019
	Program description: This program allows the user to create a binary search tree
						that supports insert, delete, search, and saves the postorder traversal to a file.
*/


#include <string>
#include <iostream>
#include <fstream>

using std::ostream;
using std::string;

class Node {
public:
	string data;
	Node* left;
	Node* right;

	Node() {
		data = "";
		left = nullptr;
		right = nullptr;
	}
	Node(string data1) {
		data = data1;
		left = nullptr;
		right = nullptr;
	}
};

class BST {
private:
	Node* root;
	bool rInsert(Node*& n, string s) {
		if (n == nullptr) {
			n = new Node(s);
			return true;
		}
		if (n->data > s) {
			return rInsert(n->left, s);
		}
		if (n->data < s) {
			return rInsert(n->right, s);
		}
		return false;
	}
	string rSearch(Node*& n, string s) {
		if (n == nullptr) { return "Not"; }
		if (n->data > s) {
			return rSearch(n->left, s);
		}
		if (n->data < s) {
			return rSearch(n->right, s);
		}
		if (n->data == s) {
			return n->data;
		}
		std::cout << "Help." << std::endl;
		return "Not";

	}
	void rdelete(Node*& n, string s) {
		if (n == nullptr) { return; }
		else if (s < n->data) {
			rdelete(n->left, s);
		}
		else if (s > n->data) {
			rdelete(n->right, s);
		}
		else {
			//Case 1
			if (n->left == nullptr && n->right == nullptr) {
				n = nullptr;
				return;
			}
			//Case 2
			else if (n->left == nullptr && n->right != nullptr) {
				n = n->right;
				n->right = nullptr;
			}
			else if (n->right == nullptr && n->left != nullptr) {
				n = n->left;
				n->left = nullptr;
			}
			//Case 3
			else {
				Node* temp = n;
				Node* tempo = nullptr;
				temp = temp->left;
				while (temp->right != nullptr) {
					tempo = temp;
					temp = temp->right;
				}
				n->data = temp->data;
				if (tempo != nullptr) {
					tempo->right = temp->left;
				}
				delete temp;
				temp = nullptr;	
			}
		}
	}
	void rInOrder(Node* n, ostream& os) {
		if (n == nullptr) return;
		rInOrder(n->left, os);
		os << n->data << std::endl;
		rInOrder(n->right, os);
	}
	void rPreOrder(Node* n, ostream& os) {
		if (n == nullptr) return;
		os << n->data << std::endl;
		rPreOrder(n->left, os);
		rPreOrder(n->right, os);
	}
	void rPostOrder(Node* n, ostream& os) {
		if (n == nullptr) return;
		rPostOrder(n->left, os);
		rPostOrder(n->right, os);
		os << n->data << std::endl;
	}
	void rlumberjack(Node* &n) {
		if (n == nullptr) return;
		rlumberjack(n->left);
		rlumberjack(n->right);
		delete n;
		n = nullptr;
	}
	Node* getRoot() {
		return root;
	}



public:
	BST() {
		root = nullptr;
	}

	bool insert(string s) {
		return rInsert(root, s);
	}
	string search(string s) {
		string x;
		string y = "Not found";
		x = rSearch(root, s);
		if (x == "Not") {
			return y;
		}
		else {
			return x;
		}
	}
	void deleteString(string s) {
		rdelete(root, s);
		Node* temp = new Node();
		temp = getRoot();
		if (temp == nullptr) {
			isEmpty();
		}
	}
	void inOrderOut(ostream& os) {
		rInOrder(root, os);
		Node* temp = new Node();
		temp = getRoot();
		if (temp == nullptr) {
			isEmpty();
		}
	}
	void preOrderOut(ostream& os) {
		rPreOrder(root, os);
		Node* temp = new Node();
		temp = getRoot();
		if (temp == nullptr) {
			isEmpty();
		}
	}
	void postOrderOut(ostream& os) {
		rPostOrder(root, os);
		Node* temp = new Node();
		temp = getRoot();
		if (temp == nullptr) {
			isEmpty();
		}
	}
	void lumberjack() {
		rlumberjack(root);
	}
	void isEmpty() {
		std::cout << "The tree is empty." << std::endl;
	}

};
