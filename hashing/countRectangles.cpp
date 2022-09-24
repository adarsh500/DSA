// given n caretesian points, find the number of axis parallel that
// can be formed by them

// points = [[0, 0], [0, 1], [1, 1], [1, 0], [2, 1], [2, 0], [3, 1], [3, 0]]
#include <bits/stdc++.h>
using namespace std;

class Point {
public:
	int x, y;
	Point() {

	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Compare {
public:
	bool operator()(Point p1, Point p2) {
		if (p1.x == p2.x) {
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};

int countRectangle(vector<Point> coords) {
	int n = coords.size();
	set<Point, Compare> s;
	// since we are creating a DS with custom data type, we
	// also need to pass a comparator class which allows it to
	//perfrom comparisons
	for (auto p : coords) {
		s.insert(p);
	}

	int ans = 0;
	for (auto it = s.begin(); it != prev(s.end()); it++) {
		for (auto jt = next(it); jt != s.end(); jt++) {
			//here prev(s.end()) will return an iterator just before s.end()
			//and next(it) is used as map is not a linear DS, it just gives
			//the next iterator
			Point p1 = *it;
			Point p2 = *jt;

			if (p2.x == p1.x || p2.y == p1.y) {
				continue;
			}

			Point p3(p2.x, p1.y);
			Point p4(p1.x, p2.y);

			if (s.find(p3) != s.end() and s.find(p4) != s.end()) {
				ans++;
			}
		}
	}

	// since all rectangles are counted twice, we divide the ans by 2
	return ans / 2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	cin >> m;
	vector<Point> coords;
	while (m--) {
		int x, y;
		cin >> x >> y;
		Point p(x, y);
		coords.push_back(p);
	}
	cout << countRectangle(coords) << endl;

	return 0;
}