#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int myCompare(string a, string b){
	cout << "comparing " << a + b << "and " <<b + a << endl; 
	return a + b > b + a;
}


int main() {
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		string arr[n];
		for (int i = 0; i < n; ++i){
		cin >> arr[i];
		}
		sort(arr, arr + n, myCompare);

		for (int i = 0; i < n; i++){
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}

