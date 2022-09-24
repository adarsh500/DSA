#include <bits/stdc++.h>
using namespace std;

class Student{
public:
	string firstName;
	string lastName;
	string rollNo;

	Student(string f, string l, string rno){
		firstName = f;
		lastName = l;
		rollNo = rno;
	}

	bool operator==(const Student &s) const{
		return rollNo == s.rollNo;
	}
};

class hashFn{
public:
	size_t operator()(const Student &s) const{
		return s.firstName.length() + s.lastName.length();
	}
};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	unordered_map<Student, int, hashFn> studentMap;
	Student s1("Prateek", "Narang", "010");
	Student s2("Rahul", "Kumar", "023");
	Student s3("Prateek", "Gupta", "030");
	Student s4("Rahul", "Kumar", "120"); 

	studentMap[s1] = 100;
	studentMap[s2] = 120;
	studentMap[s3] = 11;
	studentMap[s4] = 45;


	for(auto s: studentMap){
		cout << s.first.firstName << ": " << s.first.rollNo << " " << "Marks: " << s.second << endl;
	}
}