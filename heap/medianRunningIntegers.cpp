#include <bits/stdc++.h>
using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		priority_queue<int> leftheap; //maxheap
		priority_queue<int, vector<int>, greater<int>> rightheap; //minheap

		leftheap.push(arr[0]);
		int median = arr[0];

		cout << median << " ";

		for (int i = 1; i < n; i++) {
			if (leftheap.size() > rightheap.size()) {
				if (arr[i] < median) {
					rightheap.push(leftheap.top());
					leftheap.pop();
					leftheap.push(arr[i]);
				} else {
					rightheap.push(arr[i]);
				}

				median = (leftheap.top() + rightheap.top()) / 2;
			} else if (leftheap.size() == rightheap.size()) {
				if (arr[i] < median) {
					leftheap.push(arr[i]);
					median = leftheap.top();
				} else {
					rightheap.push(arr[i]);
					median = rightheap.top();
				}
			} else {
				//here rightheap.size() > leftheap.size()
				if (arr[i] > median) {
					leftheap.push(rightheap.top());
					rightheap.pop();
					rightheap.push(arr[i]);
				} else {
					leftheap.push(arr[i]);
				}

				median = (leftheap.top() + rightheap.top()) / 2;
			}
			cout << median << " ";
		}

		cout << endl;
	}
}