#include <bits/stdc++.h>
using namespace std;


bool reachEnd(vector<vector<int>> arr, int i, int j, int n) {
	if (i == n && j == n) {
		return true;
	}

	if (arr[i][j] == 1) {
		return false;
	}

	if (i > n || j > n) {
		return false;
	}

	// while(i < n && j < n){
	bool down = reachEnd(arr, i + 1, j, n);
	bool right = reachEnd(arr, i, j + 1, n);
	// }
	if (down || right) {
		return true;
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> arr;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 0;
			}
		}
		int temp = n;
		while (temp--) {
			int x, y;
			cin >> x >> y;
			arr[x - 1][y - 1] = 1;
		}

		if (reachEnd(arr, 0, 0, n)) {
			cout << "Yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

}