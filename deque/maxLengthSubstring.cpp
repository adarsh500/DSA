#include <iostream>
#include <deque>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int n = s.length();
	int currentLength = 1, maxLength = 1;
	//visited basically stores the index of the last encouter of ith
	//element in s;
	int visited[256] = { -1};


	//we have visited the first element of s
	visited[s[0]] = 0;

	for (int i = 1; i < n; i++) {
		int lastOccurence = visited[s[i]];

		//case 1: expansion. This means that the element that we encountered
		//is not a part of the current window, so we add it.
		if (lastOccurence == -1 || lastOccurence < i - currentLength) {
			currentLength += 1;
			maxLength = max(maxLength, currentLength);
		}
		/* case2: expansion + contraction. this means that we have encountered
		the element before and we are removing elements in the window till the
		prev occurence of the element. And then we are including the new occurence
		of the element
		eg:- (abcde)c existing window
			 abc(dec) new window
		*/
		else {
			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
			currentLength = i - lastOccurence;
		}
		visited[s[i]] = i;
	}
	if (currentLength > maxLength) {
		maxLength = currentLength;
	}
	cout << maxLength << endl;
	return 0;
}