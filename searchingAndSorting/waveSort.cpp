#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < n; i += 2){

		//previous element
		if (i != 0 and arr[i] < arr[i - 1]){
			swap(arr[i], arr[i - 1]);
		}

		if (i != n - 1 and arr[i] < arr[i + 1]){
			swap(arr[i], arr[i + 1]);
		}
	}

	for (int i = 0; i < n; i++){
		cout << arr[i];
	}
}