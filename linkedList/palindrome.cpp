#include <iostream>
using namespace std;

class node {
public:
	int data;
	node *next;
	node *prev;

	node(int val){
		data = val;
		next = NULL;
		prev = NULL;
	}
};

void insertAtTail(node*&head, int val){
	if (head == NULL){
		head = new node(val);
		return;
	}

	node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node *tail = new node(val);
	tail->next = NULL;
	temp->next = tail;
	tail->prev = temp;
}

void print(node*head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

bool isPalindrome(node*head){
	node* left = head;
	node* right = head;
	while(right->next != NULL){
		right = right->next;
	}	
	while(left < right){
		if (left->data == right->data){
			left = left->next;
			right = right->prev;
		} else {
			return false;
		}
	}
	return true;
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

	if(isPalindrome(list)){
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}