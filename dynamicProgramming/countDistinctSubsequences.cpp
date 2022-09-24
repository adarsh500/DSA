// Consider the string S=“ABCB”

// Let DP[i+1] = No. of distinct subsequences possible from S[0…i]

// where DP[0] = 1, for empty subsequence { }

// So, for the string "ABCDEFG"

// For i=0;

// Possible Subsequences: { },A

// DP[1] = 2;

// For i=1:

// Possible Subsequences: { },A,B,AB

// DP[2] = 4

// for i=2:

// Possible Subsequences: { },A,B,AB,C,AC,BC,ABC

// DP[3] = 8

// As we can observe,

// DP[i] = DP[i-1]*2;

// But till now, all characters were distinct.

// Consider the next chracter ‘B’(Getting repeated),

// Possible Subsequences:

// { },A,B,AB,C,AC,BC,ABC,B,AB,BB,ABB,CB,ACB,BCB,ABCB

// DP[4] = 16

// But here as we can see, (B,AB) are repeating (hence the subsequences are not distinct), Which we had obtained earlier by appending B at the end to ({ },A).

// Hence the No. of repeating subsequences = DP[1] in this case.

// Where, 1 is nothing but the previous occurence of the characer B. And we need to subtract the no. of repeating subsequences to get the result.

// In this case,

// DP[4] = 16 - 2 = 14

// Hence DP[i] = DP[i-1]*2 - DP[Immediate previous occurence of character S[i-1]], if S[i-1] has occurred before.

// Final Algo. obtained:

// DP[0] = 1;

// For i=0 to length(S)-1:

// DP[i+1] = DP[i]*2;

// if(previous[S[i]]>=0)

// DP[i+1] = DP[i+1] - DP[previous[S[i]]];

// previous[S[i]] = i;

// Expected Output: DP[length(S)]

// Note:

// Previous[i] = Index of prev. occurence of i. If there is no previous occurence of i, then I have initialized it to some negative value.


/*input
1 
ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ 
*/

#include <bits/stdc++.h>
using namespace std;

#define boost  ios_base::sync_with_stdio(false);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define f(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define rf(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define ms(a,b) memset((a),(b),sizeof(a))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

#define abs(x) ((x<0)?(-(x)):(x))
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN

//typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}

/*..................................................................................................................................*/
char s[MAX];
int previous_count[200],hash[200];
ll dp[MAX],sum[MAX];
int main() 
{
    boost;cin.tie(0);cout.tie(0);
   // freopen("input.txt","r",stdin);
    int n,t;cin>>t;
    while(t--)
    {
        cin>>s;
        ms(previous_count,-1);
        n=strlen(s);
        ms(dp,0);
        dp[0]=1;
        previous_count[s[0]]=0;
        f(i,1,n)
        {
          dp[i]=(2*dp[i-1])%mod;
          if(previous_count[s[i-1]]!=-1)
            dp[i]=(dp[i]-dp[previous_count[s[i-1]]-1]+mod)%mod;
          previous_count[s[i-1]]=i;
        }
       // freopen("output.txt","a",stdout);
        cout<<dp[n]<<endl;
    }
   return 0;
}