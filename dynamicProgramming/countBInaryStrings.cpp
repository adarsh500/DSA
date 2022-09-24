// #include <iostream>
// #include <string>
// using namespace std;

// int numberOfBinaryStrings(int n, string result, int count){
// 	if (n == 1){
// 		count++;
// 		return 2;
// 	}

// 	int ans = 0;
// 	int len = result.length();
// 	if (result[len - 1] == '1'){
// 		cout << result << " prev is 1" << endl;
// 		return numberOfBinaryStrings(n - 1, result + "0", count);
// 	} 
// 		int option1 = numberOfBinaryStrings(n - 1, result + "0", count);
// 		int option2 = numberOfBinaryStrings(n - 1, result + "1", count);
// 		cout << result << " prev not 1" <<  endl;
// 		return option2 + option1;
// }


// //NOTE: This is a fibo series,
// int countStrings(int n, int lastDigit){
// 	if(n == 1){
// 		return 2;
// 	}

// 	if (lastDigit&1){
// 		return countStrings(n - 1, 0);
// 	}
// 		return countStrings(n - 1, 0) + countStrings(n - 1, 1);

// }

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// 	int t, n;
// 	cin >> t;
// 	while(t--){
// 		cin >> n;
// 		// cout << countStrings(n, ) << endl;
// 		cout << numberOfBinaryStrings(n, "", 0) << endl;
// 	}
// }

// EXPLANATION
// This problem can be solved using Dynamic Programming. Let a[i] be the number of binary strings 
// of length i which do not contain any two consecutive 1’s and which end in 0. Similarly, let 
// b[i] be the number of such strings which end in 1. We can append either 0 or 1 to a string 
// ending in 0, but we can only append 0 to a string ending in 1. This yields the recurrence 
// relation: a[i] = a[i - 1] + b[i - 1] b[i] = a[i - 1] The base cases of 
// above recurrence are a[1] = b[1] = 1. The total number of strings of length i is just a[i] + b[i].

// Time Complexity : O(
// N
// N).
#include <iostream> 
using namespace std; 

#define int long long 
int countStrings(int n) 
{ 
    int a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
} 

void solve(){
    int n;
    cin>>n;
    cout<<countStrings(n)<<endl;
}

signed main() 
{ 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0; 
}
// Approach 2
// C++ program to count all distinct binary strings // without two consecutive 1's

#include <iostream>
#define ll unsigned long long int
using namespace std;

ll countStrings(int n)
{
    ll a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = (ll)(a[i-1] + b[i-1]);
        b[i] = (ll)a[i-1];
    }
    return (ll)(a[n-1] + b[n-1]);
}


// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout << countStrings(n) << endl;
    }
    //cout << countStrings(3) << endl;
    return 0;
}

// other one
	
#include<iostream>
using namespace std;

long long int dp[91][2];
long long int count(long long int n,long long int s)
{
	if(n==1)
		return 1;
	
	if(dp[n][s]!=-1)
		return dp[n][s];

	if(s==0)
		dp[n][s]=count(n-1,1)+count(n-1,0);
	else
		dp[n][s]=count(n-1,0);

	return dp[n][s];
}

int main() {
	long long int t,n;
	cin>>t;
	
	while(t--)
	{
		for(long long int i=0;i<=90;i++){	
			for(long long int j=0;j<=2;j++){
				dp[i][j]=-1;
			}
		}
		cin>>n;
		long long int res=count(n,1)+count(n,0);
		cout<<res<<endl;
	}
	return 0;
}