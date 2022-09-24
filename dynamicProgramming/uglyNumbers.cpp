#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
#define MOD 1e7
using namespace std;

int nthUglyNumber(int n){
	int ugly[n];
	int i2 = 0, i3 = 0, i5 = 0;
	int nextMultipleOf2 = 2;
	int nextMultipleOf3 = 3;
	int nextMultipleOf5 = 5;
	int nextUglyNumber = 1;
	ugly[0] = 1;

	for(int i = 1; i < n; i++){
		nextUglyNumber = min({nextMultipleOf2, nextMultipleOf3, nextMultipleOf5});
		ugly[i] = nextUglyNumber;


		if (nextUglyNumber == nextMultipleOf2){
			i2++;
			nextMultipleOf2 = ugly[i2] * 2;
		}
		if (nextUglyNumber == nextMultipleOf3){
			i3++;
			nextMultipleOf3 = ugly[i3] * 3;
		} 
		if (nextUglyNumber == nextMultipleOf5){
			i5++;
			nextMultipleOf5 = ugly[i5] * 5;
		}
	}
		// for(int i = 0;i < n; i++){
		// 	cout << ugly[i] << " ";
		// }
		// cout << endl;

	return nextUglyNumber;
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << nthUglyNumber(n) << endl;
	}
	return 0;
}