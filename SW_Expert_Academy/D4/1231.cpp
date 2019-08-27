#include <stdio.h>
#include <iostream>

using namespace std;

class Tree {
public:
	int number;
	char data;
	int left, right;
	Tree(int number, char data, int left, int right) {
		this->number = number;
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

Tree* root = (Tree*)malloc(sizeof(Tree) * (101));

void inorder(Tree* node) {
	if (node->left != 0) inorder(&root[node->left]);
	printf("%c", node->data);
	if (node->right != 0) inorder(&root[node->right]);
}

int main() {
	int number;

	for (int k = 0; k < 10; k++) {
		cin >> number;
		int n;
		int node = 1;
		char data;
		int left = 0;
		int right = 0;

		for (int i = 0; i < number; i++) {
			cin >> n;
			cin >> data;
			root[n].data = data;
			if (node++ < number) {
				cin >> left;
				root[n].left = left;
			}
			else {
				root[n].left = 0;
			}
			if (node++ < number) {
				cin >> right;
				root[n].right = right;
			}
			else {
				root[n].right = 0;
			}
		}
		printf("#%d ", k + 1);
		inorder(&root[1]);
		cout << endl;
	}

	return 0;
}