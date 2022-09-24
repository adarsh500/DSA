#include <bits/stdc++.h>
using namespace std;

class Person{
public:
	string name;
	int age;

	Person(){}

	Person(string n, int a){
		name = n;
		age = a;
	}
};

class PersonCompare{
public: 
	bool operator()(Person a, Person b){
		return a.age < b.age;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int n;
	cin >> n;

	priority_queue<Person, vector<Person>, PersonCompare> pq;
	//Here Person<compare> is a class and not a function call

	for(int i = 0; i < n; i++){
		string n;
		int a;
		cin >> n >> a;
		Person p(n, a);
		pq.push(p);
	}

	while(!pq.empty()){
		Person p = pq.top();
		cout << p.name << " " << p.age << endl;
		pq.pop(); // popping takes log(N);
	}
}