#include <iostream>
using namespace std;

//find the number of numbers between 1 to n, which are divisible by any prime
//numbers between less than 20

#define ll long long int

int main(){
	ll t;
	cin >> t;

	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	while (t--){
		ll n;
		cin >> n;

		ll subsets = (1<<8) - 1; //as the number of primes are 8
		ll ans = 0;

		for (int i = 1; i <= subsets; i++){
			ll denom = 1ll;
			int setBits = __builtin_popcount(i);

			for (ll j = 1; j <= 7; j++){
				if (i & (1<<j)){
					denom *= primes[j];
				}
			}
			if(setBits & 1){
				ans += n/denom;
			} else {
				ans -= n/denom;
			}
		}
		cout << ans << endl;
	}
	return 0;
}