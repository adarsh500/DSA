#include <iostream>
using namespace std;

int main(){
	int n, p;
	cin >> n >> p;

	int arr[100000];
	int freq[100000] = {};
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++){
		freq[arr[i]]++;
	}

	for (int i = 1; i <= n; i++){
		 cout << freq[i];
	}
}