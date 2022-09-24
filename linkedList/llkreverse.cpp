#include <iostream>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void print(node *head){
	while (head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void insertAtHead(node*&head, int val){
	if (head == NULL){
		head = new node(val);
		return;
	}
	node *n = new node(val);
	n->next = head;
	head = n;
}

void insertAtTail(node*&head, int val){
	if (head == NULL){
		head = new node(val);
		return;
	}

	node *tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = new node(val);
	return;
}

node* take_input(){
	int num;
	node *head = NULL;
	while(cin >> num){
		insertAtTail(head, num);
	}
	return head;
}
	
ostream& operator<<(ostream &os, node *head){
	print(head);
	return os;
}

node* reverse(node*&head, int k){
	int count = 0;
	node *prev = NULL;
	node *curr = head;
	node *next = NULL;
	while(curr != NULL and count < k){
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
		count++;
	}

	if (next != NULL){
		head->next = reverse(next, k);
	}

	return prev;
}


int main(){
	int n, k, num;
	cin >> n >> k;

	node *head;
	while(n--){
		cin >> num;
		insertAtTail(head, num);
	}
	cout << n;

	// cout << head;
	node *kreversed = reverse(head, k);
	cout << kreversed;
}