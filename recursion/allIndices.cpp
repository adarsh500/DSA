#include <iostream>
using namespace std;

void allIndices(int *arr, int n, int key, int i) {
	if (i == n) {
		return;
	}

	if (arr[i] == key) {
		cout << i << " ";
	}

	allIndices(arr, n, key, i + 1);
}

int main() {
	int n, key;
	cin >> n;

	int arr[1000005];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> key;

	allIndices(arr, n, key, 0);
	cout << endl;
}