// given n points in a 2d cartesian plane, how many right angled
//triangles are there such that perpendicular or base is parallel
//x or y axis (one side should be parallel to x and another should
//be parallel to y)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 4;
	int arr[][2] = {{1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}};
	map<int> mx, my;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j & 1) {
				if (my.count(arr[i][j])) {
					my[arr[i][j]]++;
				} else {
					my[arr[i][j]] = 1;
				}
			} else {
				if (mx.count(arr[i][j])) {
					mx[arr[i][j]]++;
				} else {
					mx[arr[i][j]] = 1;
				}
			}
		}
	}



}