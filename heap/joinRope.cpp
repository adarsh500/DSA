#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	// while(!pq.empty()){
	// 	cout << pq.top() << " ";
	// 	pq.pop();
	// }

	int cost = 0;
	while(pq.size() > 1){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		cost += a + b;
		pq.push(a + b);
	}

	cout << cost << endl;
}