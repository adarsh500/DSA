#include <iostream>
#include <vector>
using namespace std;


//you can either have one type of data or multiple types of data
template<typename T, typename U> 
class stack{
private:
	vector<T> v;
	vector<U> v1;

public:
	void push(T val){
		v.push_back(val);
	}

	T top(){
		return v[v.size() - 1];
	}

	bool empty(){
		return (v.size() == 0);
	}

	void pop(){
		if (!empty()){
			v.pop_back();
		}
	}
};

int main(){
	stack<char, int> s;
	for (int i = 65; i < 75; i++){
		s.push(i);
	}
	//while s is not empty
	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}