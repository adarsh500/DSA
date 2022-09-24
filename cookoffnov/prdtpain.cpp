#include <bits/stdc++.h>
#define int long long
using namespace std;

//refer this link: https://www.geogebra.org/calculator/qntmdxyb
int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, ans = 0;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		//approach, set i and k (which will be iterated through 2 for loops)
		//and then find the optimal j for which the value of the function will be
		//maximum. From the above link, we can see that there will be one global
		//maxima for which j will give max value;
		//so we can find j using binary search using upper bound.
		//where j = (a[i] + a[k]) / 2

		for(int i = 0; i < n; i++){
			for(int k = i + 2; k < n; k++){
				auto f = [&](int j){
					return (arr[i] - arr[j]) * (arr[j] - arr[k]);
				};
				int j = upper_bound(arr.begin() + i, arr.begin() + k, (arr[i] + arr[k]) / 2) - arr.begin();
				j = min(j, k - 1);
				//just to make sure that j is not out of bounds
				ans += max(f(j), f(j - 1));
				//this is to check if we get the max value for j and j - 1
			}
		}
		cout << ans << "\n";
	}
	return 0;
}