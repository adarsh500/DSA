#include <bits/stdc++.h>

using namespace std;

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

const int N = 200005;

int numberOfBST(int n){
	int dp[n + 1];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++){
		dp[i] = 0;
		for(int j = 1; j <= i; j++){
			dp[i] += dp[j - 1] * dp[i - j];
			// bug(i, j, dp[j - 1] * dp[i - j]);
		}
	}

	return dp[n];
}

int numberOfBSTTD(int n){
	if (n == 0 || n == 1){
		return 1;
	} 
	if (n == 2){
		return 2;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += numberOfBSTTD(i - 1) * numberOfBSTTD(n - i);
		// bug(ans, i);
	}

	return ans;
}

void solve() {

	//the formula to solve this is  C(2n, n) / n + 1, where c is combination

	//variations of the same problem
	//1. unlabeled binary trees: (a binary trees with structure and no data)
		// soln: the same as BST
	//2. binary trees: we can permute between the number in n! ways so
	//	soln: n! X BST soln

	int n;
	cin >> n;

	//we have to find the number of BST that we can create from n nodes
	cout << numberOfBSTTD(n) << endl;
	cout << numberOfBST(n) << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
	// cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}
