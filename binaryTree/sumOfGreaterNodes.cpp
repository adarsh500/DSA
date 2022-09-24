#include <iostream>
#include <algorithm>
#include <vector>
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

node* buildTree(int arr[], int start, int end){
	if (start > end){
		return NULL;  
	}

	int mid = (start + end) / 2;
	node* root = new node(arr[mid]);

	root->left = buildTree(arr, start, mid - 1);
	root->right = buildTree(arr, mid + 1, end);
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
	int n;
	cin >> n;
	int arr[n], cumArr[10000] = {0};
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cumArr[0] = arr[0];
	for(int i = 1; i < n; i++){
		cumArr[i] = arr[i] + cumArr[i - 1];
	}

	int maxSum = cumArr[n - 1];

	int treeArr[n];
	for(int i = 0; i < n; i++){
		treeArr[i] = maxSum - cumArr[i] + arr[i];
	}
	node* root = buildTree(treeArr, 0, n - 1);
	print(root);
	cout << endl;
}