#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

class node{
public: 
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;52134
		left = NULL;
		right = NULL;
	}
};

node* buildTreeFromTraversal(int *preorder, int *inorder, int start, int end){
	static int i = 0;
	if (start > end){
		return NULL;
	}

	node *root = new node(preorder[i]);

	int index = -1;
	for(int j = start; j <= end; j++){
		if (preorder[i] == inorder[j]){
			index = j;
			break;
		}
	}
	i++;

	root->left = buildTreeFromTraversal(preorder, inorder, start, index - 1);
	root->right = buildTreeFromTraversal(preorder, inorder, index + 1, end);
	return root;
}

void printAtLevelK(node* root, int k, vector<int> &v){
	if (root == NULL){
		return;
	}

	if (k == 0){
		v.push_back(root->data);
		return;
	}

	printAtLevelK(root->left, k - 1, v);
	printAtLevelK(root->right, k - 1, v);
}

int printAtDistancek(node* root, int target, int k){
	//base case 
	if (root == NULL){
		return -1;
	}

	if (root->data == target){
		printAtLevelK(root, k, v);
		return 0;
	}

	//when we are at some ancestor node
	int leftDistance = printAtDistancek(root->left, target, k);

	//if leftDist == -1, then the target is not present
	if (leftDistance != -1){
		//now there will be 2 more cases
		if (leftDistance + 1 == k){
			v.push_back(root->data);
		} else {
			printAtLevelK(root->right, k - 2 - leftDistance, v);
		}

		return leftDistance + 1;
	} 

	int rightDistance = printAtDistancek(root->right, target, k);
	if (rightDistance != -1){

		if (rightDistance + 1 == k){
			v.push_back(root->data);
		} else {
			printAtLevelK(root->left, k - 2 - rightDistance, v);
		}

		return 1 + rightDistance;
	}

	return -1;
}

int main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	int n;
	cin >> n;
	int preorder[n], inorder[n];
	for(int i = 0; i < n; i++){
		cin >> preorder[i];
	}
	for(int i = 0; i < n; i++){
		cin >> inorder[i];
	}
	node* root = buildTreeFromTraversal(preorder, inorder, 0, n - 1);
	int t;
	cin >> t;
	while(t--){
		int value, k;
		cin >> value >> k;
		printAtDistancek(root, value, k);
		sort(v.begin(), v.end());
		if (v.size() == 0){
			cout << 0;
		} else {
			for(int i = 0; i < v.size(); i++){
				cout << v[i] << " ";
			}
		}
		cout << endl;
		v.clear();
	}
}