#include <bits/stdc++.h>
using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int n;
	cin >> n;
	int arr[n], sum = 0, leftSum = 0, rightSum = 0, block, j = 1;
	int leftCount = 0, rightCount = n, transfer, rounds = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum % n == 0) {
		rightSum = sum;
		block = sum / n;
		for (int i = 0; i < n; i++) {
			leftSum += arr[i];
			rightSum -= arr[i];
			leftCount++;
			rightCount--;

			if ((block * leftCount) - leftSum >= 0) {
				transfer = ((block * leftCount) - leftSum);
			} else {
				transfer = abs(leftSum - (block * leftCount));
			}

			rounds = max(transfer, rounds);
		}
		cout << rounds << endl;
	} else {
		cout << -1 << endl;
	}
}