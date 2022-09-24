//you're given an array, you will have to find the number of pairs
//which satisfy the following condition:-
// arr[i] > arr[j] when i < j


#include <iostream>
using namespace std;

int merge(int * arr, int start, int end){
	if (start > end){
		return 0;
	}

	int mid = (start + end) / 2, count = 0;

	int i = start;
	int k = start;
	int j = mid + 1;
	int temp[100];


	while (i <= mid and j <= end){
		if (arr[i] <= arr[j]){
			temp[k++] = arr[i++]; 
		} else {
			temp[k++] = arr[j++];
			count += mid - i + 1;
		}
	}
	while (i <= mid){
		temp[k++] = arr[i++];
	}
	while (j <= end){
		temp[k++] = arr[j++];
	}

	for (int i = 0; i <= end; i++){
		arr[i] = temp[i];
	}

	return count;
}


int count(int * arr, int start, int end){
	if (start >= end){
		return 0;
	}
	
	int mid = (start + end) / 2;

 	int x = count(arr, start, mid);
 	int y = count(arr, mid + 1, end);
 	int z = merge(arr, start, end);
 	return x + y + z;
}

int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << count(arr, 0, n-1) << endl;
} 