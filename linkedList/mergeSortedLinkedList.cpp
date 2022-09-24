#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void print(node *head){
	while (head != NULL){
		cout << head->data <<" ";
		head = head->next;
	}
	cout << endl;
}

// int length(node *head){
// 	int count = 0;
// 	while(head->next != NULL){
// 		count++;
// 		head = head->next;
// 	}
// 	return count;
// }

ostream& operator<<(ostream &os, node *head){
	print(head);
	return os;
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
	// cout << "added at tail " << "length: " << length(head) << endl;
	return;
}

// void insertAtHead(node*&head, int val){
// 	if (head == NULL){
// 		head = new node(val);
// 		return;
// 	}
// 	node *n = new node(val);
// 	n->next = head;
// 	head = n;
// }

// void deleteAtHead(node*&head){
// 	if (head == NULL){
// 		return;
// 	}
// 	node *n = head->next;
// 	delete head;
// 	head = n;
// }

// void insertAtMiddle(node*&head, int val, int position){
// 	if (position == 0 || head == NULL){
// 		insertAtHead(head, val);
// 		return;
// 	} else if (position > length(head)){
// 		insertAtTail(head, val);
// 	} else {
// 		int jump = 1;
// 		node *temp = head;
// 		while(jump <= position - 1){
// 			temp = temp->next;
// 			jump++;
// 		}
// 		node *n = new node(val);
// 		n->next = temp->next;
// 		temp->next = n;
// 	}
// }

node* merge(node*list1, node*list2){
	if (list1 == NULL){
		return list2;
	} 
	if (list2 == NULL){
		return list1;
	}
	node *output;

	if (list1->data < list2->data){
		output = list1;
		output->next = merge(list1->next, list2);
	} else {
		output = list2;
		output->next = merge(list1, list2->next);
	}
	return output;
}



int main(){
	int t;
	cin >> t;
	while(t--){
		int n1, n2, num, temp;
		node *list1 = NULL;
		node *list2 = NULL;
		node *ans = NULL;
		cin >> n1;
		temp = n1;
		while(temp--){
			cin >> num;
			insertAtTail(list1, num);
		}
		cin >> n2;
		temp = n2;
		while(temp--){
			cin >> num;
			insertAtTail(list2, num);
		}
        print(list1);
		ans = merge(list1, list2);
		cout << ans;
	}
}
