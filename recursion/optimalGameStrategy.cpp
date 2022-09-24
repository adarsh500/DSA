#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

ll arr[30];

int winning(ll i, ll j) {
	int res;
	if (i > j){
		return 0;
	}

// 	f you pick the ith coin. The other player will have the option to pick ('I'+1)th or ‘J’th coin.
// → If the other player picks the ('I'+1)th coin. You can pick either end of the range ['I'+2, ‘J’].
// →If the other player picks ‘J’th coin. You can pick either end of the range ['I'+1, ‘J’-1].
// → As the other player wants to maximize his amount (thereby minimizing the amount you can win). 
// Hence, of the two ranges which you are left with (mentioned above), 
// you can only use that range that gives us the minimum amount.


	int x = arr[i] + min(winning(i + 1, j - 1), winning(i + 2,j));
	int y = arr[j] + min(winning(i + 1, j - 1), winning(i, j - 2));
	res = max(x, y);
	return res;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << winning(0, n - 1) << endl; 
}