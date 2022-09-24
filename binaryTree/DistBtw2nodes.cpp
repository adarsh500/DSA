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

int search(node* root, int key, int level){
	if (root == NULL){
		return -1;
	}

	if(root->data == key){
		return level;
	}

	int left = search(root->left, key, level + 1);
	if (left != -1){
		return left;
	} 
	return search(root->right, key, level + 1);
}

int distanceBetweenNodes(node* root, int a, int b){
	node* lcaNode = lca(root, a, b);

	int l1 = search(lcaNode, a, 0);
	int l2 = search(lcaNode, b, 0);

	return l1 + l2;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	node* root = buildTree();
	int a, b;
	cin >> a >> b;
	// cout << lca(root, a, b)->data << endl;
	cout << distanceBetweenNodes(root, a, b) << endl;
}