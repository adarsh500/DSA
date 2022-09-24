#include <iostream>
#include <algorithm>
using namespace std;


//unique thing about quicksort is that the sorting takes place inplace,
//i.e no extra array required

int partition(int arr[], int start, int end){

	int i = start - 1, j = start;

	int pivot = arr[end];

	for ( ; j <= end; j++){
		if (arr[j] < pivot){
			i += 1;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[end]);

	return i + 1;
}

void quickSort(int arr[], int start, int end){

	if (start >= end){
		return;
	}

	int pivot = partition(arr, start, end);

	//left part of the pivot
	quickSort(arr, start, pivot - 1);

	//right part of the pivot
	quickSort(arr, pivot + 1, end);
}

int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	quickSort(arr, 0, n -1);

	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}