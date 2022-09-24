/*
1. sort the array, then check if adjacent elements are of same value or 
   have increase in value, then count++. when you reach an element which is
   not subsequent, then just stop count, reset count to 0 and compare for max
   length
2. store all the elemnents of the array in a map, then iterate from the min
   element of the array, till the max. If the element is present in the hashmap
   then count++, else we stop and reset count, and we set ans = max(count, ans);
   this looks linear for small ranges, but bad for long ranges

3. This is the third one
*/

#include <bits/stdc++.h>
using namespace std;
//3rd one
// int findLargestSequence(int arr[], int n){
// 	int largest = 0;
// 	unordered_map<int, int> m;

// 	for(int i = 0; i < n; i++){
// 		int n = arr[i];

// 		if (m.count(n - 1) == 0 and m.count(n + 1) == 0){
// 			//if both the lesser and the greater value is not present,
// 			//we add it to the map and create a streak of 1
// 			m[n] = 1;
// 		} else if (m.count(n - 1) and m.count(n + 1)){
// 			//both greater and lesser are present
// 			int left = m[n - 1];
// 			int right = m[n + 1];

// 			int streak = left + 1 + right;

// 			//we update the leftmost and the rightmost elements with new streak
// 			m[n - left] = streak;
// 			m[n + right] = streak;
// 		} else if (m.count(n - 1) and !m.count(n + 1)){
// 			//1 2 3 [4]   7 8 9
// 			int length = m[n - 1];
// 			m[n - length] = length + 1;
// 			m[n] = length + 1;
// 		} else {
// 			int length = m[n + 1];
// 			m[n + length] = length + 1;
// 			m[n] = length + 1;
// 		}
// 	}

// 	for(auto p : m){
// 		largest = max(largest, p.second);
// 	}

// 	return largest;
// }

//more optimised O(N) space and time;

int findLargestSequence(int arr[], int n){
	unordered_set<int> s;
	for(int i = 0; i < n; i++){
		s.insert(arr[i]);
	}
	int maxStreak = 1;	
	for(int i = 0; i < n; i++){
		if (s.find(arr[i] - 1 ) == s.end()){
			//a[i] is the starting point of the new streak
			int streakLength = 1;
			int next = arr[i] + 1;
			while(s.find(next) != s.end()){
				next++;
				streakLength++; 
			}
			maxStreak = max(maxStreak, streakLength);
		}
	}

	return maxStreak;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << findLargestSequence(arr, n) << endl;
}