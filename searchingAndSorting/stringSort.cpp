#include <iostream>
using namespace std;

bool isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
 //         For current index i, check for
 // pattern match 
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
            return true;
    }
    return false;
}

// bool compare(string s1, string s2){
// 	// if(isSubstring(s1, s2)){
// 	// 	return s2.length() < s1.length();
// 	// }
// 	return s1 < s2;
// }

int main(){
	int n;
	cin >> n;

	string arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
		if(isSubstring(arr[i], arr[i + 1])){
			cout << "true";		
		} else {
			cout << "false";
		}

	// if(isSubstring(s1, s2)){
	// 	return s2.length() < s1.length();
	// }


	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}