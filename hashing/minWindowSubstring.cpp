/*
	problem: find the smallest window in a string that contains all the charecters 
	of another string
	string : hellloee0 world
	pattern: eelo

	APPROACH	
	1. if the window len > string length, then return false
	2. make a pattern freqMap, that will store the freq of letters in pattern 
	3. expand the window towards the right until you get the widow that satis
	   fies the requirements. Once you get it, then you contract the window 
	   from the left. (we will either be removing out unnecessary charecters or
	   decreasing the freq of excess charecters).
	4. every time you find a window, you will update the window size
*/

#include <bits/stdc++.h>
using namespace std;

string findWindow(string s, string pattern){
	int stringLen = s.length();
	int patternLen = pattern.length();

	//1. Corner Case
	if (patternLen > stringLen){
		return "none";
	}

	//freq maps
	int stringFreq[256] = {0};
	int patternFreq[256] = {0};

	for(int i = 0; i < patternLen; i++){
		//creating a freq map for pattern
		char ch = pattern[i];
		patternFreq[ch]++;
	} 

	// 3. Sliding window(expansion + contraction + update
	// the min length window);
	int count = 0, start = 0, minLen = INT_MAX, startIdx = 0;

	for(int i = 0; i < stringLen; i++){
		//creating a freq map for string
		char ch = s[i];
		stringFreq[ch]++;

		if (patternFreq[ch] != 0 and stringFreq[ch] <= patternFreq[ch]){
			//so basically we are checking if the char in string
			//is a member of the pattern freq or not. And if the freq of 
			//ch in string is < freq of ch in pattern. Then we increase
			//the count;
			count++;
		}

		//if all the charecters match
		if (count == patternLen){
			//start shrinking the window

			char temp = s[start];
			//loop to remove all unwanted charecters
			while(patternFreq[temp] == 0 or stringFreq[temp] > patternFreq[temp]){
				stringFreq[temp]--;
				start++;
				temp = s[start];
			}

			int windowLen = i - start + 1;
			if (windowLen < minLen){
				minLen = windowLen;
				startIdx = start;				
			}
		}
	}
	if (startIdx == -1){
		return "none";
	}

	string ans = s.substr(startIdx, minLen);
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	string s = "heelleeoaeo world";
	string p = "eelo";

	cout << findWindow(s, p) << endl;
}