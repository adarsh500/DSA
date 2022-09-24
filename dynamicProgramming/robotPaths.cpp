#include <bits/stdc++.h>

using namespace std;
int dp[1000][1000];

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 1000000007;

int countPaths(int m, int n){

	for(int j = 0; j < n; j++){
		if (dp[0][j] == -1){
			break;
		}
		dp[0][j] =1;
	}

	for(int j = 0;j < m; j++){
		if (dp[j][0] == -1){
			break;
		}
		dp[j][0] = 1;
	}

	for(int i = 1;i < m; i++){
		for(int j = 1;j < n; j++){
			if(dp[i][j] == -1){
				continue;
			}
			dp[i][j] = 0;

			if (dp[i][j - 1] != -1){
				dp[i][j] = dp[i][j - 1] % N;
			}

			if (dp[i - 1][j] != -1){
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % N;
			}
		}

		
	}

	// for(int i = 0; i )
	if (dp[m - 1][n - 1] == -1){
		return 0;
	}
	return dp[m - 1][n - 1];
}

void solve() {
	memset(dp, 0, sizeof dp);
	int m, n, p;
	cin >> m >> n >> p;
	for(int i = 0; i < p; i++){
		int a, b;
		cin >> a >> b;
		dp[a - 1][b - 1] = -1;
	}

	cout << countPaths(m, n) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
	cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}