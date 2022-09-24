#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long int
using namespace std;

int modAdd(int a, int b){
    return ((a%MOD) + (b%MOD))%MOD;
}

int countSub(string s)
{
    map<char, int> Map;
 
    // Iterate from 0 to s.length()
    for(int i = 0; i < s.length(); i++)
    {
        Map[s[i]] = -1;
    }
      
    int allCount = 0;
    int levelCount = 0;
      
    // Iterate from 0 to s.length()
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
         
        // Check if i equal to 0
        if (i == 0)
        {
            allCount = 1;
            Map[c] = 1;
            levelCount = 1;
            continue;
        }
         
        // Replace levelCount withe
        // allCount + 1
        levelCount = modAdd(allCount, 1);
         
        // If map is less than 0
        if (Map[c] < 0) {
            allCount = modAdd(allCount, levelCount);
        } else {
            allCount = modAdd(allCount, levelCount - Map[c]);
        }
        Map[c] = levelCount;
    }
     
    // Return answer
    return modAdd(allCount, 1);
}

int32_t main(){
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		cout << countSub(s) << endl;
	}
	
}