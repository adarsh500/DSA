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
	string l, r;
	cin >> d;
	node* root = new node(d);
	cin >> l;
	if(l == "true"){
		root->left = buildTree();
	}
	cin >> r;
	if(r == "true"){
		root->right = buildTree();
	}
	return root;
}

void print(node* root){
	if (root == NULL){
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

bool structure(node* root1, node* root2){
	if (root1 == NULL && root2 == NULL){
		return true;
	} else if (root1 != NULL && root2 != NULL){
		bool leftIsPresent = structure(root1->left, root2->left);
		bool rightIsPresent = structure(root1->right, root2->right);
		if (leftIsPresent && rightIsPresent){
			return true;
		}
	} 
	return false;
}

int main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif

	node *root1 = buildTree();
	node *root2 = buildTree();
	if (structure(root1, root2)){
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}