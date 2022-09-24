#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] > key) {
			return binarySearch(arr, key, start, mid - 1);
		} else {
			return binarySearch(arr, key, mid + 1, end);
		}
	}
	return -1;

}


int main() {
	int n, key;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> key;

	cout << binarySearch(arr, key, 0, n - 1) << endl;
	return 0;
}