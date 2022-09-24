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

void print(node* root){
	if (root == NULL){
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);

	return;
}

node* insert(node* root, int d){
	if(root == NULL){
		return new node(d);		
	}

	if (d <= root->data){
		root->left = insert(root->left, d);
	} else {
		root->right = insert(root->right, d);
	}

	return root;
}

void nodesInRange(node* root, int k1, int k2){
	if (root == NULL){
		return;
	}

	nodesInRange(root->left, k1 ,k2);

	if (root->data >= k1 && root->data <= k2){
		cout << root->data << " ";
	} 

	nodesInRange(root->right, k1 ,k2);
}

int main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	int t;
	cin >> t;
	while(t--){
		node* root = NULL;
		int n, k1, k2;
		cin >> n;

		int arr[n];
		for(int i = 0; i < n; i++){
			int d;
			cin >> d;
			root = insert(root, d);
		}
		cin >> k1 >> k2;

		cout << "# Preorder : ";
		print(root);
		cout << endl;

		cout << "# Nodes within range are : ";
		nodesInRange(root, k1, k2);
		cout << endl;
	}
}