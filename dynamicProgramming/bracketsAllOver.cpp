// Approach

//     It is quite obvious that we would only add opening brackets '(' to string A and only 
// closing brackets ')' to string B Since the number of open and close brackets must be equal,
 // we can never generate a valid string if n is odd. Count the total number of opening and 
// closing brackets required to balanced the string. The opening brackets will go in string A 
// and the closing brackets will go in string B. We start from pos = 0 and go till pos = n - m + 1. 
// At each instance we consider three possibilities.

//if closingBrackets have not been implemented yet (close==0) and count of open brackets that 
// we have implemented is more than required (open >= openBrackets) then, we implement the 
// closing brackets required for string B and raise a flag for the same by marking close=1 also, 
// change the open bracket count accordingly for this case if we have some open brackets then, 
// put a closing bracket to balance it and decrease open count to denote there is one less unbalanced 
// open bracket now add another opening bracket to the string so far. This bracket will be 
// initially unbalanced. We add the results obtained from the three possibilities. We store and 
// return this result. Continue the above process till pos < n-m+1. At pos == n-m+1, we must ensure 
// that all required opening and closing brackets have been implemented. We do so by checking the 
// status of out flag variable close i.e. check close==1. Also make sure there are no pending unbalanced 
// open brackets (open==0).



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int n, m;
ll dp[2222][2222][2];

int openingBrackets = 0, closeBrackets = 0;
int length = 0 ;

ll solve(int pos, int open, int close){
    if (pos == length) { 
        if(close > 0 && open == 0){
            return 1;
        }
        else {
            return 0;
        }
    }

    if (dp[pos][open][close] != -1){
        return dp[pos][open][close];
    }

    ll ans = 0;
    if (close == 0){
        if (open >= openingBrackets)
            ans = (ans + solve(pos + 1, open - (openingBrackets + closeBrackets), 1)) % MOD;
    }

    ans = (ans + solve(pos + 1, open +1, close)) % MOD;

    if(open)
        ans = (ans + solve(pos + 1, open - 1, close)) % MOD;

    dp[pos][open][close] = ans;

    return ans;
}
int main(){
    cin >> n >> m;
    length = n - m + 1;
    string s;
    cin >> s;
    if (n & 1){
        //If n is odd, string can never be balanced
        cout << 0;
        return 0;
    }

    closeBrackets = 0;
    for(int i=0;i<m;i++){
        if (s[i] == '(') {
            //We need a closing bracket to balance this opening bracket
            closeBrackets++;
        }
        else {
            //Encountered a ) , reduce a the no of closing brackets required
            closeBrackets--;
        }
        if (closeBrackets < 0) {
            //More closing brackets than opening brackets , increase the no of opening brackets for string A
            openingBrackets++;
            closeBrackets = 0;
        }
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, 0);

    return 0;
}