#include <bits/stdc++.h>
using namespace std;

//you are given an array of integers, you have to find out if a subarray has a
//sum that is equal to 0

bool checkSum(int arr[], n){
	unordered_set<int> s;

	int pre = 0;
	for(int i = 0; i < n; i++){
		//computing prefix sum
		pre += arr[i];

		//we check if pre = 0 or if pre is already existing in the set
		if (pre == 0 or s.find(pre) != s.end()){
			return true;
		}
		//if pre doesn't exist, then we add it to the set
		s.insert(pre);
	}

	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	

}