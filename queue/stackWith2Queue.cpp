#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack{
	queue<T> q1, q2;

public: 
	void push(T val){
		q1.push(val);
	}

	void pop(){
		/*first remove the last element that we added in q1.
		then move the first n - 1 elements from q1 to q2.
		interchange the names of q1 and q2;
		*/

		//this is assuming that q1 is where we push our elements
		//and q2 is the empty queue;

		if (q1.empty()){
			return;
		}

		while(q1.size() > 1){
			T val = q1.front();
			q2.push(val);
			q1.pop();
		}

		//this removes the last element
		q1.pop(); 


		//swap names of q1 and q2;
		// queue<T> temp = q1;
		// q1 = q2; 
		// q2 = temp;
		swap(q1, q2);
	}

	T top(){
	
		while(q1.size() > 1){
			T val = q1.front();
			q2.push(val);
			q1.pop();
		}

		//this removes the last element
		T element = q1.front();
		q1.pop();
		q2.push(element);

		swap(q1, q2);
		return element;
	}

	int size(){
		return q1.size() + q2.size();
 	}

 	bool empty(){
 		return size() == 0;
 	}
};


int main(){
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);


	cout << s.top() << endl;

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}