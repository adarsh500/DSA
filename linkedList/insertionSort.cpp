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

void insertAfterNode(node*&head, int val){
	node* n = new node(val);
	node* temp = head;
	n->next = temp->next;
	temp->next = n;
	n->prev = temp;

	if (n->next != NULL){
		n->next->prev = n;
	}	
}

void insertionSort(node*&head){
	node *temp = head->next;
	node *prev = NULL;
	while(temp != NULL){
		prev = temp->prev;
		int num = temp->data;

		while (prev != NULL && prev->data > num){
			prev->next->data = prev->data;
			prev = prev->prev;
		} 

		if (prev == NULL){
			head->data = num;
		} else {
			prev->next->data = num;
		}

		temp = temp->next;
	}

}

int main(){
	int n, temp, num;
	node *list = NULL;
	cin >> n;
	temp = n;
	while(temp--){
		cin >> num;
		insertAtTail(list, num);
	}
	insertionSort(list);
	print(list);
}