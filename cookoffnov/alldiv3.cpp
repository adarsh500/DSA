#include <bits/stdc++.h>
using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, ans = 0;
		cin >> n;
		int rem[3] = {0};
		//to store the number of elements with remainders 0, 1, 2
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			rem[arr[i] % 3]++;
		}

		if ((rem[0]*0 + rem[1]*1 + rem[2]*2) % 3 != 0){
			//we are calculating the sum of remainders. if the sum of remainder
			//is not divisible by three then we can just print - 1;
			ans = -1;
		} else {
			//compute the minimum operations;
			//we form a pair of elements with remainder 1 and 2
			//since it would take one operation per pair, it would take us a
			//total of temp operations
			int temp = min(rem[1], rem[2]);
			rem[1] -= temp;
			rem[2] -= temp;
			ans += temp;

			//now we deal with the remaining elements
			//we arrange the remaining 1's and 2's in groups of 3, separately
			//a group of 1's can be solved in 2 operations, and same with 2's
			ans += 2 * (rem[1]/3 + rem[2]/3) ;
		}
		cout << ans << endl;
	}
	return 0;
}