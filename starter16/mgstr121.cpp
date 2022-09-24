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