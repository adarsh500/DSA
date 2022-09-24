#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int val){
		data = val;
		next = NULL;
	}
};

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
	cin >> num;
	node *head = NULL;
	while(num != -1){
		insertAtTail(head, num);
		cin >> num;
	}
	return head;
}

void print(node *head) {
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int kthNodeFromEnd(node*head, int k){
	node *fast = head;
	node *slow = head;
	int count = 0;
	while(count < k){
		fast = fast->next;
		count++;
	}

	while(fast != NULL){
		fast = fast->next;
		slow = slow->next;
	}

	return slow->data;
}

int main(){
	int k;
	node *ll = NULL;
	ll = take_input();
	cin >> k;
	// print(ll);
	cout << kthNodeFromEnd(ll, k) << endl;
}