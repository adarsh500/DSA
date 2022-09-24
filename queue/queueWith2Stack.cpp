#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class Queue{
	stack<T> s1, s2;

public:
	//same as that of queue
	void push(T val){
		s1.push(val);
	}

	void pop(){
		//assuming that you push elements to s1;
		while(s1.size() > 1){
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}

		s1.pop();
		while(!s2.empty()){
			T value = s2.top();
			s1.push(value);
			s2.pop();
		}
	}

	T front(){
		while(s1.size() > 1){
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}

		T front = s1.top();
		while(!s2.empty()){
			T value = s2.top();
			s1.push(value);
			s2.pop();
		}

		return front;
	}

	int size(){
		return s1.size();
	}

	bool empty(){
		return size() == 0;
	}
};

int main(){
	Queue<int> q;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		q.push(i);
	}

	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}