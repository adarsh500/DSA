#include <iostream>
using namespace std;

#define ull unsigned long long int

//Euclidean's Algorithm
int gcd(int a, int b) {
	return b==0 ? a : gcd(b, a % b);
}


int main() {
	ull a, b, small, factor, ans = 0;
	cin >> a >> b;

	// cout << gcd(a, b) << endl;

	small = min(a , b);
	for (ull i = small; i >= 1; i--) {
		if ((a % i) == 0 and (b % i) == 0) {
			factor = i;
			ans = max(ans, factor);
		}
	}
	cout << ans << endl;
	return 0;
}