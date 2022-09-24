#include <iostream>
using namespace std;

#define ll long long int

ll arr[1000005], pre[1000005];
//pre is the frequency array that stores the freq of 
//elements in the arr
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		memset(pre, 0, sizeof(pre));
		//syntax: memset(arr_name, value to initialize with, end of initialize index)
		//memset basically initializes all elements of pre to 0
		pre[0] = 1;

		ll sum = 0;
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			sum += arr[i];
			sum %= n;
			sum = (sum + n) % n;
			//line 26 is done for -ve elements, but it doesn't change +ve elements
			pre[sum]++;
		}
		
		ll ans = 0;
		for (int i = 0; i < n; i++){
			ll m = pre[i];
			ans += (m * (m-1)) /2;  //nC2
		}
		cout << ans << endl;
	}
	return 0;
}
