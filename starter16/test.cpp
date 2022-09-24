// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1000000;

// int prefix[MAX];
 
// void buildPrefix() {
//     bool prime[MAX + 1];
//     memset(prime, true, sizeof(prime));
 
//     for (int p = 2; p * p < MAX; p++) {
//         if (prime[p] == true) { 
//             for (int i = p * 2; i < MAX; i += p)
//                 prime[i] = false;
//         }
//     }

//     prefix[0] = prefix[1] = 0;
//     for (int p = 2; p < MAX; p++) {
//         prefix[p] = prefix[p - 1];
//         if (prime[p])
//             prefix[p]++;
//     }
// }
 
// int query(int L, int R) {
//     return prefix[R] - prefix[L - 1];
// }

// bool isPrime(int n)
// {
//     // Corner cases
//     if (n <= 1)
//         return false;
//     if (n <= 3)
//         return true;
  
//     // This is checked so that we can skip
//     // middle five numbers in below loop
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;
  
//     for (int i = 5; i * i <= n; i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
  
//     return true;
// }

// int main(){
// 	buildPrefix();
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// 	int t;
// 	cin >> t;
// 	while(t--){	

// 		int x, y, count = 0;
// 		cin >> x >> y;
// 		int primeCount;
// 		// if (x <= 2){
// 		// 	// primeCount = query(x + 1, y);
// 		// 	if (isPrime(x + 1)){
// 		// 		primeCount = query(x + 2, y);
// 		// 	} else {
// 		// 		primeCount = query(x + 1, y);
// 		// 	}
// 		// } else {
// 		// 	primeCount = query(x, y);
// 		// }
// 		if (isPrime(x) && isPrime(x + 1)) {
// 			primeCount = query(x + 2, y);
// 		} else if(isPrime(x)){
// 			primeCount =query(x + 1, y);
// 		} else {
// 			primeCount = query(x, y);
// 		}
// 		// cout << primeCount << " ";
// 		// while(primeCount--){
// 		// 	count++;
// 		// 	y = y - 2;
// 		// }
// 		// while (y > x){
// 		// 	y--;
// 		// 	count++;
// 		// }
// 		count = y - x - primeCount;
// 		cout << count<< endl;
// 	}
// }
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

int prefix[MAX];
bool prime[MAX + 1];

void buildPrefix() {
	prefix[0] = prefix[1] = 0;
    bool prime[MAX + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= MAX; p++) {

        prefix[p] = prefix[p - 1];

        if (prime[p] == true) { 
            prefix[p]++;

            for (int i = p * 2; i <= MAX; i += p)
                prime[i] = false;
        }
    }

    // for (int p = 2; p <= MAX; p++) {
    //     if (prime[p])
    // }
}
 
int query(int L, int R) {
    return prefix[R] - prefix[L - 1];
}


int main(){
	buildPrefix();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--){	

		int x, y, count = 0;
		cin >> x >> y;
		int primeCount = query(x + 2, y);
		// cout << primeCount << " ";
		count = y - x - primeCount;
		cout << count<< endl;
	}
}