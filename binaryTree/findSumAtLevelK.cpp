

// Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.
// Input Format

// Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.
// Constraints

// 1 <= Nodes in tree <=1000
// 1<K<10
// Output Format

// A single line containing the sum at level K.
// Sample Input

// 1 2
// 2 2
// 3 0
// 4 0
// 5 2
// 6 0
// 7 0
// 2

// Sample Output

// 20

// Explanation

// Here the tree looks like

//                      1                                 Level 0
//                 /          \
//               2              5                         Level 1
//            /      \       /     \
//           3       4      6        7                    Level 2

// Sum at Level 2 = 3 + 4 + 6 + 7 = 20

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


node* buildTree(){
    int d, child;
    cin >> d >> child;
    node* root = new node(d);
    if (child == 2){
        root->left = buildTree();
        root->right = buildTree();
    } else if (child == 1){
        root->left = buildTree();
    } else {
        root->left = root->right = NULL;
    }
    return root;
}

int sumAtKLevel(node* root,int k){
    if (root == NULL){
        return 0;
    }

    if (k == 0){
        return root->data;
    } 

    int leftSum = sumAtKLevel(root->left, k - 1);
    int rightSum = sumAtKLevel(root->right, k - 1);

    
    return leftSum + rightSum;
}


int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    node*root = buildTree();
    int k;
    cin >> k;
    cout << sumAtKLevel(root, k) << endl;
}
