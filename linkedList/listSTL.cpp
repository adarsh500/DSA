#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> l1{1,2 ,3, 4, 5, 6};
	list<string> l2{"apple", "guava", "banana", "mango"};

	//insert at tail

	l2.push_back("pineapple");

	l2.sort();
	l2.reverse();
	l2.pop_front();
	l2.push_front("dragonfruit");
	l2.push_back("guava");

	for(auto s: l2){
		cout << s << " ";
	}
	cout << endl;

	l2.remove("guava");
	//here we can see that remove removes all occurences of the given item
	for(auto s: l2){
		cout << s << " ";
	}
	cout << endl;

	auto it = l2.begin();
	it++;
	it++;
	//we can see that is below statement removes the third
	//element from the array
	l2.erase(it);

	for(auto s: l2){
		cout << s << " ";
	}
	cout << endl;

	it = l2.begin();
	it++;
	l2.insert(it, "peach");

	for(auto s: l2){
		cout << s << " ";
	}
	cout << endl;

}


