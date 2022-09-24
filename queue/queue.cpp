#include <iostream>
using namespace std;

class Queue{
	int *arr;
	int currentSize, maxSize, f, rear;

public:
	Queue(int defaultSize = 10){
		arr = new int[defaultSize];
		maxSize = defaultSize;
		currentSize = 0;
		f = 0, rear = maxSize - 1;
	}

	bool full(){
		return currentSize == maxSize;
	}

	bool empty(){
		return currentSize == 0;
	}

	void push(int data){
 		if (!full()){
 			rear = (rear + 1) % maxSize;
 			arr[rear] = data;
 			currentSize++;
 		}
	}

	void pop(){
		if(!empty()){
			f = (f + 1) % maxSize;
			currentSize--;
		}
	}

	int front(){
		return arr[f];
	}

	~Queue(){
		if(arr != NULL){
			delete [] arr;
			arr = NULL;
		}

	}
};

int main(){
	Queue q;


	for (int i = 0; i < 6; i++){
		q.push(i * i);
	}
	// cout << q.front() << endl;
	q.pop();
	q.push(69);

	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;


}