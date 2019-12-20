#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	node* prev;
	node* next;
	char data;
};

node* newHead() {
	node* temp = (node*)malloc(sizeof(node));
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = 0;
	return temp;
}

node* insert(node* cursor, char val) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = val;
	
	if (cursor->next != NULL) {
		node* right = cursor->next;
		cursor->next = temp;
		temp->prev = cursor;
		temp->next = right;
		right->prev = temp;
	}
	else {
		cursor->next = temp;
		temp->prev = cursor;
		temp->next = NULL;
	}
	return temp;
}

void print(node* head) {
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		cout << temp->data;
	}
	cout << "\n";
}

void del(node* head) {
	while (head->next != NULL) {
		node* temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
}

node* erase(node* cursor) {
	node* left = cursor->prev;
	if (cursor->next != NULL) {
		node* right = cursor->next;
		left->next = right;
		right->prev = left;
	}
	else {
		left->next = NULL;
	}
	free(cursor);
	return left;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		node* head = newHead();
		node* cursor = head;
		int strSize = str.length();
		for (int i = 0; i < strSize; i++) {
			char a = str.at(i);
			if (a == '<') {
				if (cursor != head) cursor = cursor->prev;
			}
			else if (a == '>') {
				if (cursor->next != NULL) cursor = cursor->next;
			}
			else if (a == '-') {
				if(cursor != head) cursor = erase(cursor);
			}
			else {
				cursor = insert(cursor, a);
			}			
		}
		print(head);
		del(head);
	}
}