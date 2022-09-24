#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t, n;
	cin >> t;
	while (t--) {
		ll arr[100000] = {0};
		// memset(arr, 0, sizeof(arr));
		string name;
		ll n, rank;
		cin >> n;

		for (ll i = 0; i < n; i++) {
			cin >> name >> rank;
			arr[rank]++;
		}

		ll actual_rank = 1, sum = 0;
		for (ll i = 1; i < n; i++) {
			while (arr[i]) {
				sum += abs(actual_rank - i);
				arr[i]--;
				actual_rank++;
			}
		}

		cout << sum << "\n";
	}
}

// // void badness(vector<pair<string, ll>> v, ll n){
// ll badness(vector<ll> v, ll n){
// 	ll badness = 0;
// 	ll freq[n];
// 	for(ll i = 0; i < n; i++){
// 		freq[i] = 0;
// 	}



// 	//applying count sort as the range of numbers is short
// 	for(ll i = 0; i <= n; i++){
// 		ll p = v[i];
// 		freq[p - 1]++;
// 	}

// 	ll actualRank = 1;
// 	for(ll i = 1; i <= n; i++){
// 		while(freq[i - 1]){
// 			badness += abs(actualRank - i);
// 			actualRank++;
// 			freq[i - 1]--;
// 		}
// 	}

// 	return badness;
// }

// ll main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// 	ll t;
// 	cin >> t;
// 	vector<ll> v;
// 	while(t--){
// 		ll n, rank;
// 		string s;
// 		cin >> n;
// 		for(ll i = 0; i < n; i++){
// 			cin >> s >> rank;
// 			v.push_back(rank);
// 		}

// 		cout << badness(v, n) << endl;
// 		// badness(v, n);
// 		v.clear();

// 	}
// }
