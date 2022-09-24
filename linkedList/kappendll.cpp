#include <iostream>
using namespace std;

class node {
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void print(node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

ostream& operator<<(ostream &os, node *head) {
	print(head);
	return os;
}

void insertAtTail(node *&head, int val) {
	if (head == NULL) {
		head = new node(val);
		return;
	}

	node *tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new node(val);

	return;
}

node* kappend(node*head, int k, int n) {

	//handles cases where k is greater than n
	//very smort
	k = k%n;

	
	node* curr = head->next;
	node* prev = head;
	int count = 0;
	while (count < n - k - 1) {
		prev = prev->next;
		curr = curr->next;
		count++;
	}
	prev->next = NULL;

	node *temp = curr;
	count = 0;
	while (temp->next != NULL) {
		temp = temp->next;
		count++;
	}
	temp->next = head;

	return curr;
}

int main() {
	int n, temp, val, k;
	node *ll = NULL;
	node *ans;
	cin >> n;
	temp = n;
	while (temp--) {
		cin >> val;
		insertAtTail(ll, val);
	}
	cin >> k;
	if (k == n){
		ans = ll;
	} else {
		ans = kappend(ll, k, n);
	}
	cout << ans;
}