#include <bits/stdc++.h>
#define lli long long int
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	 ios_base::sync_with_stdio(false);
	     cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		lli n;
		cin >> n;
		lli ans = 1;
		ans = ((n - 2) * (n - 1) + 1);
		cout << ans << "\n";
	}

}