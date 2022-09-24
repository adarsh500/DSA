#include <iostream>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}

};

void print(node *head) {
	while(head != NULL){
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
}

int length(node *head){
	int count = 0;
	while (head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

void insertAtHead(node*&head, int d) {
	if (head == NULL) {
		//so if head points to null, we are creating a new node
		//and the address of the new node is automatically stored in head
		head = new node(d);
		return;
	}

	/*and if head is not null, then you are creating a new nodel n. And
	we are storing the n.next = head. this links the already existing head
	to the new node and hence the list grows. After that we are storing the
	address of the newly created node n in head :)*/
	node *n = new node(d);
	n->next = head; // note: n->next is same as (*n).next, *n because n s
	//stores the address
	head = n;
}

node* take_input(){
	int num;
	node *head = NULL;
	while(cin >> num){
		insertAtHead(head, num);
	}
	return head;
}

ostream& operator<<(ostream &os, node*head){
	print(head);
	return os;
}

istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}

/*here we are passing the head by reference and not value because,
we are making changes to the head, and we want the changes to be relected
int the main function
*/



void insertAtTail(node*&head, int d){
	if (head == NULL){
		head = new node(d);
		return;
	}
	//since we dont maintain a tail element as such, we can point the tail
	//to head, and we can interate through the next such that we reach the
	//last element of the linked list
	node *tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = new node(d);
	return;
}

void insertAtMiddle(node*&head, int d, int position){
	if(head == NULL or position == 0){
		insertAtHead(head, d);
		return;
	} else if (position > length(head)){
		insertAtTail(head, d);
	} else {
		//take position-1 jumps to reach the node where you wanna insert
		int jump = 1;
		node *temp = head;
		while (jump <= position - 1){
			temp = temp->next;
			jump++;
		}
		//create a new node
		node *n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

void deleteHead(node*&head){
	if (head == NULL){
		return;
	}
	node *temp = head->next;
	delete head;
	head = temp;
}

void deleteMiddle(node*&head, int position){
	int jump = 0;
	node *n = head;
	node *prev = head;
	while(jump < position){
		n = n->next;
		jump++;
	}
	jump = 0;
	while(jump < position - 1){
		prev = prev->next;
		jump++;
	}
	prev->next = n->next;
	delete n;

}

void deleteTail(node*&head){
	if (head == NULL){
		return;
	}
	int count = 1;
	node *tail = head;
	node *prev = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	while (count < length(head) - 1){
		prev = prev->next;
		count++;
	}
	prev->next = NULL;
	delete tail;
}

bool search(node*head, int key){
	node *temp = head;
	while(temp != NULL){
		if(temp->data == key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool recursiveSearch(node*head, int key){
	// node *temp = head;
	if (head == NULL){
		return false;
	}

	if(head->data == key){
		return true;
	} else {
		return recursiveSearch(head->next, key);
	}

}
//you can also use this type of method to take input of linked list
// void input(node*&head){

// }

// node* take_input(){
// 	int num;
// 	cin >> num;
// 	node *head = NULL;
// 	while(num != -1){
// 		insertAtHead(head, num);

// 		cin >> num;
// 	}

// 	return head;
// }

// you can take an input from a file like this. use this command while
// running './linkedList < input.txt'



//overloading >> and << operators

// void operator<<(ostream &os, node*head){
// 	print(head);
// }

node *recReverse(node*&head){
	if (head->next == NULL or head == NULL){
		return head;
	}
	node *shead = recReverse(head->next);
	
	node *temp = head->next;
	temp->next = head;
	head->next = NULL;
	return shead;
}

// runner technique
/* so in a horse race, you have 2 horses, one races at 2x speed and
other races at x speed. So if we go by this, when the faster horse is
at end point, then the slower horse will be at midpoint
*/
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

//kth node from the end of linked list
void kthNode(node *head, int k){
	node *fast = head;
	node *slow = head;
	int count = 0;
	while(count < k){
		fast = fast->next;
		count++;
	}
	count = 0;
	while (fast != NULL){
		slow = slow->next;
		fast = fast->next;
	}
	cout << slow->data << endl;
	return;
}



int main() {
	node *head = NULL;
	int k;
	// insertAtHead(head, 3);
	// insertAtHead(head, 2);
	// insertAtHead(head, 1);
	// insertAtHead(head, 0);
	// insertAtMiddle(head, 5, 3);
	// insertAtTail(head, 7);
	// insertAtTail(head, 9);

	// deleteTail(head);
	// print(head);

	// deleteMiddle(head, 3);
	// print(head);

	// int key;
	// cin >> key;

	// // if (search(head, key)){
	// if (recursiveSearch(head, key)) {
	// 	cout << "Element found" << endl;
	// } else {
	// 	cout << "Element not found" << endl;
	// }
	// node*head = take_input();
	cin >> k;
	cin >> head;	
	kthNode(head, k);
	// print(head);
	cout<<head;

}