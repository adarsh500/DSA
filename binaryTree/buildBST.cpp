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

node* buildBST(int *arr, int start, int end){
	if (start > end){
		return NULL;
	}

	int mid = (start + end) / 2;
	node* root = new node(arr[mid]);

	root->left = buildBST(arr, start, mid - 1);
	root->right = buildBST(arr, mid + 1, end);

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


int main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}

		node* root = buildBST(arr, 0, n - 1);
		print(root);
		cout << endl;
	}
}