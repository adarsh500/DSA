#include<bits/stdc++.h>

using namespace std;

int main() {

	int n = 0;
	cin >> n;
	int k = 0; cin >> k;
	priority_queue< long long int> pq;
	int count = 1;
	for (int i = 0; i < n; i++) {

		int q = 0;
		cin >> q;
		if (q == 1) {
			long long int x , y;
			cin >> x >> y;
			long long int dist = x * x + y * y;
			if (count <= k) {
				pq.push(dist);
				count++;
			} else if (pq.top() > dist) {
				pq.pop();

				pq.push(dist);
			}
		}
		else if (q == 2) {
			cout << pq.top() << endl;
		}
	}

	return 0;
}