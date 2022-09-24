#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int val){
		data = val;
		next = NULL;
	}
};

void insertAtTail(node*&head,int val){
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

void print(node *head){
	while (head != NULL){
		cout << head->data <<" ";
		head = head->next;
	}
	cout << endl;
}

node* merge(node*&odd, node*&even, int oddCount, int evenCount){
	node *temp1 = even;
	node *temp2 = odd;
	while(temp1 != NULL){
		// cout << temp1->data << endl;
		temp1 = temp1->next;
	}
	while(temp2->next != NULL){
		// cout << temp2->data << endl;
		temp2 = temp2->next;
	}
	temp2->next = even;

	return odd;
}

int main(){
	int n, temp, num, oddCount = 0, evenCount = 0;
	node* odd = NULL;
	node* even = NULL;
	node *ans = NULL;
	cin >> n;
	temp = n;
	while(temp--){
		cin >> num;
		if ((num&1) == 1){
			insertAtTail(odd, num);
			oddCount++;
		} else {
			insertAtTail(even, num);
			evenCount++;
		}
	}

	ans = merge(odd, even, oddCount, evenCount);
	print(ans);

	// print(odd);
	// print(even);
}