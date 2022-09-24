//problem on spoj

#include <iostream>
using namespace std;

bool canMakeParatha(long long int arr[], long long int mid, long long int p, long long int n) {
	long long int prata = 0, time = 0;
	for (long long int i = 0; i < n; i++) {
		long long int time = arr[i], k = 2;
		while (time <= mid) {
			time += k * arr[i];
			prata++;
			k++;
		}
		if (prata >= p)
			return true;
	}
	return false;
}

int main() {
	long long int t;
	cin >> t;
	while (t--) {
		long long int p;
		cin >> p;

		long long int n;
		cin >> n;

		long long int arr[n], maxRank;
		for (long long int i = 0; i < n; i++)
			cin >> arr[i];

		for (long long int i = 0; i < n; i++)
			maxRank = max(maxRank, arr[i]);

		long long int start = 0, end = maxRank * ((p * (p + 1)) / 2), mid, ans;
		while (start <= end) {
			mid = (start + end) / 2;
			if (canMakeParatha(arr, mid, p, n)) {
				ans = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}