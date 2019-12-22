#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	node* prev;
	node* next;
	int data;
};

node* newHead() {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = 1;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

node* insert(node* cursor, int data) {
	node* temp = (node*)malloc(sizeof(node));
	cursor->next = temp;
	temp->prev = cursor;
	temp->next = NULL;
	temp->data = data;
	return temp;
}

node* erase(node* cursor) {
	node* left = cursor->prev;
	node* right = cursor->next;
	left->next = right;
	right->prev = left;
	free(cursor);
	return right;
}

void del(node* head) {
	head->prev->next = NULL;
	while (head->next != NULL) {
		node* temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	node* head = newHead();
	node* cursor = head;
	for (int i = 2; i <= N; i++) cursor = insert(cursor, i);
	cursor->next = head;
	head->prev = cursor;

	int res = 0;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		if (head->data == n) {
			head = erase(head);
			N--;
		}
		else {
			cursor = head->next;
			int cnt = 1;
			while (cursor->data != n) {
				cursor = cursor->next;
				cnt++;
			}
			if (N - cnt > cnt) {
				res += cnt;
				head = erase(cursor);
				N--;
			}
			else {
				cursor = head->prev;
				cnt = N - cnt;
				res += cnt;
				for (int j = 1; j < cnt; j++) cursor = cursor->prev;
				head = erase(cursor);
				N--;
			}

		}
	}

	cout << res << "\n";
	if(N) del(head);

	return 0;
}