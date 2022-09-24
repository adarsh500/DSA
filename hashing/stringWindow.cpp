#include <bits/stdc++.h>
using namespace std;

string stringWindow(string s, string p) {
	int strLen = s.length();
	int patLen = p.length();

	if (patLen > strLen) {
		return "No String";
	}

	int sfreq[256] = {0};
	int pfreq[256] = {0};

	for (int i = 0; i < patLen; i++) {
		pfreq[p[i]]++;
	}

	int count = 0, start = 0, minLen = INT_MAX, startIdx = -1;
	for (int i = 0; i < strLen; i++) {
		int ch = s[i];
		sfreq[ch]++;

		if (pfreq[ch] != 0 and sfreq[ch] <= pfreq[ch]) {
			count++;
		}

		if (count == patLen) {
			char temp = s[start];
			while (pfreq[temp] == 0 or sfreq[temp] > pfreq[temp]) {
				sfreq[temp]--;
				start++;
				temp = s[start];
			}

			int windowLen = i - start + 1;
			if (windowLen < minLen) {
				minLen = windowLen;
				startIdx = start;
			}
		}
	}
	if (startIdx == -1) {
		return "No String";
	}

	return s.substr(startIdx, minLen);
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	string s1, s2, ans;
	getline(cin, s1);
	getline(cin, s2);
	// cout <<s1 << endl;

	cout << stringWindow(s1, s2) << endl;
}