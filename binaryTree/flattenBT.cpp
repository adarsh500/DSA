#include <iostream>
#include<queue>
#include<climits>
#define ll long long int
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class LinkedList{
public:
    node* head;
    node* tail;
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

LinkedList flatten(node* root){
    LinkedList l;
    if (root == NULL){
        l.head = l.tail = NULL;
        return l;
    }

    //leaf node
    if (root->left == NULL && root->right == NULL){
        l.head = l.tail = root;
        return l;
    }

    //only left exists
    if (root->left != NULL && root->right == NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;

        return l;
    }

    //only right exists
    if (root->right != NULL && root->left == NULL){
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;

        return l;
    }

    //both left and right exists

    LinkedList rightLL = flatten(root->right);
    LinkedList leftLL = flatten(root->left);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;

    return l;

}

void bfs(node * root){
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

void build(node* &root){
    ll d,c1,c2;
    queue<node*> Q;

    cin>>d;
    root = new node(d);
    Q.push(root);
    while(Q.size() >= 1){
        node *n = Q.front();
        Q.pop();
        cin>>c1>>c2; // Children of n->data
        if(c1 != -1){
            n->left = new node(c1);
            Q.push(n->left);
        }
        if(c2 != -1){
            n->right = new node(c2);
            Q.push(n->right);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    node* root;
    build(root);
    bfs(root);
    cout << endl;

    LinkedList l = flatten(root); 
    node* temp = l.head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->right;
    }
}