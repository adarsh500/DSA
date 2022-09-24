// #include <bits/stdc++.h>
// using namespace std;

// bool compare(pair<int, int> a, pair<int, int> b){
// 	if (a.second != b.second){

// 	}
// 	return a.second < b.second;
// }

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		vector<pair<int, int> > v;
// 		int n, ans = 1, a, b;
// 		cin >> n;
// 		for(int i = 0; i < n; i++){
// 			cin >> a >> b;
// 			v.push_back(make_pair(a, b));
// 		}

// 		// sort(v.begin(),v.end(), compare);

// 		// for(auto p : v){
// 		// 	cout << p.first << " " << p.second << endl;
// 		// }


// 		// int end = v[0].second;
// 		// for(int i = 1; i < n; i++){
// 		// 	if (v[i].first >= end){
// 		// 		ans++;
// 		// 		end = v[i].second;
// 		// 	}
// 		// }
// 		// cout << ans << endl;
// 	}
// }

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.second != b.second){
		return a.second < b.second;
	} else {
		return a.first < b.first;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		int n, ans = 1;
		cin >> n;
		vector<pair<int, int> > v;
		while(n--){
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}

		sort(v.begin(),v.end(), compare);

		for(auto it = v.begin(); it != v.end() - 1; it++){
			for(auto jt = v.begin() + 1; jt != v.end(); jt++){
				if (it->second <= jt->first){
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}