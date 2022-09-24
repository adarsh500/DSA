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

class Pair{
public:
	int branchSum;
	int maxSum;

	Pair(){
		branchSum = 0;;
		maxSum = 0;
	}
};

Pair maxSumPath(node* root){
	Pair p;
	if (root == NULL){
		return p;
	}

	Pair left = maxSumPath(root->left);
	Pair right = maxSumPath(root->right);

	//handling 4 cases
	int op1 = root->data;
	int op2 = root->data + left.branchSum;
	int op3 = root->data + right.branchSum;
	int op4 = left.branchSum + right.branchSum + root->data;

	int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

	p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
	p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

	return p;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	node* root = buildTree();
	cout << maxSumPath(root).maxSum << endl;
		
}