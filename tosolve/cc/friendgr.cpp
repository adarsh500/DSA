#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, res, groups = 0;
		string str;
		cin >> n >> k;
		cin >> str;
		vector <int> pos;
		for (int i = 0; i < n; i++){
			if (str[i] == 1){
				pos.push_back(i);
			}
		}
		for (int i = 1; i < n; i++){
			int diff = pos[i] - pos[i - 1];
			if (diff <= k){
				groups = 1;
			} else {
				diff = (pos[i]-1) - pos[i - 1];
				if (diff <= k){
					continue;
				} else if (pos[i] - (pos[i - 1] + 1) <= k){
					continue;
				} else if ((pos[i]-1) - (pos[i - 1] + 1) <= k){
					continue;
				} else {
					groups++;
				}
			}
			res = groups;
		}
		cout << res << endl;
	}
}