#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void print(node*head){
	node *temp = head;
	while(temp->next != head){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
	return;
}

node* getNode(node*head, int data){
	node *temp = head;

	//checking for all nodes except last node
	while(temp->next != head){
		if (temp->data == data){
				return temp;
		}
		temp = temp->next;
	}

	//checking for last node
	if(temp->data == data){
		return temp;
	}

	return NULL;
}

void deleteNode(node*&head, int data){
	node *del = getNode(head, data);
	if (del == NULL){
		return;
	}

	if(head == del){
		head = head->next;
	}

	node *temp = head;
	while(temp->next != del){
		temp = temp->next;
	}
	temp->next = del->next;
	delete del;
}

void insertAtHead(node*&head, int val){
	node *n = new node(val);
	node *temp = head;


	n->next = head;

	if (temp != NULL){
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = n;
	} else {
		n->next = n;
	}
	head = n;
}


int main(){
	node *circList = NULL;
	insertAtHead(circList, 1);
	insertAtHead(circList, 5);
	insertAtHead(circList, 7);
	insertAtHead(circList, 9);
	insertAtHead(circList, 8);
	insertAtHead(circList, 4);
	deleteNode(circList, 9);
	print(circList);
}