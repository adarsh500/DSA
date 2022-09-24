// #include <iostream>
// using namespace std;

// #define ll long long int

// void primeSieve(int *p){
// 	for (ll i = 3; i < 7400005; i += 2){
// 		p[i] = 1;
// 	}

// 	for (ll i = 3; i < 7400005; i += 2){
// 		if (p[i] == 1){
// 			for (ll j = i*i; j < 7400005; j += i){
// 				p[j] = 0;
// 			}
// 		}
// 	}

// 	p[0] = p[1] = 0;
// 	p[2] = 1;

// }

// int main(){
// 	long long n;
// 	cin >> n;
// 	int p[7400005] = {0};
// 	primeSieve(p);

// 	ll count = 0;
// 	for(int i = 0; i < 7400005; i++){
// 		if(p[i] == 1){
// 			count++;
// 		}
// 		if (count == n){
// 			cout << i << endl;
// 			break;
// 		}
// 	}
// 	return 0;
// 	// int primeArr[7400005], k = 1;
// 	// primeArr[0] = 2;
// 	// for (int i = 3; i < 7400005; i++){
// 	// 	if (p[i] == 1){
// 	// 		primeArr[k] = i;
// 	// 		k++;
// 	// 	}
// 	// }

// 	// cout << primeArr[n - 1] << endl;
// 	// return 0;
// }


//---------------------------CB SOLUTION----------------------------

#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

bool prime [7400005] = {};
vector<int> Prime;
int main() {
	prime[0] = prime[1] = true;
	Prime.push_back(2);
	for (ll i = 3; i < 7400000; i += 2) {

		if (!prime[i]) {
			Prime.push_back(i);
			for (ll j = i * i; j < 7400000; j += i) {
				prime[j] = true;
			}
		}
	}
	int n; 
	cin >> n;
	cout << Prime[n - 1] << endl;
	return 0;
}

// The 500,000th prime is 7,368,787.