#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n){
	if (n == 1){
		return;
	}

	for (int j = 0; j < n - 1; j++){
		if (arr[j] > arr[j + 1]){
			swap(arr[j], arr[j + 1]);
		}
	}
	bubbleSort(arr, n - 1);
}

void bSort(int arr[], int n, int i){	
	if (n == 1)
		return;

	if (i == n - 1){
		//this means that we have done one full round of comparing
		//and swapping, and j has reached the end of the array
		return bSort(arr, n - 1, 0);
	}

	if (arr[i] > arr[i + 1]){
		swap(arr[i], arr[i + 1]);
	}
	bSort(arr, n, i + 1);
}		

int main(){
	int n;
	cin >> n;

	int arr[n];
	for(int i =0;i < n; i++){
		cin >> arr[i];
	}

	// bubbleSort(arr, n);
	bSort(arr, n, 0);


	for(int i =0;i < n; i++){
		cout << arr[i] << " ";
	}
}