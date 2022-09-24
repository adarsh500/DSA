#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	map<int, int> m;
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	int maxi = INT_MIN, ans;
	for(auto it = m.begin(); it != m.end(); it++){
		auto p = *it;
		if (p.second > maxi){
			maxi = p.second;
			ans = p.first;
		}
	}

	cout << ans << endl;
}