// You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are 
// also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon 
// as possible under the constraints that any painter will only paint contiguous sections of board.
//  Return the ans % 10000003


// Input Format
// First line contains three space seperated integers N,K and T ,where 
// N = Size of array, 
// K = No of painters available , 
// T = Time taken to print each board by one painter 
// Next line contains N space seperated positive integers denoting size of N boards.


// Constraints
// 1<=N<=100000 
// 1<=K<=100000 
// 1<=T<=1000000 
// 1<=Li<=100000


// Output Format
// Return minimum time required to paint all boards % 10000003.


// Sample Input
// 2 2 5
// 1 10
// Sample Output
// 50
// Explanation
// The first painter can paint the first board in 5 units of time and the second painter will take 50 units 
// of time to paint the second board. Since both can paint simultaneously , the total time required to paint 
// both the boards is 50.

#include <iostream>
using namespace std;

int paintersRequired(long long int arr[], long long int n, long long int mid, long long int k, long long int t) {
	long long int painters = 1, workDone = 0;
	for (int i = 0; i < n; i++){
		workDone += arr[i];

		if (workDone > mid){
			painters++;
			workDone = arr[i];
		}
	}
	return painters;
}

int main() {
	long long int n, k, t;
	cin >> n >> k >> t;

	long long int arr[n];
	for (long long int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long int start = 0, end = 0, mid, ans;
	for (long long int i = 0; i < n; i++) {
		start = max(arr[i], start);
		end += arr[i];
	}

	while (start <= end) {
		mid = (start + end) / 2;
		if (paintersRequired(arr, n, mid, k, t) <= k) {
			end = mid - 1;
			ans = mid;
		} else {
			start = mid + 1;
		}
	}

	cout << ((ans * t) % 10000003) << endl;
	return 0;
}





// #include <iostream>
// using namespace std;
// long long int maximum(long long int ar[1000000], long long int N)
// {
// 	long long int max = ar[0];
// 	for (int i = 0; i < N; i++)
// 	{
// 		if (ar[i] > max)
// 		{
// 			max = ar[i];
// 		}
// 	}
// 	return max;
// }
// long long int Valid(long long int L[], long long int N, long long int Mid)
// {
// 	long long int sum = 0, point = 1;
// 	for (int i = 0; i < N; i++)
// 	{
// 		sum = sum + L[i];

// 		if (sum > Mid)
// 		{
// 			point++;
// 			sum = L[i];
// 		}
// 	}
// 	return point;
// }
// long long int PP(long long int length[], long long int n, long long int k, long long int length_sum, long long int t)
// {
// 	long long int s = maximum(length, n);
// 	long long int e = length_sum;
// 	long long int ans;
// 	while (s <= e)
// 	{
// 		long long int mid = (s + e) / 2;
// 		long long int painters = Valid(length, n, mid);
// 		if (painters <= k)
// 		{
// 			ans = mid;
// 			e = mid - 1;
// 		}
// 		else
// 		{
// 			s = mid + 1;
// 		}
// 	}
// 	return (ans * t) % 10000003;
// }
// int main()
// {
// 	long long int n, k, length_sum = 0, t;
// 	cin >> n >> k >> t;
// 	long long int length[n];
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> length[i];
// 		length_sum = length_sum + length[i];
// 	}
// 	cout << PP(length, n, k, length_sum, t);
// 	return 0;
// }