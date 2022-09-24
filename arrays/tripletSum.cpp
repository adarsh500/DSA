#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, key;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> key;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int left = i + 1, right = n - 1, sum = key - arr[i];
		while (left < right) {
			if (sum < arr[left] + arr[right]) {
				right--;
			} else if ( sum > arr[left] + arr[right]) {
				left++;
			} else {
				cout << arr[i] << ", " << arr[left] << " and " << arr[right] << endl;
				left++;
				right--;
			}
		}
	}
}