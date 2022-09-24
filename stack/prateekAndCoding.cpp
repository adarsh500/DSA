#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	int n, type, val;
	cin >> n;
	while(n--){
		cin >> type;
		if (type == 2){
			cin >> val;
			s.push(val);
		} else {
			if (!s.empty()){
				cout << endl << s.top();
				s.pop();
			} else {
				cout << endl << "No Code";
			}
		}
	}

}