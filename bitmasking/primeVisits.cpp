// //-------------------OPTIMISED APPROACH: O(NloglogN)--------------------

// #include <iostream>
// using namespace std;

// #define ll long long int

// void primeSieve(int * prime){
// 	for (ll i = 3; i < 1000000; i += 2){
// 		prime[i] = 1;
// 	}

// 	for (ll i = 3; i < 1000000; i += 2){
// 		if (prime[i] == 1){
// 			for (ll j = i*i; j < 1000000; j += i){
// 				prime[j] = 0;
// 			}
// 		}	
// 	}

// 	prime[0] = prime[1] = 0;
// 	prime[2] = 1;


// }

// int main(){
// 	int prime[1000000] = {0};
// 	primeSieve(prime);
// 	int cumSum[1000000] = {0};

// 	for (int i = 1; i < 1000000; i++){
// 		cumSum[i] = cumSum[i - 1] + prime[i];
// 	}


// 	int n;
// 	cin >> n;
// 	while(n--){
// 		ll a, b;
// 		cin >> a >> b;
// 		cout << (cumSum[b] - cumSum[a - 1]) << endl;
// 	}
// 	return 0;
// }


//-------------------MORE OPTIMISED APPROACH: O(logN)--------------------

#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

vector<int> primeSieve(int* prime,int n){
	for (ll i = 3; i < n; i += 2){
		prime[i] = 1;
	}

	for (ll i = 3; i < n; i += 2){
		if (prime[i] == 1){
			for (ll j = i*i; j < n; j += i){
				prime[j] = 0;
			}
		}	
	}

	prime[0] = prime[1] = 0;
	prime[2] = 1;

	vector<int> primeArray;
	for (ll i = 0; i < n; i++){
		if (prime[i] == 1){
			primeArray.push_back(i);
		}
	}

	return primeArray;
}


//return a vector of prime factors
vector<int> factorize(int m, vector<int> &primes){

	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];

	while(p * p <= m){
		if (m % p == 0){
			while(m % p == 0){
				factors.push_back(p);

				m /= p;
			}
		}
		i++;
		p = primes[i];
	}

	if (m != 1){
		factors.push_back(m);
	}
	return factors;
}



int main(){
	int p[1000000] = {0};
	vector<int> primes = primeSieve(p, 10000);

	int t;
	cin >> t;

	while (t--){
		ll n;
		cin >> n;

		vector<int> factors = factorize(n, primes);

		for (auto f: factors){
			cout << f << " " << endl;
		}
	}
	return 0;
}
