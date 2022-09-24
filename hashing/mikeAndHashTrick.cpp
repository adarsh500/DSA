// #include <bits/stdc++.h>
// // #define MAX 1e9 + 9
// using namespace std;

// int MAX = 1e5 + 7;

// int* hash_array(int A[], int n, int largest)
// {
// 	int* hash = new int[largest]; //MAX is the maximum possible value of A[i]
// 	for (int i = 0; i <= largest; i++) {
// 		hash[i] = -1; //initialize hash to -1.
// 	}
// 	int count = 0;
// 	for (int i = 0; i < n; i++) // Loop through elements of array
// 	{
// 		if (hash[A[i]] == -1) // A[i] was not assigned any hash before
// 		{
// 			hash[A[i]] = count; // Assigning hash to A[i]
// 			count++;
// 			continue;
// 		}
// 		for (int j = 0; j < i; j++)
// 		{
// 			if (hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
// 				hash[A[j]]--;
// 		}
// 		hash[A[i]] = count - 1; // Assigning a new hash to A[i]
// 	}
// 	return hash;
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	int n, largest = INT_MIN;
// 	cin >> n;
// 	int arr[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 		largest = max(largest, arr[i]);
// 	}
// 	int* hash = new int[largest];
// 	hash = hash_array(hash, n, largest);

// 	for (int i = 0; i < n; i++) {
// 		cout << hash[arr[i]] << endl;
// 	}

// }



#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 100100
#define ll long long int
using namespace std;

map<int, int>last; //stores the last position of every integer that occurred in the array.

int a[nn];

bool compare(int a, int b) //sorting by last position
{
	return last[a] < last[b];
}

int main() {
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif 
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (last.find(a[i]) == last.end())
			v.pb(a[i]);
		last[a[i]] = i;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}