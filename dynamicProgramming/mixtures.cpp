// #include <bits/stdc++.h>
// #define ll long long
// #define F first
// #define S second
// #define pb push_back
// #define MOD 1e7
// using namespace std;

// long long arr[1000] = {0}; 
// long long dp[1000][1000] = {-1};

// long long sum(long long start, long long end){
// 	long long ans = 0;
// 	for(long long i = start; i <= end; i++){
// 		ans += arr[i];
// 		ans %= 100;
// 	}

// 	return ans;
// }

// long long minSmoke(ll start, ll end){
// 	if (start >= end){
// 		return 0;
// 	}

// 	if (dp[start][end] != -1){
// 		return dp[start][end];
// 	}

// 	dp[start][end] = INT_MAX;
// 	for (ll k = start; k < end; k++){
// 		dp[start][end] = min(dp[start][end], minSmoke(start, k) + minSmoke(k + 1, end) + (sum(start, k) * sum(k + 1, end)));
// 		// cout << (sum(start, k) * sum(k + 1, end))  << endl;
// 		// cout << minSmoke(start, k) + minSmoke(k + 1, end) << endl;
// 	}
// 	return dp[start][end];
// }

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// 	int n;
// 	cin >> n;
// 	for(ll i = 0;i < n; i++){
// 		cin >> arr[i];
// 	}

// 	cout << minSmoke(0, n - 1) << endl;
// 	return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll mod=1e9+7;
ll n;
ll arr[500];
ll dp[500][500];


ll sum2(ll i,ll j){
	ll ans=0;
	for(ll k=i;k<=j;k++)
	{
		ans+=arr[k];
		ans%=100;
	}
	return ans;
}

ll solve(ll i,ll j)
{
	if(i>=j)
	return 0;

	if(dp[i][j]!=-1)
	return dp[i][j];
	ll ans=LLONG_MAX;
	for(ll k=i;k<j;k++)
	{
		ans=min(ans,solve(i,k)+solve(k+1,j)+sum2(i,k)*sum2(k+1,j));

	}
	return dp[i][j]=ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fast		
	while(cin>>n){
		memset(dp,-1,sizeof(dp));
		for(ll i=0;i<n;i++)
		cin>>arr[i];

		cout<<solve(0,n - 1)<<endl;
	}

	return 0;
}	