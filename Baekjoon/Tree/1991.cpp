#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	char data;
};

Node* findNode(Node* node, char data) {
	if (node->data == data) return node;
	if (node->left != NULL) {
		Node* left = findNode(node->left, data);
		if (left != NULL) return left;
	}
	if (node->right != NULL) {
		Node* right = findNode(node->right, data);
		if (right != NULL) return right;
	}
	return NULL;
}

Node* makeNode(Node* root, char a, char b, char c) {
	Node* temp;
	if (root == NULL) {
		temp = (Node*)malloc(sizeof(Node));
		temp->data = a;
		temp->left = NULL;
		temp->right = NULL;
	}
	else temp = findNode(root, a);

	if (b != '.') {
		Node* leftChild = (Node*)malloc(sizeof(Node));
		leftChild->data = b;
		leftChild->left = NULL;
		leftChild->right = NULL;
		temp->left = leftChild;
	}
	if (c != '.') {
		Node* rightChild = (Node*)malloc(sizeof(Node));
		rightChild->data = c;
		rightChild->left = NULL;
		rightChild->right = NULL;
		temp->right = rightChild;
	}
	return temp;
}

void preOrder(Node* node) {
	cout << node->data;
	if (node->left != NULL) preOrder(node->left);
	if (node->right != NULL) preOrder(node->right);
}

void inOrder(Node* node){
	if (node->left != NULL) inOrder(node->left);
	cout << node->data;
	if (node->right != NULL) inOrder(node->right);
}

void postOrder(Node* node) {
	if (node->left != NULL) postOrder(node->left);
	if (node->right != NULL) postOrder(node->right);
	cout << node->data;
}

void delNode(Node* node) {
	if (node->left != NULL) delNode(node->left);
	if (node->right != NULL) delNode(node->right);
	free(node);
}

int main() {
	int T;
	cin >> T;
	Node* root = NULL;
	for (int t = 0; t < T; t++) {
		char a, b, c;
		cin >> a >> b >> c;
		Node* temp = makeNode(root, a, b, c);
		if (a == 'A') root = temp;
	}

	preOrder(root);
	cout << "\n";
	inOrder(root);
	cout << "\n";
	postOrder(root);
	cout << "\n";

	delNode(root);

	return 0;
}