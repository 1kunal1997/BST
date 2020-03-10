#include "Node.h"
#include <iostream>

// Function prototypes
void traverse(int val, Node* temp);
void inOrder(Node* temp);
int searchVal(int value, Node* temp);
void cleanHeap(Node* temp);

/* main function that makes a binary tree out of a root node and a set
of numbers. The tree is then traversed "in order" printed to the 
terminal. Finally, the tree is searched for a given value. */ 
int main()
{
	int arr[10] = {34,25,6,1,67,103,56,88,47,2000};
	int value = 100;			// number to be searched in the tree.
	Node* root = new Node(50); 
	
	// loop through the array and place them in the appropriate node.  
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
		Node* curr = root;
		traverse(arr[i], curr);
	}
	
	inOrder(root);
	if (searchVal(value, root))
		std::cout << "Value found!" << std::endl;
	else
		std::cout << "Value not found." << std::endl;	
	cleanHeap(root);
	
	return 0;
}

// Recursive function that builds the binary tree.
void traverse(int val, Node* temp) {
	
	if (val > temp -> getValue()) {
		if (temp -> getRight() == nullptr) {
			temp -> setRight(new Node(val));
			return;
		}
		else
			traverse(val, temp -> getRight());
	}
	else {
		if (temp -> getLeft() == nullptr) {
			temp -> setLeft(new Node(val));
			return;
		}
		else
			traverse(val, temp -> getLeft());
	}
}

// traverses the tree and prints the node values in order.	
void inOrder(Node* temp) {
	
	if (!temp)
		return;
	inOrder(temp -> getLeft());
	std::cout << temp -> getValue() << std::endl;
	inOrder(temp -> getRight());
}

// searches for a integer (value) in the tree.
int searchVal(int value, Node* temp) {
	
	if (!temp)
		return 0;
	if (value == temp -> getValue()) {
		return 1;
	}
	if (value < temp -> getValue())
		return searchVal(value, temp -> getLeft());
	else
		return searchVal(value, temp -> getRight());
	return 0;
}

// deletes each node off the heap.
void cleanHeap(Node* temp) {
	
	if (!temp)
		return;
	cleanHeap(temp -> getLeft());
	cleanHeap(temp -> getRight());
	delete temp;
}
