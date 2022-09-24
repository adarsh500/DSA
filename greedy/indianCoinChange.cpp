#include <bits/stdc++.h>
using namespace std;

int makeChange(int *coins, int n, int money){
	//how to find the index of the biggest coin less than money

	int noOfCoins = 0;
	while(money > 0){
		//upper bound will return index of element just greater than it
		int idx = upper_bound(coins, coins + n, money) - 1 - coins;

		//this will give us the address, to get the index
		//subtract from base address
		cout << coins[idx] << " + ";
		money = money - coins[idx];
		noOfCoins++;
	}

	return noOfCoins;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int money;
	cin >> money;

	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int t = sizeof(coins) / sizeof(int);
	makeChange(coins, t, money);


	return 0;
}