#include <iostream>
#include <queue>
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

node* insertInBST(node* root, int d){
	if (root == NULL){
		return new node(d);
	}

	if (d <= root->data){
		root->left = insertInBST(root->left, d);
	} else {
		root->right = insertInBST(root->right, d);
	}

	return root;
}

node* build(){
	int d;
	cin >> d;

	node* root = NULL;
	while(d != -1){
		root = insertInBST(root, d);
		cin >> d;
	}

	return root;
}

bool search(node* root, int data){
	if (root == NULL){
		return false;
	}

	if (root->data == data){
		return true;
	}

	if (data <= root->data){
		search(root->left, data);
	}
	return search(root->right, data);
}

void bfs(node * root){
	queue<node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node *f = q.front();
		if (f == NULL){
			cout << endl;
			q.pop();
			if (!q.empty()){
				q.push(NULL);
			}
		} else {
			cout << f->data << " ";
			q.pop();

			if (f->left){
				q.push(f->left);
			}

			if (f->right){
				q.push(f->right);
			}
		}
	}
}

node* deleteInBST(node* root, int data){
	if (root == NULL){
		return NULL;
	} else if (data < root->data){
		root->left = deleteInBST(root->left, data);
		return root;
	} else if (data == root->data){
		//we have found the node to delete. WE will encounter 3 cases
		//CASE 1: node with 0 children
		if (root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		} 

		//CASE 2: node has 1 child
		if (root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		if (root->right == NULL && root->left != NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}

		//CASE 3: node has 2 children
		//here we replace the node with the element that is just bigger 
		//than the current node
		node* replace = root->right;
		while(replace->left != NULL){
			replace = replace->left;
		}

		root->data = replace->data;
		root->right = deleteInBST(root->right, replace->data);
		return root;
	} else {
		root->right = deleteInBST(root->right, data);
		return root;
	}
}

bool isBST(node* root, int min = INT_MIN, int max = INT_MAX){
	if (root == NULL){
		return true;
	}
	bool left = isBST(root->left, min, root->data);
	bool right = isBST(root->right, root->data, max);

	if (root->data >= min && root->data <= max && left && right){
		return true;
	}

	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	node* root = build();
	bfs(root);
	// root = deleteInBST(root, 5);
	// bfs(root);
	if (isBST(root)){
		cout << "true";
	} else {
		cout << "false";
	}

}