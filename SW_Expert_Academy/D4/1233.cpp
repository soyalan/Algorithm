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

Tree* root = (Tree*)malloc(sizeof(Tree) * (201));

bool ps;

void inorder(Tree* node) {
	if (node->left != 0) inorder(&root[node->left]);
	if (node->left == 0 && node->right == 0) {
		int c = node->data - '0';
		if (!(c >= 0 && c < 10)) {
			ps = false;
		}
	}
	else {
		int c = node->data - '0';
		if (c >= 0 && c < 10) {
			ps = false;
		}
	}
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
		ps = true;
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

		inorder(&root[1]);
		if(ps) printf("#%d 1\n", k + 1);
		else printf("#%d 0\n", k + 1);
		
	}

	return 0;
}