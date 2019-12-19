#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
	node* prev;
	node* next;
	char val;
};

node* newHead() {
	node* temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->val = 0;
	return temp;
}

node* insert(node* cursor, char a) {
	node* temp = (node*)malloc(sizeof(node));
	if (cursor->next != NULL) {
		node* right = cursor->next;
		temp->next = right;
		right->prev = temp;
	}
	else {
		temp->next = NULL;
	}
	temp->prev = cursor;
	temp->val = a;
	cursor->next = temp;
	return temp;
}

node* erase(node* cursor) {
	node* left = cursor->prev;
	if (cursor->next != NULL) {
		node* right = cursor->next;
		right->prev = left;
		left->next = right;
	}
	else {
		left->next = NULL;
	}
	free(cursor);
	return left;
}

void del(node* head) {
	node* cur = head;
	while (cur->next != NULL){
		node* temp = cur;
		cur = cur->next;
		free(temp);
	}
	free(cur);
}

void print(node* head) {
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
		cout << cur->val;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int T;
	char C, A;
	cin >> str;

	node* head = newHead();
	node* cursor = head;
	int strSize = str.length();
	for (int i = 0; i < strSize; i++) cursor = insert(cursor, str.at(i));
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> C;
		if (C == 'L') {
			if (cursor != head) cursor = cursor->prev;
		}
		else if (C == 'D') {
			if (cursor->next != NULL) cursor = cursor->next;
		}
		else if (C == 'B') {
			if (cursor != head) cursor = erase(cursor);
		}
		else if(C == 'P'){
			cin >> A;
			cursor = insert(cursor, A);
		}
	}

	print(head);
	del(head);
	
	return 0;
}