#include <iostream>
#include <queue>
#define ll long long int
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

void level_order_build(node *&root) {

	ll d, c1, c2;
	queue<node*> Q;

	cin >> d;
	root = new node(d);
	Q.push(root);
	while (Q.size() >= 1) {
		node *n = Q.front();
		Q.pop();
		cin >> c1 >> c2; // Children of n->data
		if (c1 != -1) {
			n->left = new node(c1);
			Q.push(n->left);
		}
		if (c2 != -1) {
			n->right = new node(c2);
			Q.push(n->right);
		}
	}
}

void rightView(node* root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}

	if (level > maxlevel) {
		cout << root->data << " ";
		maxlevel = level;
	}

	rightView(root->right, level + 1, maxlevel);
	rightView(root->left, level + 1, maxlevel);
}

void bfs2(node * root) {
	queue<node *> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node *f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << f->data << " ";
			q.pop();

			if (f->left) {
				q.push(f->left);
			}

			if (f->right) {
				q.push(f->right);
			}
		}
	}
}

int main() {
	// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	// #endif
	node* root;
	level_order_build(root);
	// bfs2(root);
	// cout << endl;
	int maxLevel = -1;
	rightView(root, 0, maxLevel);
	cout << endl;
}