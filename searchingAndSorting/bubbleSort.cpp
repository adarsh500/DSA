// #include <bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n;
// 	cin >> n;

// 	if (n < 1){
// 		return 0;
// 	}

// 	long long arr[n];
// 	for (int i = 0; i < n; i++){
// 		cin >> arr[i];
// 	}

// 	for (int i = 0; i < n - 1; i++){
// 		for (int j = 0; j < n - i - 1; j++){
// 			if (arr[i] > arr[i + 1]){
// 				// swap(arr[i] > arr[i + 1]);
// 				long long temp = arr[i];
// 				arr[i] = arr[i + 1];
// 				arr[i + 1] = temp;
// 			}
// 		}
// 	}
// 	for (int i = 0; i < n; i++){
// 		cout << arr[i] << endl;
// 	}
// 	return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// void swap(long long *xp, long long *yp)
// {
// 	int temp = *xp;
// 	*xp = *yp;
// 	*yp = temp;
// }

// void bubbleSort(long long arr[], int n)
// {
// 	int i, j;
// 	for (i = 0; i < n - 1; i++)
// 		for (j = 0; j < n - i - 1; j++)
// 			if (arr[j] > arr[j + 1])
// 				swap(&arr[j], &arr[j + 1]);
// }


// int main()
// {
// 	int n;
// 	cin >> n;

// 	long long arr[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}

// 	bubbleSort(arr, n);
// 	for (int i = 0; i < n; i++)
// 		cout << arr[i] << endl;

// 	return 0;
// }


#include <iostream>
using namespace std;

int main() {
	long long int n;
	cin >> n;
	long long int i, j, k;
	long long int arr[n];

	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				k = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = k;
			}
		}
	}

	for (i = 0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
}