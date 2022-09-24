#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int n, xdiff, ydiff, size = INT_MIN;
	cin >> n;
	int x[n], y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		size = max(x[i], y[i]);
	}

	sort(x, x + n);
	sort(y, y + n);

	xdiff = x[0] - 0;
	ydiff = y[0] - 0;
	// cout << xdiff << endl;
	// cout << ydiff << endl;

	for(int i = 1; i < n; i++){
		xdiff = max(xdiff, x[i] - x[i - 1] - 1);
		ydiff = max(ydiff, y[i] - y[i - 1] - 1);
	// 	cout << xdiff << endl;
	// cout << ydiff << endl;
	}

	xdiff = max(xdiff, size - x[n - 1] - 1);
	ydiff = max(ydiff, size - y[n - 1] - 1);

	cout << (xdiff * ydiff) << endl;
}