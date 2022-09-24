#include <iostream>
#include <list>
using namespace std;

class Queue{
	int currentSize;
	list<int> l;

public:
	Queue(){
		currentSize = 0;
	}

	bool empty(){
		return currentSize == 0;
	}

	void push(int data){
		l.push_back(data);
		currentSize++;
	}

	void pop(){
		if (!empty()){
			currentSize--;
			l.pop_front();
		}
	}


	int front(){
		return l.front();
	}
};

int main(){
	Queue q;
	for (int i = 0; i < 10; i++){
		q.push(i * i);
	}

	q.pop();
	cout << q.front() << endl;
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
}