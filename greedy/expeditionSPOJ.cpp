#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int n, dist, fuel, a, b, prev, x, flag = 0;
	int count = 0;
	vector<pair<int, int >> v;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a , b));
	}

	cin >> dist >> fuel;

	//logic
	sort(v.begin(), v.end(), compare);

	//update the distance of the fuel station from the truc
	for (int i = 0; i < n; i++) {
		v[i].first = dist - v[i].first;
	}

	prev = 0; // denotes the prev station that we visited
	x = 0; // current city

	while (x < n) {
		if (fuel >= v[x].first - prev) {
			fuel = fuel - (v[x].first - prev);
			pq.push(v[x].second);
			prev = v[x].first;
		} else {
			//check if you have visited some fueling stations
			//in the priority queue;
			if (pq.empty()) {
				flag = 1;
				break;
			}

			fuel += pq.top();
			pq.pop();
			count++;
			continue;
		}

		x++;
	}

	//at the end of the while loop we have travelled through
	//n fuel stations and now we have to travel to the city
	if (flag == 1) {
		cout << -1 << endl;
		return 0;
	}
	dist = dist - v[n - 1].first;
	if (fuel >= dist) {
		cout << count << endl;
		return 0;
	}

	//otherwise
	while (fuel < dist) {
		if (pq.empty()) {
			flag = 1;
			break;
		}

		fuel += pq.top();
		pq.pop();
		count++;
	}

	if (flag == 1) {
		cout << -1 << endl;
		return 0;
	}

	cout << count << endl;
}