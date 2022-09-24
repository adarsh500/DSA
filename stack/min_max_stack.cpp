#include <iostream>
#include <vector>
using namespace std;

class stack{
	vector<int> stack;
	vector<int> minStack;
	vector<int> maxStack;

public: 
	void push(int data){
		int currentMin = data;
		int currentMax = data;

		if (minStack.size()){
			currentMin = min(minStack[minStack.size() - 1], data);
			currentMax = max(maxStack[maxStack.size() - 1], data);
		}

		minStack.push_back(currentMin);
		maxStack.push_back(currentMax);
		stack.push_back(data);
	}

	int getMin(){
		return minStack[minStack.size() - 1];
	}

	int getMax(){
		return maxStack[maxStack.size() - 1];
	}

	int top(){
		return stack[stack.size() - 1];
	}

	bool empty(){
		return stack.size() == 0;
	}

	void pop(){
		stack.pop_back();
		minStack.pop_back();
		maxStack.pop_back();
	}
};

int main(){
	stack s;
	s.push(1);
	s.push(5);
	s.push(9);
	s.push(0);
	s.push(-1);
	cout << s.getMax() << " " << s.getMin() << " " << s.top() << endl;
	s.pop();
	cout << s.getMax() << " " << s.getMin() << " " << s.top() << endl;
	
}