#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, a, b, count = 1;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back(make_pair(a - b, a + b));
	}

	sort(v.begin(), v.end(), compare);

	// for( auto p : v){
	// 	cout << p.first << " " << p.second << endl;
	// }

	

	int prev = v[0].second;
	for(int i = 1; i < n; i++){
		if (v[i].first >= prev){
			prev = v[i].second;
			count++;

		}
	}

	cout << n - count << endl;
}