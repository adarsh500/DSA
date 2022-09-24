#include <iostream>
#include <map>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

void levelOrderBuild(node* &root) {
	int d, c1, c2;
	queue<node *> q;
	cin >> d;
	root = new node(d);
	q.push(root);
	while (q.size() >= 1) {
		node* n = q.front();
		q.pop();
		cin >> c1 >> c2;
		if (c1 != -1) {
			n->left = new node(c1);
			q.push(n->left);
		}
		if (c2 != -1) {
			n->right = new node(c2);
			q.push(n->right);
		}
	}
}

void leftView(node* root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}

	if (level > maxlevel) {
		cout << root->data << " ";
		maxlevel = level;
	}

	leftView(root->left, level + 1, maxlevel);
	leftView(root->right, level + 1, maxlevel);
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	node* root;
	levelOrderBuild(root);
	int level = -1;
	leftView(root, 0, level);
	cout << endl;
}

