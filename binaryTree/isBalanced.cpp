

// Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.
// Input Format

// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
// Constraints

// 1 <= No of nodes <= 10^5
// Output Format

// Display the Boolean result
// Sample Input

// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

// Sample Output

// true

// Explanation

// The tree looks like

//                  10
//               /       \
//            20           30
//         /     \       /     \
//        40      50    60      73

// The given tree is clearly balanced as depths of the left and right sub-trees of every node differ by 1 or less.


#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isHeightBalancedOptimised(node *root)
{
    pair<int, bool> p;
    if (root == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> left = isHeightBalancedOptimised(root->left);
    pair<int, bool> right = isHeightBalancedOptimised(root->right);

    p.first = max(left.first, right.first) + 1;

    if (abs(left.first - right.first) <= 1 && left.second && right.second){
        p.second = true;
    } else {
        p.second = false;
    }

    return p;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    node *root = build("true");

    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}
