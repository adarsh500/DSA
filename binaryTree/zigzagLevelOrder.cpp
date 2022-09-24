

// Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.
// Input Format

// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
// Constraints

// None
// Output Format

// Display the values in zigzag level order in which each value is separated by a space
// Sample Input

// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

// Sample Output

// 10 30 20 40 50 60 73 



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

int height(node* root){
	if (root == NULL){
		return 0;
	}

	int left = height(root->left);
	int right = height(root->right);
	return max(left, right) + 1;
}

void printKthlevel(node* root, int k, int level){
	if (root == NULL){
		return;
	}

	if (k == 1){
		cout << root->data << " ";
	}

	if (level&1){
		printKthlevel(root->left, k - 1, level);
		printKthlevel(root->right, k - 1, level);
	} else {
		printKthlevel(root->right, k - 1, level);
		printKthlevel(root->left, k - 1, level);
	}
}

node* buildTree(){
	int d;
	cin >> d;
	node* root = new node(d);
	string left, right;
	cin >> left;
	if (left == "true"){
		root->left = buildTree();
	} 
	cin >> right;
	if (right == "true"){
		root->right = buildTree();
	}

	return root;
}

void bfs2(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* front = q.front();
		if (front == NULL){
			cout << endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		} else {
			cout << front->data << " ";
			q.pop();

			if (front->left){
				q.push(front->left);
			} 

			if (front->right){
				q.push(front->right);
			}
		}
	}
}

void zigzagPrint(node * root){
	int h = height(root);

	for(int i = 1; i <= h; i++){
		printKthlevel(root, i, i);
	}
	// return;
}

int main(){
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
 //    #endif
	node* root = buildTree();
	zigzagPrint(root);
	cout << endl;
}