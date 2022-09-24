// note that we cannot sort the string lexicographically consider this example
	// 01111
	// 10000
	// your solution will sort them 01111 → 10000
	// whereas the best is achieved when we use the order 10000 > 01111

#include <bits/stdc++.h>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		vector<pair<int, int> > v;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			int count1 = count(s[i].begin(), s[i].end(), '1');
			v.push_back({count1, i});
		}

		sort(v.begin(), v.end());
		//sorts the vector in ascending order i.e. increasing order of 1's
		string finalStr;

		for (int i = 0; i < n; i++) {
    		for (auto u : s[v[i].second]) {
      			finalStr.push_back(u);
    		}
  		}
		//we sort string in increasing order of 1's and concatenate them

		int ones = 0, ans = 0;
		for(int i = 0; i < n * m; i++){
			if (finalStr[i] == '1'){
				ones++;
			} else {
				ans += ones;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}






// #include<bits/stdc++.h>
// using namespace std;
// void solve() {
//   int n, m; 
//   cin >> n >> m;
//   vector<string> s(n);
//   vector<pair<int, int>> v;
//   for (int i = 0; i < n; i++) {
//     cin >> s[i];
//     int ones = count(s[i].begin(), s[i].end(), '1');
//     v.push_back({ones, i});
//   }
//   sort(v.begin(), v.end());
//   string cur;
//   for (int i = 0; i < n; i++) {
//     for (auto u : s[v[i].second]) {
//       cur.push_back(u);
//     }
//   }
//   int ones = 0;
//   long long ans = 0;
//   for (int i = 0; i < n * m; i++) {
//     if (cur[i] == '1') ones++;
//     else ans += ones;
//   }
//   cout << ans << '\n';
// }

// signed main() {
//   int t = 1;
//   cin >> t;
//   for (int i = 1; i <= t; i++) solve();
//   return 0;
// }