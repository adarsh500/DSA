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

void topView(node* root){
	if (root == NULL){
		return;
	}
	queue<pair<node*, int>> q;
	map<int, int> m;

	q.push(make_pair(root, 0));

	while(!q.empty()){

		auto it = q.front();
		q.pop();

		node* node = it.first;
		int index = it.second;

		if (m.find(index) == m.end()){
			m[index] = node->data;
		}

		if (node->left != NULL){
			q.push(make_pair(node->left, index - 1));
		}

		if (node->right != NULL){
			q.push(make_pair(node->right, index + 1));
		}
	}

	for( auto it : m){
		cout << it.second << " ";
	}

}

int main() {

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	node* root;
	levelOrderBuild(root);
	topView(root);
	cout << endl;
}

