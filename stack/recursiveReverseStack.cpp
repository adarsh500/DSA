#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
	if (s.empty()){
		s.push(x);
		return;
	}

	int data = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(data);
}

void recursiveReverse(stack<int> &s){

	//base case 
	if (s.empty()){
		return;
	}
 	//pop out the top element of the stack and insert it at the bottom
 	//of the smaller reversed stack
 	int x = s.top();
 	s.pop();
 	//recursively reverse the smaller stack
 	recursiveReverse(s);
 	insertAtBottom(s, x);
}
 
int main(){
	stack<int> s;
	int n, num;
	cin >> n;

	while(n--){
		cin >> num;
		s.push(num);
	}

	recursiveReverse(s);

	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
}