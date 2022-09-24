#include <iostream>
using namespace std;

int profit(int *weight, int *prices, int n, int c){
	if (n == 0 || c == 0){
		return 0;
	}

	int include, exclude = 0;

	if (weight[n - 1] <= c){
		include = prices[n - 1] + profit(weight, prices, n - 1, c - weight[n - 1]);	
	}
	exclude = profit(weight, prices, n - 1, c);

	int ans = max(include, exclude);
	return ans;
}

int main(){
	int weight[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};

	int n = 4, c = 7;

	cout << profit(weight, prices, n, c) << endl;
}