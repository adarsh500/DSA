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

node* buildNode(){
	int d;
	cin >> d;
	node *root = new node(d);
	string l, r;
	cin >> l;
	if (l == "true"){
		root->left = buildNode();
	}
	cin >> r;
	if (r == "true"){
		root->right = buildNode();
	}
	return root;
}

int countNode(node* root){
	if (root == NULL){
		return 0;
	}
	return 1 + countNode(root->left) + countNode(root->right);
}

	
int sumOfAllNodes(node *root){
	if (root == NULL){
		return 0;
	}
	return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	node *root = buildNode();
	cout << countNode(root) << endl;
	cout << sumOfAllNodes(root) << endl;
}