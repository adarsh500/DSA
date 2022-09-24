

// We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.
// Input Format

// First line contains the length of the array n. Second line contains the n space separated integers.
// Constraints

// 1 <= n <= 10^6
// -10^8 <= Ai <= 10^8 , 0<= i< n
// Output Format

// Print n space separated integers each representing the next greater element.
// Sample Input

// 3
// 1 2 3

// Sample Output

// 2 3 -1

// Explanation

// Next greater element for 1 is 2,
// for 2 is 3 but not present for 3 therefore -1



//O(1) space and O(n^2)time
// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
// 	int n;
// 	cin >> n;

// 	int arr[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}

// 	stack<int> s;

// 	for (int i = 0; i < n; i++) {
// 		for (int j = i + 1; j < n + i; j++) {
// 			if (arr[j % n] > arr[i]) {
// 				cout << arr[j % n] << " ";
// 				break;
// 			}
// 			cout << "-1" << " ";
// 			break;
// 		}
// 	}
// 	// cout << "-1" << " ";

// }







//very detailed explanation: https://www.youtube.com/watch?v=Du881K7Jtk8


// Time Complexity: O(N)
// Auxiliary Space: O(N)

#include <bits/stdc++.h>
using namespace std;


void printNGE(int a[], int n)
{
	stack <int> s;
	vector<int> ans(n);
	for (int i = 2 * n - 1; i >= 0; i--)
	{

		while (!s.empty() && a[i % n] >= s.top())
			s.pop();


		if (i < n) {
			if (!s.empty())
			{
				ans[i] = s.top();
			}
			else
			{
				ans[i] = -1;
			}
		}
		s.push(a[i % n]);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}

int main()
{
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	printNGE(arr, N);
	return 0;
}



