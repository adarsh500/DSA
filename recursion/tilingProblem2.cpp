#include <iostream>
using namespace std;

#define ll long long int

int possibleWays(int n, int m) {
	const unsigned int mod = 1000000007;

	if (n <= 3) {
		return 1;
	} else if (n == m){
		return 2;
	}

	return (possibleWays(n - 1, m) % mod) + (possibleWays(n - m, m) % mod);
}

int main() {
	const unsigned int mod = 1000000007;

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		cout << possibleWays(n, m) % mod << endl;
	}
}