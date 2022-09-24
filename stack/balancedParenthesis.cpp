#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s){
	stack<char> st;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '('){
			st.push(s[i]);
		} 
		if (s[i] == ')'){
			if (!st.empty() && st.top() == '('){
				st.pop();
			}
		}
		if (s[i] == '['){
			st.push(s[i]);
		} 
		if (s[i] == ']'){
			if (!st.empty() && st.top() == '['){
				st.pop();
			}
		} 
		if (s[i] == '{'){
			st.push(s[i]);
		} 
		if (s[i] == '}'){
			if (!st.empty() && st.top() == '{'){
				st.pop();
			}
		}
	}
	return st.empty();
}

int main(){
	string s;
	cin >> s;

	if (isBalanced(s)){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}