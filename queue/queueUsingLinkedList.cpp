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



class Queue{
	node *front = NULL;
	node *rear = NULL;

public:
	Queue(){
		front = rear = NULL;
	}

	int size(){
		if (front == NULL){
			return 0;
		}
		return rear - front;
	}

	bool empty(){
		return (front == NULL);
	}

	void push(int val){
		if(front == NULL and rear == NULL){
			front = rear = new node(val);
			return;
		}

		rear->next = new node(val);
		rear = rear->next;
	}

	void pop(){
		if (front == NULL){
			return;
		}

		node* temp = front;
		front = front->next;

		delete(temp);
	}

	void print(){
		if (front == NULL and rear == NULL){
			return;
		}
		while(!empty()){
			cout << front->data << " ";
			front = front->next;
		}
	}
};

int main(){
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.print();
	q.pop();
	q.push(6996);
	q.print();
}