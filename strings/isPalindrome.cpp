#include <iostream>
using namespace std;

bool palindrome(int arr[], int start, int end){
	if(arr[start] == arr[end]){
		start++;
		end--;
		palindrome(arr, start, end);
		return true;
	} else {
		return false;
	}
}

int main() {
	int n;
	cin >> n;

	if(n <= 1){
		cout << "true";
		return 0;
	}

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	if (palindrome(arr, 0, n - 1)){
		cout << "true";
	} else {
		cout << "false";
	}
	return 0;
}