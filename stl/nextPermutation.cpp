// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main()
// {
// 	int t;
// 	cin>>t;
// 	for(int i=0;i<t;i++)
// 	{
// 		int n;
// 		cin>>n;
//         int arr[n];
// 		for(int j=0;j<n;j++){
// 			cin>>arr[j];
// 		}

// 		next_permutation(arr, arr + n);
// 		for(int j=0;j<n;j++){
//             cout<<arr[j]<<" ";
//         }
//         cout<<endl;
// 	}
// 	return 0;
// }



// Algorithm The steps to solve this problem:

//     Scan from right to left, find the first element that is less than its previous one.


// 4 5 6 3 2 1
//   |
//   p

//     Scan from right to left, find the first element that is greater than p.


// 4 5 6 3 2 1
//     |
//     q

//     Swap p and q


// 4 5 6 3 2 1
// swap
// 4 6 5 3 2 1

//     Reverse elements [p+1, nums.length]


// 4 6 1 2 3 5

#include <bits/stdc++.h>
using namespace std;


void reverse(vector<int>& nums, int left, int right) {
	while (left < right) {
		swap(nums[left], nums[right]);
		left++;
		right--;
	}
}


void next_permutation(vector<int> &nums) {

	if (nums.size() < 2)
		return;

	int p = 0;
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			p = i;
			break;
		}
	}

	int q = 0;
	for (int i = nums.size() - 1; i > p; i--) {
		if (nums[i] > nums[p]) {
			q = i;
			break;
		}
	}

	if (p == 0 && q == 0) {
		reverse(nums, 0, nums.size() - 1);
		return;
	}

	swap(nums[p], nums[q]);

	if (p < nums.size() - 1) {
		reverse(nums, p + 1, nums.size() - 1);
	}
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		next_permutation(v);

		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
