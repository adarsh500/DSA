#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;
		left = right = NULL;
	}
};

node* buildTreeFromTraversal(int *preorder, int* inorder, int start, int end){
	static int i = 0;

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
	i++;

	root->left = buildTreeFromTraversal(preorder, inorder, start, index - 1);
	root->right = buildTreeFromTraversal(preorder, inorder, index + 1, end);

	return root;
}


int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
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

// int largestBst(node* root){

// 	if(isBST(root,INT_MIN,INT_MAX)) 
//   	{	
//     	return height(root);
//   	}
//     return max(largestBst(root->left),largestBst(root->right));
// }

int sizeOfMaxBST(node *root)
{
    int maxSize = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (isBST(root))
    {
        maxSize = max(maxSize, height(root));
    }
    return max(maxSize, max(sizeOfMaxBST(root->left), sizeOfMaxBST(root->right)));
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
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
	cout << sizeOfMaxBST(root) << endl;

}