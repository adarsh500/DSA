#include <iostream>
#include <set>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int arr[] = {1, 8 ,23, 5, 9 , 10, 12, 4, 2, 4};
	int n = sizeof(arr)/sizeof(int);

	set<int> s;

	for(int i = 0; i < n; i++){
		s.insert(arr[i]);
	}

	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout << *(it) << " ";
	}
	cout << endl;


	// s.erase(4);

	// or

	set<int>::iterator i = s.find(4);
	s.erase(i);

	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout << *(it) << " ";
	}
	cout << endl;
}