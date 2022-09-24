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

node* createTreeFromTraversal(int* inorder, int* preorder, int start, int end){
	static int i = 0;
	//static makes sure that the variable stores the value from the 
	//prev function call
	if (start > end){
		return NULL;
	}

	node* root = new node(preorder[i]);

	int index = -1;
	for(int j = start; j <= end; j++){
		if (inorder[j] == preorder[i]){
			index = j;
			break;
		}
	}
	++i;


	root->left = createTreeFromTraversal(inorder, preorder, start, index - 1);
	root->right = createTreeFromTraversal(inorder, preorder, index + 1, end);
	return root;
}

void print(node* root){
	if (root == NULL){
		return;
	}

	if (root->left == NULL){
		cout << "END => ";
	} else {
		cout << root->left->data << " => ";
	}
	cout << root->data;

	if (root->right == NULL){
		cout << " <= END" << endl;
	} else {
		cout << " <= " << root->right->data << endl;
	}
	print(root->left);
	print(root->right);
}

int main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif

	int n, m;
	cin >> n;
	int preorder[n];
	for(int i = 0; i < n; i++){
		cin >> preorder[i];
	}
	cin >> m;
	int inorder[m];
	for(int i = 0; i < m; i++){
		cin >> inorder[i];
	}
	node* root = createTreeFromTraversal(&inorder[0], &preorder[0], 0, n - 1);
	print(root);
	return 0;
}