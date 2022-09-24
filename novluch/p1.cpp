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
		int n, k;
		cin >> n >> k;
		if ((k&1)){
			cout << n << "\n";
		} else if ((n&0) == 0 and (k&0)==0){
			int start = 1, end = n - 1;
			while(start <= end){
				int i = (start + end) / 2;
				if ((i * k) % n == 0){
					cout << i << "\n";
					break;
				} else if((i * k) > (n * k)){
					end--;
				} else {
					start++;;
				}
			}
			// for(int i = 1; i <= k; i++){
			// 	if ((i * n) >= k){
			// 	cout << ceil((i * n) / (k * 1.0)) << endl;
			// 	break;
			// }
		} else {
			if (n > k){
				
			} else {
				
			}
		}
		// for(int i = 1; i <= n; i++){
		// 	if ((i * k) % n == 0){
		// 		cout << i << "\n";
		// 		break;
		// 	}
		// 	// if ((i * n) >= k){
		// 	// 	cout << ceil((i * k) / (n)) << endl;
		// 	// 	break;
		// 	// }
		// }
	}
		
}