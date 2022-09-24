#include <bits/stdc++.h>
using namespace std;

void insertionSort(long long int arr[], long long int n){
	for (int i = 1; i < n; i++){
		int e = arr[i];
		int j = i - 1;
		while (j >= 0 and arr[j] > e){
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = e;
	}
}

int main()
{
	long long int n;
	cin >> n;

	long long int arr[n];
	for (long long int i = 0; i < n; i++)
		cin >> arr[i];
	insertionSort(arr, n);

	for (int i=0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}