// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> primeSieve(int * p){
// 	vector<int> prime;
// 	// int arr[1000005];
// 	for (int i = 3; i < 1000005; i += 2){
// 		p[i] = 1;
// 	}

// 	for (int i = 3; i < 1000005; i += 2){
// 		if (p[i] == 1){
// 			for (int j = i * i; j <= 1000005; j += i){
// 				p[j] = 0;
// 			}
// 		}
// 	}
// 	p[1] = p[0] = 0;
// 	p[2] = 1;
// 	prime.push_back(2);
// 	for (int i = 3; i < 1000005; i++){
// 		if (p[i] == 1){
// 			prime.push_back(i);
// 		}
// 	}

// 	return prime;
// }

// int main(){
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		int a, b;
// 		cin >> a >> b;
// 		vector<int> p[10000005] = {0};
// 		primeSieve(p);

// 	}
// }




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
	int t; 
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << Prime[n - 1] << endl;
	}
	
	return 0;
}
