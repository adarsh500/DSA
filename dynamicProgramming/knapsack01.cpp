// Here the state of any subproblem can be defined by using 2 variables i.e id and remW where id is the index 
// of the current item to be considered and remW is the remaining weight left in the knapsack.
// knapsack(id, 0) = 0 // if remaining weight is 0, we can’t take anything .
// knapsack(n, remW) = 0 // if id = n we have considered all the items .
// if(W[id] > remW), we have no choice but to ignore this item .
// if(W[id]≤ remW), we have two choices either we can ignore this item or include it .
// Value1 = knapsack(id+1, remW) // Not including .
// Value2 = knapsack(id+1, remW - W[id]) // Included .
// knapsack(id, remW) = max(Value1, Value2 + V[id]) .
// Example: n = 3, V = {60,100,120, 80}, W = {100,40,60,120}, S = 120.
// Here we can easily see some overlapping subproblems. After including the 0th item and ignoring 
// 1st and 2nd item we arrive at state knapsack(3, 20) i.e. at the third item with 20 units weight left. 
// Also if we ignore the 0th item and include both the 1st and the 2nd item we arrive at the same state 
// i.e. knapsack(3, 20). So here we got an overlapping subproblem. The total number of possible states 
// for this knapsack problem can be O(nS) where n is the number of items and S is the maximum weight possible.


// int knapSack(int W, int wt[], int val[], int n) 
// { 
//    int i, w; 
//    int K[n+1][W+1]; 
//    for (i = 0; i <= n; i++) 
//    { 
//        for (w = 0; w <= W; w++) 
//        { 
//            if (i==0 || w==0) 
//                K[i][w] = 0; 
//            else if (wt[i-1] <= w) 
//                  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
//            else
//                  K[i][w] = K[i-1][w]; 
//        } 
//    } 

//    return K[n][W]; 
// }


#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[1005][1005];

//Recursive Approach
ll knapsack(ll n, ll w, ll *weights, ll *prices)
{
    //Base case
    if (n == 0 || w == 0) {
        return 0;
    }

    if (dp[n][w] != -1) {
        return dp[n][w];
    }

    ll include = 0;
    ll exclude = 0;

    if (weights[n - 1] <= w)
    {
        //Include the current index element
        include = prices[n - 1] + knapsack(n - 1, w - weights[n - 1], weights, prices);
    }

    //Exclude the current element
    exclude = knapsack(n - 1, w, weights, prices);

    dp[n][w] = max(include, exclude);

    return dp[n][w];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ll n, w;
    cin >> n >> w;
    ll weights[1005] = {0};
    ll prices[1005] = {0};

    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++){
        cin >> prices[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, w, weights, prices);

    return 0;
}