#include<iostream>
using namespace std;
class node {
public:
	int data;
	node*left;
	node*right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* insert(node*root, int data) {
	if (root == NULL) {
		return new node(data);
	}
	if (data <= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}
node* deletion(node*root, int data) {
	if (root == NULL) {
		return NULL;
	}
	else if (data < root->data) {
		root->left = deletion(root->left, data);
		return root;
	}
	else if (data == root->data) {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		if (root->left != NULL && root->right == NULL) {
			node*temp = root->left;
			delete root;
			return temp;
		}
		if (root->left == NULL && root->right != NULL) {
			node*temp = root->right;
			delete root;
			return temp;
		}
		else {
			node*replace = root->right;
			while (replace->left != NULL) {
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = deletion(root->right, replace->data);
			return root;
		}
	}
	else {
		root->right = deletion(root->right, data);
		return root;
	}
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
int main()
{
	int t, d;
	cin >> t;
	while (t--)
	{
		node*root = NULL;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d;
			root = insert(root, d);
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> d;
			root = deletion(root, d);
		}
		print(root);
		cout << endl;
	}
	return 0;
}