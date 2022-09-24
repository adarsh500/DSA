#include <bits/stdc++.h>
using namespace std;

bool compare (pair <string, int> pair1, pair <string, int> pair2){
	if (pair1.second == pair2.second){
		return pair1.first < pair2.first;
	}
	return pair1.second > pair2.second;
}

int main(){
	int x;
	cin >> x;

	long long int n;
	cin >> n;

	string name;
	int sal;
	pair <string, int> arr[100005];
	for (int i = 0; i < n; i++){
		cin >> name >> sal;
		// arr[i] = make_pair(name, sal);
		arr[i].first = name;
		arr[i].second = sal;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++){
		if (arr[i].second >= x)
			cout << arr[i].first << " " << arr[i].second << endl;
		else
			return 0;
	}
	return 0;
}