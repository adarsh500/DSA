#include <iostream>
#include <stack>
#define lli long long int
using namespace std;

lli computeMaxArea(lli height[1000000], lli n){
	stack<lli> s;
	lli maxArea = 0, area = 0, top;
	lli i;
	for (i = 0; i < n;){

		if (s.empty() || height[s.top()] <= height[i]){
			s.push(i++);
		} else {
			top = s.top();
			s.pop();
			if (s.empty()){
				area = height[top] * i;
				// cout << area << endl;
			} else {
				area = height[top] * (i - s.top() - 1);
				// cout << area << endl;
			}

			maxArea = max(area, maxArea);
		}
	}

	while(!s.empty()){
		top = s.top();
		s.pop();

		if (s.empty()){
			area = height[top] * i;
			// cout << area << endl;
		} else {
			area = height[top] * (i - s.top() - 1);
			// cout << area << endl;
		}
			maxArea = max(area, maxArea);
	}
	return maxArea;
}

int main(){
	lli n;
	cin >> n;
	lli height[1000000] = {0};
	for (lli i = 0; i < n; i++){
		cin >> height[i];
	}

	cout << computeMaxArea(height, n) << endl;
}