#include <iostream>
using namespace std;

class node{
public: 
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	int d;
	cin >> d;

	if (d == -1){
		return NULL;
	}

	node *root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

//lowest common ancestor
node* lca(node* root, int a, int b){
	if (root == NULL){
		return NULL;
	}

	if (root->data == a or root->data == b){
		return root;
	}

	node* leftAns = lca(root->left, a , b);
	node* rightAns = lca(root->right, a , b);

	if (leftAns != NULL && rightAns != NULL){
		return root;
	}

	if (leftAns == NULL){
		return rightAns;
	}
	return leftAns;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int a, b;
	cin >> a >> b;
	node* root = buildTree();
	node* ancestor = lca(root, a, b);
	cout << ancestor->data << endl;
}