#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int ans(vector<int> &A, int B){
	int sum = 0, maxSum = -999999, minDiff = 999999;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++){
        int left = i + 1, right = A.size() - 1; sum = A[i] + A[left] + A[right];
        while (left < right){
            int diff = abs(B - sum);
            if (sum > maxSum and diff < minDiff){
                maxSum = sum;
                minDiff = diff;
                left++;
            } else {
                right--;
            }
        }
    }
    return maxSum;
}

int main() {
	int n, key;
	cin >> n >> key;
	vector<int> A;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cout << ans(A, key) << endl;

	// sort(arr, arr + n);

	// for (int i = 0; i < n; i++) {
	// 	int left = i + 1, right = n - 1, sum = min(sum, key - arr[i]);
	// 	while (left < right) {
	// 		if (sum < arr[left] + arr[right]) {
	// 			right--;
	// 		} else if ( sum > arr[left] + arr[right]) {
	// 			left++;
	// 		} else {
	// 			cout << arr[i] << ", " << arr[left] << " and " << arr[right] << endl;
	// 			left++;
	// 			right--;
	// 		}
	// 	}
	// }
}