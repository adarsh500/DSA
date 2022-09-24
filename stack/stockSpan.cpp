#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int prices[], int span[], int n){
	stack<int> s;
	s.push(0);

	//span of 0th element is always 1 by default;
	span[0] = 1;

	for(int i = 1; i < n; i++){

		int currentPrice = prices[i];
		while(!s.empty() and prices[s.top()] <= currentPrice){
			s.pop();
		}
		if (!s.empty()){
			int prevHighest = s.top();
			span[i] = i - prevHighest;
		} else {
			//else span = no. of days till now
			span[i] = i + 1;
		}
		s.push(i);
	}
}

int  main(){
	int n;
	cin >> n;
	int prices[n], span[100000] = {0};
	for (int i = 0; i < n; i++){	
		cin >> prices[i];
	}

	stockSpan(prices, span, n);

	for (int i = 0; i < n; i++){
		cout << span[i] << " ";
	}
	cout << "END" << endl;
}