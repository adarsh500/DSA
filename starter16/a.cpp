#include <bits/stdc++.h>
using namespace std;

// bool isPrime(int n){
// 	if (n == 1){
// 		return false;
// 	}
// 	if (n == 2 || n == 3 || n == 5){
// 		return true;
// 	}

// 	int i = 2;
// 	while(i*i <= n){
// 		if (n % i == 0){
// 			return false;
// 		}
// 		i++;
// 	}

// 	return true;
// }

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

const int MAX = 1000000;

bool prime[MAX + 1];
 
void buildPrefix() {
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= MAX; p++) {
        if (prime[p] == true) { 
            for (int i = p * 2; i <= MAX; i += p)
                prime[i] = false;
        } else if (prime[p + 2] == true){
        	for (int i = (p + 2) * 2; i <= MAX; i += p)
                prime[i] = false;
        }
    }
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
		int x, y;
		cin >> x >> y;
		int count = 0;
		while(x < y){
			if (prime[x + 2]){
				x += 2;
				count++;
			} else {
				x++;
				count++;
			}
		}

		cout << count << endl;
	}
}