#include <iostream>
#define ll long long int
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	ll x[40010], y[40010];
	ll n, w, h;
	while(t--){
		cin >> w >> h >> n;

		for(ll i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}

		sort(x, x + n);
		sort(y, y + n);

		//first case, unguarded area between tiles 1 and x/y
		ll xdiff = x[0] - 1;
		ll ydiff = y[0] - 1;

		for(ll i = 1; i < n; i++){
			xdiff = max(xdiff, x[i] - x[i - 1] - 1);
			ydiff = max(ydiff, y[i] - y[i - 1] - 1);
		}

		//last ccase, unguarded area between last x/y and w/h
		xdiff = max(xdiff, w - x[n - 1]);
		ydiff = max(ydiff, h - y[n - 1]);
		cout << (xdiff * ydiff) << endl;
	}
}