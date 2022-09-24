#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define MOD LLONG_MAX

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE	
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll left, right;
		cin >> left >> right;
		vector<ll> arr(n);
		for(ll i = 0; i < n; i++){
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		ll count = 0;
		for(auto y: arr){
			ll lengthOfY = log10(y) + 1;//trick;
			ll denominator = pow(10ll, lengthOfY);
			ll R = (right - y) / denominator;// for right, this will automatically 
			//calculate the floor value

			ll L = (left - y + denominator - 1ll) / denominator;
			//for left, this will automatically calculate the ceit value;
			count += upper_bound(arr.begin(), arr.end(), R) - lower_bound(arr.begin(), arr.end(), L);
		}
		cout << count << "\n";
	}
}