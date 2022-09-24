#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// 4 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1

class node{
public:
	int data;
	node* left;
	node* right;
	node(int val){
		data = val;
		left = right = NULL;
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

void verticalOrder(node* root, int d, map<int, vector<int>> &m){
	if (root == NULL){
		return;
	}

	m[d].push_back(root->data);
	verticalOrder(root->left, d - 1, m);
	verticalOrder(root->right, d + 1, m);
	return;
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif 
	int n;
	cin >> n;
	node* root;
	level_order_build(root);
	map<int, vector<int>> m;
	int d = 0; // this is the level
	verticalOrder(root, d, m); 


	for(auto p : m){
		// cout << "key: " << p.first << " "; 
		for(auto x : p.second){
			cout << x << " ";
		}

		// cout << endl;
	}
	cout << endl;
}