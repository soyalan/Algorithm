#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	node* next;
	int data;
};

node* newHead() {
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	head->data = 1;
	return head;
}

node* insert(node* cur, int val) {
	node* temp = (node*)malloc(sizeof(node));
	cur->next = temp;
	temp->next = NULL;
	temp->data = val;
	return temp;
}

node* del(node* cur) {
	node* left = cur;
	cur = cur->next;
	node* right = cur->next;
	cout << cur->data << ", ";
	free(cur);
	left->next = right;
	return left;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, N;
	cin >> K >> N;
	node* head = newHead();
	node* cur = head;
	for (int i = 2; i <= K; i++) cur = insert(cur, i);
	cur->next = head;

	cout << "<";
	for (int i = 1; i < K; i++) {
		for (int j = 1; j < N; j++) cur = cur->next;
		cur = del(cur);
	}
	cout << cur->data << ">\n";
	free(cur);

	return 0;
}