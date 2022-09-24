// #include <iostream>
// #include <climits>
// using namespace std;

// int main() {

// 	long long int n;
// 	cin >> n;
// 	long long int mini = LLONG_MAX;
// 	long long int arr[n];


// 	for (long long int i = 0; i < n; i++)
// 		cin >> arr[i];

// 	for (long long int i = 0; i < n - 1; i++) {
// 		long long int minIndex = i;
// 		for (long long int j = i + 1; j < n; j++) {
// 			if (arr[j] < mini) {
// 				mini = arr[j];
// 				minIndex = j;
// 			}
// 		}
// 		long long int temp = arr[i];
// 		arr[i] = arr[minIndex];
// 		arr[minIndex] = temp;
// 	}

// 	for (int i = 0; i < n; i++)
// 		cout << arr[i] << endl;
// }


#include <bits/stdc++.h>
using namespace std;

void swap(long long int *xp, long long int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(long long int arr[], long long int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}


int main()
{
	long long int n;
	cin >> n;

	long long int arr[n];
	for (long long int i = 0; i < n; i++)
		cin >> arr[i];
	selectionSort(arr, n);

	for (int i=0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
}

