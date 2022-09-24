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

void print(node *head) {
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void insertAtTail(node*&head, int val){
	if (head == NULL){
		head = new node(val);
		return;
	}

	node *n = head;
	while(n->next != NULL){
		n = n->next;
	}
	n->next = new node(val);
}

node *midpoint(node *head){
	if (head == NULL or head->next == NULL){
		return head;
	}
	node *fast = head->next;
	node *slow = head;
	while(fast != NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* merge(node*list1, node*list2){
	if (list1 == NULL){
		return list2;
	} 
	if (list2 == NULL){
		return list1;
	}
	node *output = NULL;

	if (list1->data < list2->data){
		output = list1;
		output->next = merge(list1->next, list2);
	} else {
		output = list2;
		output->next = merge(list1, list2->next);
	}
	return output;
}

node* mergeSort(node*head){
	if (head == NULL or head->next == NULL){
		return head;
	}

	node *mid = midpoint(head);
	node *a = head;
	node *b = mid->next;
	
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node *c = merge(a, b);
	return c;
}

int main(){
	int n, temp, num;
	node *head = NULL;
	node *ans = NULL;
	cin >> n;
	temp = n;
	while(temp--){
		cin >> num;
		insertAtTail(head, num);
	}

	ans = mergeSort(head);
	print(ans);
	// print(head);
}