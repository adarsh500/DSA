#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<vector<int>> s;
void sumItUp(int a[20], vector <int> out, int i, int sum, int target, int n) {
	if (i == n) {
		if (sum == target) {
			sort(out.begin(), out.end());
			s.insert(out);
		}
		return;
	}
	out.push_back(a[i]);
	sumItUp(a, out, i + 1, sum + a[i], target, n);
	out.pop_back();
	sumItUp(a, out, i + 1, sum, target, n);
}

int main() {
	int n;
	cin >> n;
	int a[20];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int target;
	cin >> target;
	vector <int> out;
	sumItUp(a, out, 0, 0, target, n);
	for (auto itr = s.begin(); itr != s.end(); itr++) {
		vector<int> t = *itr; // set has vectors as its elements
		for (int i = 0; i < t.size(); i++) // displaying each vector
			cout << t[i] << " ";
		cout << endl;
	}
}
