#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node* prev;

	node(int val){
		data = val;
		next = NULL;
		prev = NULL;
	}

};
void print(node *head) {
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void insertAtHead(node*&head, int val){
	node* n = new node(val);
	n->next = head;
	n->prev = NULL;

	if (head != NULL)
		head->prev = n;

	head = n;
}

void insertAtTail(node*&head, int val){
	if (head == NULL){
		head = new node(val);
		return;
	}
	// print(head);
	node* n = head;
	while(n->next != NULL){
		n = n->next;
	}
	node*tail = new node(val);
	tail->next = NULL;
	n->next = tail;
	tail->prev = n;
}		


void insertAt(node*&head, int position, int val){
	int count = 0;
	node *prev = head;
	while (count < position - 1){
		prev = prev->next;
		count++;
	}
	node *forward = prev->next;
	node *n = new node(val);
	prev->next = n;
	n->prev = prev;
	n->next = forward;
	forward->prev = n;
}


int main(){
	node* ll = NULL;
	int n, num;
	cin >> n;
	int temp = n;
	while(temp--){
		cin >> num;
   		insertAtTail(ll, num);
	}

	insertAt(ll, 3, 69);
	print(ll);
}