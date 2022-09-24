#include <iostream>
#include <queue>
// #include <pair>
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

class Pair{
public:
	int height;
	int diameter;
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

//this is preorder
void print(node* root){
	if (root == NULL){
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

void printInorder(node* root){
	if (root == NULL){
		return;
	}

	print(root->left);
	cout << root->data << " ";
	print(root->right);
}

void printPostorder(node *root){
	if (root == NULL){
		return;
	}
	print(root->left);
	print(root->right);
	cout << root->data << " ";
}

int height(node* root){
	if (root == NULL){
		return 0;
	}

	int rightNode = height(root->right);
	int leftNode = height(root->left);
	return (max(rightNode, leftNode) + 1);
}

void printKthLevel(node* root, int k){
	if (root == NULL){
		return;
	}
	if (k == 1){
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
	return;
}

void printAllLevels(node* root){

	//worst case O(n^2)
	int h = height(root);

	for(int i = 1; i <= h; i++){
		printKthLevel(root, i);
		cout << endl;
	}
}

void bfs(node *root){
	queue<node *> q;
	q.push(root);

	while(!q.empty()){
		node * f = q.front();
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

// int diameter(node* root){
// 	//worst case O(n^2)
// 	//each height function call is O(n)
// 	// you have 3 cases, 1. the diameter passes through the root, 
// 	// 2. the diameter lies on the left tree, 3. it lies on the right tree

// 	// if it is case1, then count the height of the left and right tree,
// 	// then, diameter = height(left) + height(right)
	
// 	if (root == NULL){
// 		return 0;
// 	}

// 	int leftHeight = height(root->left);
// 	int rightHeight = height(root->right);
// 	int case1 = leftHeight + rightHeight;
// 	int case2 = diameter(root->left);
// 	int case3 = diameter(root->right);

// 	return max(case1, max(case2, case3));
// }

//this returns the diameter but with better complexity O(n)
//we use a postorder traversal for this, and in this method we store 
//the height and the diameter for each node
Pair diameter(node * root){
	Pair p;
	if (root == NULL){
		p.diameter = p.height = 0;
		return p;
	}
	Pair left = diameter(root->left);
	Pair right = diameter(root->right);
	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}

//prints the sum of child nodes
int sumOfChildNodes(node* root){
	if (root == NULL){
		return 0;
	}

	if (root->left == NULL && root->right == NULL){
		return root->data;
	}
	
	int leftSum = sumOfChildNodes(root->left);
	int rightSum = sumOfChildNodes(root->right);
	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

//height balanced tree is a tree where the height of the left sub-tree and 
//the height of the right sub-tree is taken. The difference between the 2
//must be <= 1. AT EVERY NODE
class balancePair{
public:
	int height;
	bool balance;
};

balancePair heightBalanced(node* root){
	balancePair p;
	if (root == NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}

	balancePair left = heightBalanced(root->left);
	balancePair right = heightBalanced(root->right);

	p.height = max(left.height, right.height) + 1;
	if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
		p.balance = true;
	} else {
		p.balance = false;
	}

	return p;
}

//create a balanced tree. NOTE: height of a balanced tree: log(N)
node* buildBalancedTree(int arr[], int start, int end){
	if (start > end){
		return NULL;
	}

	int mid = (start + end) / 2;
	node* root = new node(arr[mid]);
	root->left = buildBalancedTree(arr, start, mid - 1);
	root->right = buildBalancedTree(arr, mid + 1, end);

	return root;
}

//you will either be given inorder + preorder or something else
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
		if (preorder[i] == inorder[j]){
			index = j;
			break;
		}
	}
	i++;

	root->left = createTreeFromTraversal(inorder, preorder, start, index - 1);
	root->right = createTreeFromTraversal(inorder, preorder, index + 1, end);
	return root;
}

void rightView(node* root, int level, int &maxlevel){
	if (root == NULL){
		return;
	}

	if (level > maxlevel){
		cout << root->data << " ";
		maxlevel = level;
	}

	rightView(root->right, level + 1, maxlevel);
	rightView(root->left, level + 1, maxlevel);
}

void printAtLevelK(node* root, int k){
	if (root == NULL){
		return;
	}

	if (k == 0){
		cout << root->data << " ";
		return;
	}

	printAtLevelK(root->left, k - 1);
	printAtLevelK(root->right, k - 1);
}

int printAtDistancek(node* root, node* target, int k){
	//base case 
	if (root == NULL){
		return -1;
	}

	if (root == target){
		printAtLevelK(target, k);
		return 0;
	}

	//when we are at some ancestor node
	int leftDistance = printAtDistancek(root->left, target, k);

	//if leftDist == -1, then the target is not present
	if (leftDistance != -1){
		//now there will be 2 more cases
		if (leftDistance + 1 == k){
			cout << root->data << " ";
		} else {
			printAtLevelK(root->right, k - 2 - leftDistance);
		}

		return 1 + leftDistance;
	} 

	int rightDistance = printAtDistancek(root->right, target, k);
	if (rightDistance != -1){

		if (rightDistance + 1 == k){
			cout << root->data << " ";
		} else {
			printAtLevelK(root->right, k - 2 - rightDistance);
		}

		return 1 + rightDistance;
	}

	return -1;
}

//this function prints the elements of a level in a new line
void bfs2(node * root){
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

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	node * root = buildTree();

	return 0; 
}