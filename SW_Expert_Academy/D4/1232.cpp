#include <stdio.h>
#include <iostream>

using namespace std;

class Tree {
public:
	int number;
	char data;
	int datan;
	int left, right;
};

Tree* root = (Tree*)malloc(sizeof(Tree) * (1001));

void inorder(Tree* node) {
	if (node->left != 0) inorder(&root[node->left]);
	if (node->right != 0) inorder(&root[node->right]);
	if (root[node->left].data == 'N' && root[node->right].data == 'N') {
		char c = node->data;
		int a = root[node->left].datan;
		int b = root[node->right].datan;
		int result = 0;
		if (c == '+') result = a + b;
		else if (c == '-') result = a - b;
		else if (c == '*') result = a * b;
		else if (c == '/') result = a / b;
		node->data = 'N';
		node->datan = result;
		node->left = 0;
		node->right = 0;
	}
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
			string str;
			cin >> str;
			if (str == "+" || str == "-" || str == "/" || str == "*") {
				cin >> left;
				cin >> right;
				root[n].data = str[0];
				root[n].datan = 0;
				root[n].left = left;
				root[n].right = right;
			}
			else {
				root[n].data = 'N';
				root[n].datan = atoi(str.c_str());
				root[n].left = 0;
				root[n].right = 0;
			}

		}
		
		printf("#%d ", k + 1);
		inorder(&root[1]);
		cout << root[1].datan << endl;
		
	}

	return 0;
}