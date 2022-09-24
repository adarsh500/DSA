#include <bits/stdc++.h>
using namespace std;

bool compare(pair <int, int> pair1, pair <int, int> pair2){
	return pair1.second < pair2.second;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, a, b;
		cin >> n;

		pair <int, int>  arr[n];
		for (int i = 0; i < n; i++){	
			cin >> a >> b;
			arr[i] = make_pair(a, b);
		}

		sort(arr, arr + n, compare);

		//by default the first pair set is counted
		//current is the chosen/current pair at focus
		int count = 1, current = 0;
		for (int i = 1; i < n; i++){
			if (arr[i].first >= arr[current].second){
				count++;
				current = i;
			}
		}
		cout << count << endl;
	}
	return 0;
}