#include <iostream>
using namespace std;

void countSort(long long int arr[], int n, int min, int max){
	int range = max - min + 1;
	int *freqArr = new int[range]{0};


	//counts the frequency of the array elements
	for (int i = 0; i < n; i++){
		int index = arr[i] - min;
		freqArr[index]++;
	}

	//prefix sum of freq array
	for (int i = 1; i < range; i++){
		freqArr[i] += freqArr[i - 1];
	}

	int *output = new int[n];
	for (int i = n - 1; i >= 0; i--){
		int val = arr[i];
		int pos = freqArr[val - min];
		int idx = pos - 1;
		output[idx] = val;
		freqArr[val - min]--;
	}

	for (int i = 0; i < n; i++){
		arr[i] = output[i];
	}
}

int main() {
	long long int n;
	cin >> n;

	long long int arr[n], smallest, largest;
	for (long long int i = 0; i < n; i++) {
		cin >> arr[i];
		smallest = min(smallest, arr[i]);
		largest = max(largest, arr[i]);
	}

	countSort(arr, n, smallest, largest);


	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}